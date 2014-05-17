from pyqtgraph.Qt import QtCore, QtGui
import pyqtgraph as pg
import pyqtgraph.opengl as gl
import scipy.ndimage as ndi
from matplotlib.mlab import griddata
import numpy as np
import string
import sys
import os
import serial
from struct import unpack

# Plot refresh rate and update counter
PACKETS_UNTIL_UPDATE = 4
UPDATE_COUNTER = 0
X = []
YRSS = []
YCORR = []

# Get the channel to monitor from the provided arguments
if len(sys.argv) == 1:
    print("Provide a channel as argument.")
    os._exit(1)

channel = int(sys.argv[1])

# Create the plot window
pg.setConfigOption('background', 'w')
pg.setConfigOption('foreground', 'k')
plt = pg.plot()
plt.plotItem.setYRange(-40, 120)

# Update the plot with the new data
def update():
    x, yRssi, yCorr = parse(collect())
    plt.plotItem.setXRange(UPDATE_COUNTER * PACKETS_UNTIL_UPDATE - 100, UPDATE_COUNTER * PACKETS_UNTIL_UPDATE)
    plt.plot(x, yRssi, pen=pg.mkPen('r', width=2), antialias=True, name='RSS', clear=True)
    plt.plot(x, yCorr, pen=pg.mkPen('b', width=2), antialias=True, name='Correlation value')
    
# Collect measurements from the serial port (USB dongle)
def collect():
    # Open the serial connection
    ser = serial.Serial("/dev/ttyACM0", 38400);
    beef = '\xef' + '\xbe'

    # Clear the buffers and counters
    ser.flushInput()
    buffer = ''
    packets = ''
    packetCount = 0

    # Listen for multi-Spin packets until we have enough of them
    listening = True;
    while listening:
        buffer = buffer + ser.read(ser.inWaiting())
        if beef in buffer:
            lines = buffer.split(beef)
            binaryPacket = lines[-2]
            buffer = lines[-1]
            spinPacket = unpack('<Hb' + (len(binaryPacket) - 4) * 'b' + 'b', binaryPacket)
            splitPacket = string.split(str(spinPacket).translate(None, '\n()'), ', ')

            if int(splitPacket[-1]) == channel and int(splitPacket[3]) != 127:
                packetCount = packetCount + 1
                packets = packets + str(spinPacket) + '\n'

                if packetCount >= PACKETS_UNTIL_UPDATE:
                    listening = False;

    return packets

# Parse measurements in the buffer
def parse(packets):
    global UPDATE_COUNTER, PACKETS_UNTIL_UPDATE, X, YRSS, YCORR
    splitPackets = string.split(packets, '\n')
    
    for index, line in enumerate(splitPackets):
        # Skip empty lines
        if line == '':
            continue;

        # Get single packet strings and clean them up
        line = line.translate(None, '\n()')
        splitLine = string.split(line, ', ')
        
        X.append(UPDATE_COUNTER * PACKETS_UNTIL_UPDATE + index)
        YRSS.append(int(splitLine[3]))
        YCORR.append(int(splitLine[5]))

    UPDATE_COUNTER = UPDATE_COUNTER + 1
    return X, YRSS, YCORR

# Set the timer to dynamically update the plot
timer = QtCore.QTimer()
timer.timeout.connect(update)
timer.start(30)

# Start a Qt event loop, except when running in interactive mode
if __name__ == '__main__':
    if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
        QtGui.QApplication.instance().exec_()

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

# Plot refresh rate
PACKETS_UNTIL_UPDATE = 80

# Get the channel to monitor from the provided arguments
if len(sys.argv) == 1:
    print("Provide a channel as argument.")
    os._exit(1)

channel = int(sys.argv[1])

# Create a GL View widget to display the plot
app = QtGui.QApplication([])
w = gl.GLViewWidget()
w.opts['distance'] = 45
w.showMaximized()
w.setWindowTitle('RSSI plot on channel ' + str(channel))

# Update the plot with the new data
def update():
    numNodes, x, y, z = parse(collect())
    xi = yi = np.linspace(1, numNodes)
    X, Y = np.meshgrid(xi, yi)
    Z = griddata(x, y, z, xi, yi)
    p.setData(z=Z)

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
            packetCount = packetCount + 1
            packets = packets + str(spinPacket) + '\n'

            if packetCount >= PACKETS_UNTIL_UPDATE:
                listening = False;

    return packets

# Parse measurements in the buffer
def parse(packets):
    numNodes = 0
    temp = {}
    splitPackets = string.split(packets, '\n')
    
    for line in splitPackets:
        # Skip empty lines
        if line == '':
            continue;

        # Get single packet strings and clean them up
        line = line.translate(None, '\n()')
        splitLine = string.split(line, ', ')
        
        # Use only those packets with the channel number equal to the monitored channel number
        if int(splitLine[-1]) == channel:
            length = len(splitLine)
            nodeId = int(splitLine[1])
            numNodes = ((length - 3) / 2) # Number of RSSI values in the string: ignores packet ID, current node ID, channel and correlation values
            temp[nodeId] = temp.get(nodeId, {})
            for x in range(1, numNodes):
                # Skip 127 values because they mess up the average
                if int(splitLine[1 + x]) == 127:
                    continue;
                
                # Create the statistics: get the RSSI values
                temp[nodeId][x] = temp[nodeId].get(x, {})
                if not 'rssi' in temp[nodeId][x]:
                    temp[nodeId][x]['rssi'] = int(splitLine[1 + x])
                else:
                    temp[nodeId][x]['rssi'] += int(splitLine[1 + x])

                # Update a counter to be able to compute the average RSSI value later on
                if not 'count' in temp[nodeId][x]:
                    temp[nodeId][x]['count'] = 1
                else:
                    temp[nodeId][x]['count'] += 1
        else:
            continue;

    # Format the data for the axes (average RSSI)
    data = []
    for k, v in temp.iteritems():
        for k2, v2 in temp[k].iteritems():
            data.append([k, k2, (temp[k][k2]['rssi'] / temp[k][k2]['count'])])
    data = np.array(data)
    return numNodes, data[:,0], data[:,1], data[:,2]

# Create the grids
gx = gl.GLGridItem()
gx.rotate(90, 0, 1, 0)
gx.translate(-10, 0, 0)
w.addItem(gx)
gy = gl.GLGridItem()
gy.rotate(90, 1, 0, 0)
gy.translate(0, -10, 0)
w.addItem(gy)
gz = gl.GLGridItem()
gz.translate(0, 0, -10)
w.addItem(gz)

# Set other surface/space properties and make the plot
numNodes,x,y,z = parse(collect())
xi = yi = np.linspace(1, numNodes)
X, Y = np.meshgrid(xi, yi)
Z = griddata(x, y, z, xi, yi)
p = gl.GLSurfacePlotItem(z = Z, shader = 'shaded', color = (0.9, 0.25, 0.25, 1))
p.scale(1./3., 1./3., 1./2.)
p.translate(-10, -10, 10)
w.addItem(p)

# Set the timer to dynamically update the plot
timer = QtCore.QTimer()
timer.timeout.connect(update)
timer.start(50)

# Start a Qt event loop, except when running in interactive mode
if __name__ == '__main__':
    if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
        QtGui.QApplication.instance().exec_()

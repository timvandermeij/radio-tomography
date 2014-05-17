import os
import serial
import string
from struct import unpack
import sys
import time

class Packet:
    def __init__(self):
        self.fromNode = 0
        self.toNode = 0
        self.rssi = 0
        self.corr = 0
        self.channel = 0

    def __str__(self):
        return (str(self.fromNode) + ' | ' +
                str(self.toNode) + ' | ' +
                str(self.rssi) + ' | ' +
                str(self.corr) + ' | ' +
                str(self.channel))

class Sniffer:
    def __init__(self):
        if not os.path.exists('/dev/ttyACM0'):
            print('USB dongle not found. Aborting...')
            os._exit(1);
        self.serialConnection = serial.Serial('/dev/ttyACM0', 38400)
        self.serialConnection.flushInput()
        self.packets = []
    
    # Collect packets from the serial connection for a fixed time
    def start(self, seconds):
        stopTime = time.time() + seconds # When to stop sniffing
        buffer = ''
        fieldsToIgnore = 3 # Channel number, node number and packet counter
        beef = '\xef' + '\xbe' # End of packet marker
        while time.time() < stopTime:
            buffer += self.serialConnection.read(self.serialConnection.inWaiting())
            while beef in buffer:
                lines = buffer.split(beef, 1)
                binaryPacket = lines[-2]
                buffer = lines[-1]
                binaryPacket = str(unpack('<Hb' + (len(binaryPacket) - 4) * 'b' + 'b', binaryPacket))
                binaryPacket = string.split(binaryPacket.translate(None, '\n()'), ', ')
                numNodes = (len(binaryPacket) - fieldsToIgnore) / 2 # Because of RSSI and CORR arrays
                rssiArray = binaryPacket[2 : (2 + numNodes)]
                corrArray = binaryPacket[(2 + numNodes) : (2 + (numNodes * 2))]
                for index in range(1, numNodes + 1):
                    # Create a packet object for each measured link
                    packet = Packet()
                    packet.fromNode = int(binaryPacket[1])
                    packet.toNode = index
                    packet.rssi = int(rssiArray[index - 1])
                    packet.corr = int(corrArray[index - 1])
                    packet.channel = int(binaryPacket[-1])
                    self.packets.append(packet)

    # Close the serial connection
    def stop(self):
        self.serialConnection.close()

    # Returns all collected packets
    def getPackets(self):
        return self.packets

class Filter:
    def __init__(self, packets):
        self.packets = packets

    # Filter out packets where key value does not equal the given value 
    def where(self, key, value):
        buffer = []
        for packet in self.packets:
            if getattr(packet, key) == value:
                buffer.append(packet)
        self.packets = buffer
        return self.packets

class Export:
    def __init__(self, packets):
        self.packets = packets

    # Write a text file with all formatted packets
    def txt(self, fileName):
        file = open(fileName, 'w')
        for packet in self.packets:
            file.write(packet.__str__() + '\n')
        file.close()

    # Write a LaTeX file with the pgfplots plot of the data type
    def tex(self, fileName, type, channels):
        colors = {
            '11': 'red',
            '16': 'blue',
            '21': 'purple',
            '26': 'orange'
        }

        file = open(fileName, 'w')

        # Write the header of the file
        file.write('\documentclass{article}' + '\n\n')
        file.write('\\usepackage{pgfplots}' + '\n\n')
        file.write('\\begin{document}' + '\n\n')
        file.write('\\begin{tikzpicture}' + '\n')

        if type == 'rssi':
            label = 'RSSI'
            yMin = '-50'
            yMax = '-20'
        else:
            label = 'Correlation value'
            yMin = '80'
            yMax = '110'

        file.write('\t' + '\\begin{axis}[width=\\textwidth,' + 
                                        'height=0.85\\textwidth,' + 
                                        'xlabel=Measurement,' + 
                                        'ylabel=' + label + ',' +
                                        'ymin=' + yMin + ',' +
                                        'ymax=' + yMax + ',' +
                                        'legend style={at={(1,0)},anchor=south east,font=\scriptsize}]' + '\n')

        # Write the actual plot command including measurements for each channel
        for channel in channels:
            # Get all packets for this channel
            filter = Filter(self.packets)
            channelPackets = filter.where('channel', int(channel))

            # Write the plot command for the current channel
            file.write('\t\t' + '\\addplot[color=' + colors[channel] + ', thick] coordinates {' + '\n')
            for index, packet in list(enumerate(channelPackets)):
                file.write('\t\t\t' + '(' + str(index) + ', ' + str(getattr(packet, type)) + ')' + '\n')
            file.write('\t\t' + '};' + '\n')

        # Write the footer of the file
        file.write('\t\t' + '\legend{Channel ' + ", Channel ".join(channels) + '}' + '\n')
        file.write('\t' + '\end{axis}' + '\n')
        file.write('\end{tikzpicture}' + '\n\n')
        file.write('\end{document}')
        
        file.close()

def main(argv):
    # Get the channels
    if len(argv) == 0:
        print('Provide the used channels as arguments')
        os._exit(1)
    channels = argv;

    # Get packets for ten seconds
    sniffer = Sniffer()
    sniffer.start(10)
    sniffer.stop()
    packets = sniffer.getPackets()

    # Only keep packets from node 1 to node 2
    filter = Filter(packets)
    packets = filter.where('fromNode', 1)
    packets = filter.where('toNode', 2)
    
    # Write the results to a text file and create two LaTeX plots
    export = Export(packets)
    export.txt('measurements.txt')
    export.tex('plot_rssi.tex', 'rssi', channels)
    export.tex('plot_corr.tex', 'corr', channels)

if __name__ == "__main__":
    main(sys.argv[1:])

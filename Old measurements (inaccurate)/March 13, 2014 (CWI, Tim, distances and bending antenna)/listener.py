import serial
from struct import unpack

MAX_NUM_NODES = 4
packetSize = 4 + MAX_NUM_NODES + 2 # in bytes
ser = serial.Serial("/dev/ttyACM0", 38400);
beef = '\xef' + '\xbe'

# Clear the buffer
ser.flushInput()
buffer = ''

# Keep on listening for multi-Spin packets
while True:
    buffer = buffer + ser.read(ser.inWaiting())
    if beef in buffer:
        lines = buffer.split(beef)
        binaryPacket = lines[-2]
        buffer = lines[-1]
        spinPacket = unpack('<Hb' + (len(binaryPacket) - 4) * 'b' + 'b', binaryPacket)
        print(spinPacket)


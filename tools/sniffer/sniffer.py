import serial
from struct import unpack

# Establish a serial connection and clear the buffer
ser = serial.Serial("/dev/ttyACM0", 38400);
ser.flushInput()
beef = '\xef' + '\xbe'
buffer = ''

# Keep on listening for multi-Spin packets
while True:
    buffer = buffer + ser.read(ser.inWaiting())
    if beef in buffer:
        lines = buffer.split(beef, 1)
        binaryPacket = lines[-2]
        buffer = lines[-1]
        spinPacket = unpack('<Hb' + (len(binaryPacket) - 4) * 'b' + 'b', binaryPacket)
        print(str(spinPacket).replace(', 0', '')) # Remove zeros from the output

import serial
import scipy as sp
import scipy.sparse
import scipy.sparse.linalg
import numpy as np
from struct import unpack
import weights
import time

# open connection to USB dongle
ser = serial.Serial("/dev/ttyACM0", 38400);

# Clear the buffer
ser.flushInput()
ser.flushOutput()

# global buffer of USB dongle
buffer = ''


def readPacket():
    global buffer
    beef = '\xef' + '\xbe'
    while True:
        buffer = buffer + ser.read(ser.inWaiting())
        if beef in buffer:
            lines = buffer.split(beef)
            binaryPacket = lines[-2]
            buffer = lines[-1]
            spinArray = unpack('<Hb' + (len(binaryPacket) - 4) * 'b' + 'b', binaryPacket)
            spinPacket = dict()
            spinPacket['packetCount'] = spinArray[0]
            spinPacket['nodeid'] = spinArray[1]
            spinPacket['rssi'] = spinArray[2:-1]
            spinPacket['channel'] = spinArray[-1]
            return spinPacket
            
def getNumNodes():
    spinPacket = readPacket()
    return len(spinPacket['rssi'])

def getSweep(numNodes):
    node_idx = 1
    out = []
    while node_idx <= numNodes:
        packet = readPacket()
        if packet['nodeid'] != node_idx:
            node_idx = 1
            out = []
        else:
            out.append(packet)
            node_idx += 1
    return out

def sweep2vec(sweep):
    numNodes = len(sweep)
    vec = np.array([])
    for packet in sweep:
        vec = np.append(vec, packet['rssi'])
    return vec

nodes = [
        [0,0],
        [0,1],
        [1,1],
        [1,0]]
#nodes = [       
#        [0,0],
#        [0,3],
#        [0,6],
#        [0,9],
#        [3,9],
#        [6,9],
#        [9,9],
#        [9,6],
#        [9,3],
#        [9,0],
#        [6,0],
#        [3,0]]

resX = 64
resY = 64
_lambda = 1

W  = sp.sparse.csc_matrix(weights.createWeights(nodes, resX, resY, _lambda))
Wt = np.transpose(W)

u, s, vt = sp.sparse.linalg.svds(W,15)
print s
#print u.shape
#print s.shape
#print vt.shape

#rs = np.reciprocal(s)
#nv = np.dot(np.transpose(vt),np.diag(rs))
#nnv = np.dot(nv,np.transpose(u))

Winv = np.dot(np.dot(np.transpose(vt),np.diag(np.reciprocal(s))),np.transpose(u))

numNodes = getNumNodes()

print 'Starting initalization...'

# initialization
t1 = time.time()
nMeasurements = 0.0
while True:
    sweep = getSweep(numNodes)
    p_mean = sweep2vec(sweep)
    p_mean += p_mean
    nMeasurements += 1.0
    # wait 10 seconds
    if time.time()-t1 > 10:
        break

p_mean /= nMeasurements

def svds_recon(p):
    return np.dot(Winv,p)

print 'Realtime reconstruction'
while True:
    sweep = getSweep(numNodes)
    p = sweep2vec(sweep)
    p -= p_mean
    x = np.dot(Winv,p)
    #print np.reshape((x < -0.8).astype(int),(8,8))
    print np.reshape(x, (8,8))
    for i in range(0,24):
        print ''


import os
import re
from subprocess import call
import sys

# Get the number of nodes
if len(sys.argv) == 1:
    print("Provide the number of nodes as argument")
    os._exit(1)

numNodes = int(sys.argv[1])
nodeId = 1
os.chdir('../software/rf-node')
call(['make', 'clean'])
os.chdir('../')

while nodeId <= numNodes:
    lines = []
    
    # Find and replace the THIS_NODE_ID line
    file = open('../libraries/multi-spin-3.0/rf-node/main.c')
    for line in file:
        found = re.search('#define THIS_NODE_ID (\d+)', line)
        if found:
            lines.append('#define THIS_NODE_ID ' + str(nodeId) + '\n')
        else:
            lines.append(line)
    file.close()

    # Write the file with updated THIS_NODE_ID
    file = open('../libraries/multi-spin-3.0/rf-node/main.c', 'w')
    for line in lines:
        file.write(line)
    file.close()

    # Compile the RF node and save the file as rf-node-(nodeId).hex
    os.chdir('rf-node')
    call(['make'])
    os.rename('rf-node.hex', 'rf-node-' + str(nodeId) + '.hex')
    os.chdir('../')
    nodeId += 1

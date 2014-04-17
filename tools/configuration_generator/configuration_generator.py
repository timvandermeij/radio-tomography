import shutil
import subprocess
import os, sys, stat
import re

# Constants
CC_TOOL = "./cc-tool"
CONFIGURATION_FILE = "configuration.h"

# Extracts the MAC address from the cc-tool output
def getMacAddress():
    # Run cc-tool
    process = subprocess.Popen([CC_TOOL, '-a'], stdout=subprocess.PIPE)
    result = process.communicate()
    if "denied" in result[0]:
        print("Error: this script is not run with the right permissions. Aborting...")
        os._exit(1)

    # Parse cc-tool's output and append the MAC address in the correct form to the list
    mac = re.findall('(.*?)primary: (.*?),', result[0])
    mac = mac[0][1].split(":")
    macAddresses.append("{ " + 
                            "0x" + mac[6] + ", " +
                            "0x" + mac[7] + ", " +
                            "0x" + mac[4] + ", " +
                            "0x" + mac[5] + ", " +
                            "0x" + mac[2] + ", " +
                            "0x" + mac[3] + ", " +
                            "0x" + mac[0] + ", " +
                            "0x" + mac[1] +
                        " }")

# Get the number of input nodes and loop to get all MAC addresses
numNodes = int(raw_input("Enter the number of nodes in the sensor network: "))
macAddresses = []
for i in range(0, numNodes):
    raw_input("Connect node " + str(i + 1) + " to the SmartRF board and press Enter...")
    getMacAddress()

# Copy the configuration file template
shutil.copy(CONFIGURATION_FILE + ".dist", CONFIGURATION_FILE)

# Read the configuration file into a variable
with open(CONFIGURATION_FILE, "r") as configFile:
    configuration = configFile.read()

# Replaces the variables in the configuration file with their content
configuration = configuration.replace("#numNodes#", str(numNodes))
configuration = configuration.replace("#macAddresses#", ",\n    ".join(macAddresses))

# Write the full configuration file
configFile = open(CONFIGURATION_FILE, 'w')
configFile.write(configuration)
configFile.close()
os.chmod(CONFIGURATION_FILE, stat.S_IRWXO)

print("Configuration file 'configuration.h' has been written")

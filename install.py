import os
import shutil
import urllib2
import zipfile

# Constants (sources and folders)
MULTI_SPIN_URL = 'https://sites.google.com/site/boccamaurizio/multi-Spin_v2.0.zip'
CC_USB_FIRMWARE_URL = 'http://www.ti.com/lit/sw/swrc088c/swrc088c.zip'
MULTI_SPIN_FOLDER = 'multi-spin-2.0'
CC_USB_FIRMWARE_FOLDER= 'cc-usb-firmware'
LISTEN_NODE_FOLDER = 'listen-node-project'
RF_NODE_FOLDER = 'rf-node-project'
PATCHES_FOLDER = 'patches'
LIBRARIES_FOLDER = 'libraries'
PROJECTS_FOLDER = 'projects'
DOWNLOADS = [MULTI_SPIN_URL, CC_USB_FIRMWARE_URL]
LIBRARIES = [MULTI_SPIN_FOLDER, CC_USB_FIRMWARE_FOLDER]
PROJECTS = [LISTEN_NODE_FOLDER, RF_NODE_FOLDER]

# Paths
installation_path = raw_input('Enter the installation path: ')
libraries_path = os.path.join(installation_path, LIBRARIES_FOLDER)
multi_spin_path = os.path.join(libraries_path, MULTI_SPIN_FOLDER)
cc_usb_firmware_path = os.path.join(libraries_path, CC_USB_FIRMWARE_FOLDER)

# Check if the installation path exists or create it if possible
if not os.path.exists(installation_path):
    try:
        os.makedirs(installation_path)
        print('-> Installation path not found, but it has been created')
    except OSError:
        print('-> Installation path invalid; aborting!')
        os._exit(1)
else:
    print('-> Installation path found')

# Clear the folder to be sure we are starting with a clean slate
if os.path.exists(installation_path):
    file_list = os.listdir(installation_path)
    for file_name in file_list:
        file_path = os.path.join(installation_path, file_name)
        if os.path.isfile(file_path):
            os.remove(file_path)
        else:
            shutil.rmtree(file_path)

# Download the Multi-Spin 2.0 code and the CC USB firmware
for index, download in enumerate(DOWNLOADS):
    try:
        # Do not use the Python user agent because TI blocks it
        request = urllib2.Request(download, headers = {'User-Agent': ''})
        response = urllib2.urlopen(request)
        output = open(LIBRARIES[index] + '.zip', 'wb')
        output.write(response.read())
        output.close()
        print('-> Downloaded "' + download + '"')
    except urllib.request.URLError as e:
        print('-> Could not download the library files from "' + download + '"; aborting!')
        os._exit(1)

# Unzip the libraries and place the code in the installation path
for library in LIBRARIES:
    try:
        zip_file = zipfile.ZipFile(open(library + '.zip', 'rb'))
        zip_file.extractall(os.path.join(libraries_path, library))
        zip_file.close()
        os.remove(library + '.zip')
        print('-> Extracted and removed "' + library + '.zip"')
    except shutil.Error:
        print('-> Could not extract the libraries to the installation path; aborting!')
        os._exit(1)

# Apply the patches for LED support and SDCC compilation.
PATCHES = {'clock.c': cc_usb_firmware_path + '/source/components/radios/cc2530/clock.c',
           'flash.c': multi_spin_path + '/multi-Spin_v2.0/xpand2531/flash.c',
           'hal_board.h': cc_usb_firmware_path + '/source/components/targets/cc2531_dongle/hal_board.h',
           'hal_cc8051.h': cc_usb_firmware_path + '/source/components/common/cc8051/hal_cc8051.h',
           'hal_int.h': cc_usb_firmware_path + '/source/components/targets/interface/hal_int.h',
           'hal_mcu.c': cc_usb_firmware_path + '/source/components/radios/cc2530/hal_mcu.c',
           'hal_types.h': cc_usb_firmware_path + '/source/components/common/hal_types.h',
           'ioCC2530.h': libraries_path + '/ioCC2530.h',
           'ioCC2531.h': libraries_path + '/ioCC2531.h',
           'leds.c': multi_spin_path + '/multi-Spin_v2.0/xpand2531/leds.c',
           'main_listen_node.c': multi_spin_path + '/multi-Spin_v2.0/listen_node/main.c',
           'main_rf_node.c': multi_spin_path + '/multi-Spin_v2.0/RF_sensor/main.c',
           'rf.c': multi_spin_path + '/multi-Spin_v2.0/xpand2531/rf.c',
           'rf.h': multi_spin_path + '/multi-Spin_v2.0/xpand2531/rf.h',
           'timers34.c': multi_spin_path + '/multi-Spin_v2.0/xpand2531/timers34.c',
           'timers34.h': multi_spin_path + '/multi-Spin_v2.0/xpand2531/timers34.h',
           'usb_framework.c': cc_usb_firmware_path + '/source/components/usb/library/usb_framework.c',
           'usb_framework.h': cc_usb_firmware_path + '/source/components/usb/library/usb_framework.h',
           'usb_framework_structs.h': cc_usb_firmware_path + '/source/components/usb/library/usb_framework_structs.h',
           'usb_interrupt.c': cc_usb_firmware_path + '/source/components/usb/library/cc2531/usb_interrupt.c',
           'usb_interrupt.h': cc_usb_firmware_path + '/source/components/usb/library/usb_interrupt.h',
           'usb_standard_requests.c': cc_usb_firmware_path + '/source/components/usb/library/usb_standard_requests.c',
           'usb_uart.c': cc_usb_firmware_path + '/source/components/usb/class_cdc/usb_uart.c'}

for source, destination in PATCHES.iteritems():
    try:
        shutil.copy(PATCHES_FOLDER + '/' + source, destination)
        print('-> Patched "' + source + '"')
    except shutil.Error:
        print('-> Could not apply all patches; aborting!')
        os._exit(1)

# Copy the projects to the installation path
projects_path = os.path.join(installation_path, PROJECTS_FOLDER)
for project in PROJECTS:
    try:
        shutil.copytree(project, os.path.join(projects_path, project))
        print('-> Copied project folder "' + project + '"')
    except shutil.Error:
        print('-> Could not copy the projects to the installation path; aborting!')
        os._exit(1)

# Finish the installation
print('Installation finished successfully!')
os._exit(0)

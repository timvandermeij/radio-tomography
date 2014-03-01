import os
import shutil
import urllib2
import zipfile

# Sources and folders
MULTI_SPIN_URL = 'https://sites.google.com/site/boccamaurizio/multi-Spin_v2.0.zip'
CC_USB_FIRMWARE_URL = 'http://www.ti.com/lit/sw/swrc088c/swrc088c.zip'

MULTI_SPIN_FOLDER = 'multi-spin-2.0'
CC_USB_FIRMWARE_FOLDER= 'cc-usb-firmware'

LISTEN_NODE_FOLDER = 'listen-node-project'
RF_NODE_FOLDER = 'rf-node-project'
XPAND_UPDATES_FOLDER = 'xpand2531-updates'

LIBRARIES_FOLDER = 'libraries'
PROJECTS_FOLDER = 'projects'

DOWNLOADS = [MULTI_SPIN_URL, CC_USB_FIRMWARE_URL]
LIBRARIES = [MULTI_SPIN_FOLDER, CC_USB_FIRMWARE_FOLDER]
PROJECTS = [LISTEN_NODE_FOLDER, RF_NODE_FOLDER]

# Get the installation path
installation_path = raw_input('Enter the installation path: ')

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
        # Do not use the Python user agent as TI blocks it
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
libraries_path = os.path.join(installation_path, LIBRARIES_FOLDER)
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

# Patch the xpand2531 code with our custom changes.
multi_spin_path = os.path.join(libraries_path, MULTI_SPIN_FOLDER)
try:
    shutil.copy(XPAND_UPDATES_FOLDER + '/leds.c', multi_spin_path + '/multi-Spin_v2.0/xpand2531/leds.c')
    print('-> Patched multi-Spin 2.0')
except shutil.Error:
    print('-> Could not patch multi-Spin 2.0; aborting!')
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

import os
import shutil
import urllib.request
import zipfile

# Sources and folders
MULTI_SPIN_URL = 'https://sites.google.com/site/boccamaurizio/multi-Spin_v2.0.zip'
CC_USB_FIRMWARE_URL = 'http://www.ti.com/lit/sw/swrc088c/swrc088c.zip'

MULTI_SPIN_FOLDER = 'multi-spin-2.0'
CC_USB_FIRMWARE_FOLDER= 'cc-usb-firmware'

LISTEN_NODE_FOLDER = 'listen-node-project'
RF_SENSOR_FOLDER = 'rf-sensor-project'

LIBRARIES_FOLDER = 'libraries'
PROJECTS_FOLDER = 'projects'

DOWNLOADS = [MULTI_SPIN_URL, CC_USB_FIRMWARE_URL]
LIBRARIES = [MULTI_SPIN_FOLDER, CC_USB_FIRMWARE_FOLDER]
PROJECTS = [LISTEN_NODE_FOLDER, RF_SENSOR_FOLDER]

# Get the installation path
print('multi-Spin 2.0 installation')
print('---------------------------', end = '\n\n')
installation_path = input('Enter installation path: ')

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
        request = urllib.request.Request(download, headers = {'User-Agent': ''})
        response = urllib.request.urlopen(request)
        output = open(LIBRARIES[index] + '.zip', 'wb')
        output.write(response.read())
        output.close()
        print('-> Successfully downloaded "' + download + '"')
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
        print('-> Successfully extracted and removed "' + library + '.zip"')
    except shutil.Error:
        print('-> Could not extract the libraries to the installation path; aborting!')
        os._exit(1)

# Copy the projects to the installation path
projects_path = os.path.join(installation_path, PROJECTS_FOLDER)
for project in PROJECTS:
    try:
        shutil.copytree(project, os.path.join(projects_path, project))
        print('-> Successfully copied project folder "' + project + '"')
    except shutil.Error:
        print('-> Could not copy the projects to the installation path; aborting!')
        os._exit(1)

# Finish the installation
print('multi-Spin 2.0 has successfully been installed!')

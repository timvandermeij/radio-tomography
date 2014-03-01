This repository contains the radio tomography software for usage with the CC2530 SoC for the Leiden University and CWI radio tomography project.

Requirements
============

* Python 2.7
* IAR Embedded Workbench for 8051 version 7.60 (either the full edition or a version without code size limitations)

Installation
============

Open a terminal and enter `python install.py` to run the installation script.

Usage
=====

After installation, you will be able to directly open and compile the listener node and RF sensor projects with IAR Embedded Workbench. The produced hex files can be flashed onto the chips using either IAR Embedded Workbench itself or SmartRF Flash Programmer. Make sure that `MAX_NUM_NODES` and `THIS_NODE_ID` are set correctly for each compilation.

The above steps all had to be done on Windows. If the chips have been flashed, all measurements can be done on Linux. Insert the USB dongle, switch on all nodes and run `sudo python2 listener.py` in a terminal to fetch all multi-Spin packets. It might be helpful to pipe the output to a text file using `sudo python2 listener.py > output.txt`.

Authors
=======

* Tim van der Meij (@timvandermeij)
* Alyssa Milburn (@fuzzie)
* Folkert Bleichrodt (@3cHeLoN)

License
=======

The software is licensed under a GPL v2 license. Please refer to the `LICENSE` file for more information. Note that while the code in this repository is licensed under a GPL v2 license, the multi-Spin 2.0 and TI's CC USB firmware libraries (dependencies) may not be. Be sure to consult their licenses before using the code.

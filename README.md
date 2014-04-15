This repository contains the open source radio tomography software toolchain for usage with the Texas Instruments CC2530 SoC. The toolchain is developed by researchers from Leiden University and CWI Amsterdam and contains software from Texas Instruments and the University of Utah amongst others. Please refer to the references section below for an extensive list of sources.

Prerequisites
=============

In order to be able to use the toolchain, you must install the following software on your system. The software has been developed for Linux, but can also be made to work on Windows or any other operating system since all prerequisites are also present for those operating systems.

* Git 1.9.0 (other versions might also work)
* SDCC 3.3.0 (other versions might also work)
* Python 2.7 with the following packages (package names may differ per operating system):
    * `python2-pyserial`
    * `python2-pyqt4`
    * `python2-numpy`
    * `python2-scipy`
    * `python2-pyqtgraph`
    * `python2-opengl`
    * `python2-matplotlib`
* Vim or any other code editor
* boost and boost-libs (package names may differer per operating system)

For all commands in this file, replace `python` by `python2` if your operating system uses that to distinguish between Python 2.x and Python 3.x and replace `vim` by any other code editor you might be using.

Cloning the repository
======================

The first step is to clone the repository to obtian a local copy of the code. Open a terminal window and run the following commands.

    $ git clone https://github.com/timvandermeij/radio-tomography.git
    $ cd radio-tomography

Compiling the software
======================

Now that you have a copy of the software, you can compile the software. The software consists of two parts: software for the listener node (USB dongle) and software for the RF nodes. Both must be compiled individually using the steps outlined below.

Listener node
-------------

Before being able to compile the listener node software, you must first make sure that the configuration file is correct for your configuration. Run the following command to do so.

    $ vim libraries/multi-spin-3.0/xpand2531/configuration.h

For the sensor network to operate correctly, you only have to update the array of MAC addresses of all RF nodes in your network. The order is hereby important because node IDs will be assigned in the order given in the array. You must therefore also place the nodes in the same order in the network to obtain consistent results!

Once you have done this, run the following commands to compile the listener node software.

    $ cd projects/listener-node
    $ make

The result of `make` is (amongst others) an Intel HEX file named `listener-node.hex` that contains the compiled code.

RF nodes
--------

The RF nodes requires no additional configuration and the software can be compiled directly using the following commands.

    $ cd ../rf-node
    $ make

Again, you will end up with an Intel HEX file named `rf-node.hex` that contains the compiled code.

Flashing the software
=====================

The next step is to flash the software onto the nodes. This is a process that must be done once. If you want to experiment with the network later on, you only need to flash the listener node again and not all individual RF nodes (unless you make a fundamental change in the RF node's behaviour of course).

In order to be able to flash the HEX files onto the nodes, we must first compile `cc-tool` from source. Note that compiling from source is necessary because the software has been patched for usage with the CC2530 nodes. Run the following commands to compile `cc-tool`.

    $ cd ../../tools/cc-tool
    $ ./configure
    $ make

You will end up with an executable named `cc-tool`. It is recommended to add this executable to your PATH variables so you can use it everywhere. For this manual, we will assume that you have done this.

Listener node
-------------

To flash the listener node, connect the USB dongle and the SmartRF board to the computer using the steps outlined in the CC2530 user manual. If the devices are properly connected, run the following commands.

    $ cd ../../projects/listener-node
    $ sudo cc-tool -ew listener-node.hex -v

Once the process is complete, the listener node is flashed.

RF nodes
--------

To flash the RF nodes, connect the SmartRF board to the computer and the RF node to the SmartRF board using the steps outlined in the CC2530 user manual. If the devices are properly connected, run the following commands.

    $ cd ../rf-node
    $ sudo cc-tool -ew rf-node.hex -v

Once the process is complete, one RF node is flashed. Repeat this process for all RF nodes in the sensor network.

Inspection
==========

The network should be up and running now. To inspect the network, the toolchain provides several useful tools that are outlined below.

Sniffer
-------

The sniffer allows you to capture all Spin packets received by the listener node. You can pipe the output of the sniffer to a file to save the results if you want to retain the measurements. A useful command to achieve this is:

    $ timeout --kill-after=1s 4s sudo python sniffer.py > results.txt

This command runs the sniffer for exactly 5 seconds and writes the output to `results.txt`.

Plotter
-------

The toolchain provides realtime 2D (line) and 3D (surface) plotters. You can use the 2D (line) plot only for a sensor network consisting of two nodes. Running the command

    $ sudo python 2d_line.py

plots the RSSI and correlation values from node 1 to node 2 in the sensor network. Running

    $ sudo python 3d_surface.py

gives you a 3D surface plot of the averaged RSSI values per time unit of all links in the network. The x-axis and z-axis respectively represent the source and destination nodes and the y-axis represents the RSSI value for each link. This plot is primarily useful for researching the effects of distortions in the network.

Reconstruction
--------------

The realtime reconstruction software can be started by running the following command.

    $ sudo python reconstruction.py
    
The software directly starts converting measurements to reconstruction images.

Authors
=======

* Tim van der Meij (@timvandermeij)
* Alyssa Milburn (@fuzzie)
* Folkert Bleichrodt (@3cHeLoN)

License
=======

The toolchain itself is licensed under a GPL v2 license. Please refer to the `LICENSE` file for more information. However, the external libraries used (like cc-tool, the CC USB firmware or multi-Spin) are licensed under their own licenses. Refer to their individual license files for more information.

References
==========

This software in this toolchain uses or is based on the following sources.

* multi-Spin 2.0: https://sites.google.com/site/boccamaurizio/home/software-data
* Texas Instruments CC USB library: http://www.ti.com/lit/zip/swrc088
* cc-tool: http://sourceforge.net/projects/cctool/files
* smartdoor: http://code.google.com/p/smartdoor/source/browse/trunk/rfap

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
* `boost` and `boost-libs` (package names may differer per operating system)

For all commands in this file, replace `python` by `python2` if your operating system uses that to distinguish between Python 2.x and Python 3.x and replace `vim` by any other code editor you might be using.

Cloning the repository
======================

The first step is to clone the repository to obtian a local copy of the code. Open a terminal window and run the following commands.

    $ git clone https://github.com/timvandermeij/radio-tomography.git
    $ cd radio-tomography

Compiling the software
======================

Now that you have a copy of the software, you can compile the software. The software consists of two parts: software for the listener node (USB dongle) and software for the RF nodes. Both must be compiled individually using the steps outlined below.

We hereby release multi-Spin 3.0. The changelog for version 3.0 in comparison with version 2.0 is as follows:

- Full support has been added for the open source SDCC compiler (you cannot compile with the commercial tool IAR Embedded Workbench anymore).
- Correlation values are implemented into Spin packets.
- Spin clock code has been rewritten and the code style has been made consistent.

In order to be able to flash the HEX files onto the nodes later on, we must first compile `cc-tool`. Note that compiling from source is necessary because the software has been patched for usage with the CC2530 nodes. Run the following commands to compile `cc-tool`.

    $ cd tools/cc-tool
    $ ./configure
    $ make

You will end up with an executable named `cc-tool`. It is recommended to add this executable to your PATH variables so you can use it everywhere. For the next steps, we will assume that you have done this.

Listener node
-------------

Before compiling the listener node software, you must update the number of RF nodes in your sensor network. You can do this as follows:

    $ cd ../../libraries/multi-spin-3.0/xpand2531
    $ vim spin_multichannel.h

In this file, set `MAX_NUM_NODES` to the number of RF nodes in the sensor network. After that, update the number of channels to use. You can do this as follows:

    $ vim channels.h

In this file, set `CHANNELS_NUMBER` to the number of channels that you wish to use. Do not forget to update the channels array a few lines below `CHANNELS_NUMBER`. Make sure that the channels array starts with the channel that you want to use as default channel.

Once you have done all this, run the following commands to compile the listener node software.
    
    $ cd ../../../software/listener-node
    $ make

The result of `make` is (amongst others) an Intel HEX file named `listener-node.hex` that contains the compiled code.

RF nodes
--------

The changes made for the listener node are also used for the RF nodes. However, because each RF node has a unique identifier, the HEX files for each RF node must be compiled separately. Since this can be a tedious task, we have provided build automation for this. Run the following commands to automatically generate all RF node HEX files (change `MAX_NUM_NODES` to the number of nodes in your sensor network):

    $ cd ../../tools
    $ python rf_compiler.py MAX_NUM_NODES

You will end up with `MAX_NUM_NODES` Intel HEX files that can be flashed onto the hardware chips.

Flashing the software
=====================

The next step is to flash the Intel HEX files onto the USB dongle or the RF nodes. This process is described below.

Listener node
-------------

To flash the listener node, connect the USB dongle and the SmartRF board to the computer using the steps outlined in the CC2530 user manual. If the devices are properly connected, run the following commands.

    $ cd ../listener-node
    $ sudo cc-tool -ew listener-node.hex -v

Once the process is complete, the listener node is flashed.

RF nodes
--------

To flash the RF nodes, connect the SmartRF board to the computer and the RF node to the SmartRF board using the steps outlined in the CC2530 user manual. If the devices are properly connected, run the following commands (assuming we flash node 8):

    $ cd ../rf-node
    $ sudo cc-tool -ew rf-node-8.hex -v

Once the process is complete, one RF node (node 8 in our case) is flashed. Repeat this process for all RF nodes in the sensor network.

Tools
=====

The network should be up and running now. To inspect the network, the toolchain provides several useful tools that are outlined below.

Sniffer
-------

The sniffer allows you to capture all Spin packets received by the listener node from the serial connection. It will show each received Spin packet in a readable format. You can pipe the output to a file, however it is recommended to use the measurement framework described below for that. You can run the sniffer using the following command:

    $ cd ../../tools
    $ sudo python sniffer.py

Plotter
-------

The toolchain provides a realtime 2D line plotter. You can use the plotter only for a sensor network consisting of two nodes. Running the command

    $ sudo python plotter.py 26

will open a plot window with two line plots: one for the RSSI values and one for the correlation values. The last parameter, 26 in this case, is the channel for which the RSSI and correlation values are plotted.

Measurement framework
---------------------

The measurement framework is a framework for performing experiments with the sensor network. It can fetch packets directly from the serial connection, filter them according to rules given by the reseacher and export the results as text files or LaTeX plot files (using the `pgfplots` package). First, you must run

    $ vim measurement_framework.py

to adapt the `main` function to your own wishes. Example usage for a simple experiment is:

    # Get packets for five seconds
    sniffer = Sniffer()
    sniffer.start(5)
    sniffer.stop()
    packets = sniffer.getPackets()

    # Only keep packets from node 1 to node 2
    filter = Filter(packets)
    packets = filter.where('fromNode', 1)
    packets = filter.where('toNode', 2)
    
    # Write the results to a text file and create two LaTeX plots
    export = Export(packets)
    export.txt('measurements.txt')
    export.tex('plot_rssi.tex', 'rssi', channels)
    export.tex('plot_corr.tex', 'corr', channels)

After adapting the `measurement_framework.py` file, you can run the experiment using

    $ sudo python measurement_framework.py 11 16 21 26

Again, the parameters indicate the channels to use for the experiment.

Authors
=======

* Folkert Bleichrodt (CWI Amsterdam, @3cHeLoN)
* Tim van der Meij (Leiden University, @timvandermeij)
* Alyssa Milburn (Leiden University, @fuzzie)

License
=======

The toolchain itself is licensed under a GPL v2 license. Please refer to the `LICENSE` file for more information. However, the external libraries used (like cc-tool, the CC USB firmware or multi-Spin) are licensed under their own licenses. Refer to their individual license files for more information. multi-Spin 3.0 has the same license as multi-Spin 2.0.

References
==========

This software in this toolchain uses or is based on the following sources.

* multi-Spin 2.0: https://sites.google.com/site/boccamaurizio/home/software-data
* Texas Instruments CC USB library: http://www.ti.com/lit/zip/swrc088
* cc-tool: http://sourceforge.net/projects/cctool/files
* smartdoor: http://code.google.com/p/smartdoor/source/browse/trunk/rfap

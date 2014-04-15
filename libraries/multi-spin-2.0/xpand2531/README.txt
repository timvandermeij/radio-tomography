xpand TI CC2531 USB dongle library - Release 0.1

Author(s):
Maurizio Bocca (maurizio.bocca@utah.edu)
Joey Wilson (joey@xandem.com)
Neal Patwari (neal@xandem.com)

This library is result of a collaboration between SPAN lab at the University of Utah and
Xandem Technology, LLC.

How to install the library:
1) Download all files and place in a separate directory near your project directory;
2) Add the files that you want to use to your project. In IAR Embedded Workbench,
right click the project title in the workspace browser and then click "add.. files..".
Only the .c files are necessary, but you can include the .h files for convenience;
3) Make sure the .h files can be seen in your include paths found in project options...
c/c++ compiler... preprocessor... additional include directories. If the library 
directory is a sibling of the project directory, add this:
"$PROJ_DIR$/../xpand2531/" without the quotes;
4) Use "#include" statements to import the functions into your code. For example
- #include "rf.h"
5) Look at the header files for info on how the functions work.

Implemented:
- rf.h: A basic framework for transmitting and receiving arbitrary packets over the RF 
module. The RF library does not implement CCA (Clear Channel Assessment).
- leds.h: LED functions
- spin_clock.h: Clock setup functions (make sure you set up the clocks by calling
clockInit() as the first statement in main)
- timers34.h: Timer 3 and 4 functions. These are one-shot timers only, and must be
restarted each time they fire.
- flash.h: Flash libraries for reading and writing to non-volitile memory. When writing,
the entire page will be erased.
- spin_multichannel.h: This is included for convenience of including spin.h in multiple
projects (RF sensor, listen node, etc.).

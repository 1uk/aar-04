# Compiling programs
To compile your programs you just have to invoke this command:
    make
The output is pretty verbose and will list down the configurations that the makefile is using and from where it got the values.
If there were any errors then they will be displayed with line numbers, which you can correct.

# Uploading programs
To upload the compiled program to your Arduino, just plug your Arduino and run this command
    make upload
The program will be recompiled if needed and will be uploaded to your Arduino board.

# Opening Serial monitor
The makefile can also be used to check the serial output from your Arduino. To do that just run this command:
    make monitor
This command will open a serial connection to your Arduino using [gnu screen](http://www.gnu.org/software/screen/ "gnu.org"). The makefile tries to auto detect the baud rate. If it is not able to detect it properly, then you can manually set it using the variable MONITOR_BAUDRATE.

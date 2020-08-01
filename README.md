# CarHacks

This repository is made by referring internet and some findings done by other developers.

Tribute to all.

If you are using other than SparkFun, please modify MCP2515_CS 'B,2' with 'B,1' in 'Canbus/defaults.h'.


# Step 1

Need to do initial setup for your hardware. Here I tried Arduino UNO and CAN-bus shield.

# Step 2

Burn Sample code, understand the working of the hardaware(Read / Write Program).


# Step 3

For Can-bus sniffing following steps would be helpful (if you are using linux as Operating System)

        sudo apt install can-utils -Y

Above statement will helps you to install #can-utils 

##following commands will help you to up the stream of can-bus signals.

        sudo slcan_attach -f -s6 -o /dev/ttyUSB0

above command is used for attaching the serial port, "/dev/ttyUSB0" states connected usb device (Here Arduino UNO, it might vary according to your port number).

        sudo slcand -S 1000000 ttyUSB0 can0

above will initialize the baud rate of the CAN-bus signals.

        sudo ifconfig can0 up

then, you can see the incoming stream by executing following command;

        candump can0

If you want to sniff the can-bus data stream, you can execute the below command (skip above command - candump)

        cansniffer -c can0


For Exiting (ctrl + C , in linux)

###Cleanup should be done after this

        sudo ifconfig can0 down
        sudo killall slcand




Identify the actions and data streams coming out from OBD port.

Have a great findings...












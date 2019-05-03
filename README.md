# README

This is a record of thus far work done for the BLDG 61 space camp program.

### Get space credits for ROCKBLOCK device to talk to satellites

1. Go to [rock7.com/register](http://www.rock7.com/register) and create an account (or log in to your existing account).
1. Add a ROCKBLOCK using the registration code.
1. Add credits for communication and set up a line for your device.

### Get ROCKBLOCK hardware communications up (testing ROCKBLOCK in isolation):

1. Download [FTDI driver for your local dev environment](https://www.ftdichip.com/Drivers/VCP.htm)
1. Download [Arduino IDE](https://www.arduino.cc/en/Main/Software)
1. Plug the FTDI cable into the ROCKBLOCK
1. Plug in the usb end of the FTDI cable into your computer, and select the serial port under Tools -> Port
1. Open the Serial Monitor under Tools
1. Change baud rate to `19200 baud`, and line ending to `Carriage return`
1. GO OUTSIDE! You are about to try and talk to a satellite! Out in the open, and maybe face the antenna toward the sky.
1. Send following series of messages to the device (this is a sample ASCII version, use binary for deployed / prod use especially with longer messages):

    ```C
    AT
    AT&K0 // Turn off Flow Control
    AT+SBDWT=Hello Elowyn // Insert ASCII message into MO (mobile origination... coming FROM the device) buffer
    AT+SBDIX // Initiate an Extended SBD Session (exchange messages)
    ```

    **remember**, you will need `\r` (Carriage return) at the end of each of these lines in a code file!

1. You should get a message back in this format: `+SBDIX: <MO status>, <MOMSN>, <MT status>, <MTMSN>, <MT length>, <MT queued>\r`

    Interpret this response as follows ([source](https://docs.rockblock.rock7.com/docs/transmit-ascii-data)):
    > The SBDIX command denotes the status of your sent, received and queued messages:
    >
    > `<MO status>` - Any returned number with a value of 0 to 2 indicates your message has been successfully transmitted. Any number above 2 indicates that the message has not been successfully transmitted.
    >
    >`<MOMSN>` - This number denotes the MO message number and cycles between 0 and 65535.
    >
    >`<MT status>`:
    >
    > * 0 - No messages waiting to be received.
    > * 1 - New message successfully received.
    > * 2 - Error during mailbox check / message reception.
    >
    >`<MTMSN>` - This number denotes the MT message number and cycles between 0 and 65535.
    >
    >`<MT length>` - The size (in bytes) of the MT message.
    >
    >`<MT queued>` - The number of MT messages in the queue waiting to be downloaded.

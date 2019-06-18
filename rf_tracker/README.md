# README

### One signal radio frequency transmitter and receiver

* Problems finding your port for a plugged in board? Try hitting the board reset button, or change the connection cable.

#### Transmitter:

Required materials:

1. RedBoard or Arduino Uno
1. [Breadboard - 1/4 size is sufficient](https://www.sparkfun.com/products/12002)
1. Button
1. Jumper wires - 2 black, 2 orange, 1 red
1. [RF transmitter (pin diagrams linked under Documents -> Datasheet)](https://www.sparkfun.com/products/10534)

Assembly:

* 2 black "ground" wires: Connect the RB GND to pin 1 of the RF transmitter. Connect other GND to one side of the button
* 2 orange "transmitter signal" wires: Connect RB pin ~9 to pin 2 of the RF Transmitter. Connect RB pin 4 to other side of button
* 1 red "power" wire: Connect RedBoard 5V to pin 3 of the RF Transmitter.

#### Receiver

Required materials:

1. [Breadboard - 1/4 size is sufficient](https://www.sparkfun.com/products/12002)
1. Jumper wires - 2 black, 1 orange, 1 red
1. [RF receiver (pin diagrams linked under Documents -> Datasheet)](https://www.sparkfun.com/products/10532)
1. power adapter
1. 6V battery holder
1. Piezo Buzzer


Get RF (radio frequency) receiver, power adapter, 6V battery holder, breadboard, piezo buzzer, jumper wires - 1 black
Connect battery holder to power adapter, power adapter red wire to pin 5 of RF Receiver and black wire to negative power rail.
1 black “ground” wire: ground rail to pin 1 of RF Receiver
Connect Piezo red to pin 3 of RF Receiver, Piezo black to ground rail
An Antenna can be attached to pin 8 of the RF Receiver and ground pin 8


Assembly:

* Connect battery holder to power adapter, power adapter red wire to pin 5 of RF Receiver and black wire to negative power rail.
* 1 black “ground” wire: ground rail to pin 1 of RF Receiver
* Connect Piezo red to pin 3 of RF Receiver, Piezo black to ground rail
* An Antenna can be attached to pin 8 of the RF Receiver and ground pin 8

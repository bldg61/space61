# README

### One signal radio frequency transmitter and receiver

* Note! The RedBoard for the Reciever is ONLY providing power. No code is needed, and this can be exchanged for an alternative power source.
* Problems finding your port for a plugged in board? Try hitting the board reset button, or change the connection cable.

#### Transmitter:

Required materials:

1. RedBoard or Arduino Uno
1. [Breadboard - 1/4 size is sufficient](https://www.sparkfun.com/products/12002)
1. Jumper wires - 1 black, 1 orange, 1 red
1. [RF transmitter pin diagrams linked under Documents -> Datasheet](https://www.sparkfun.com/products/10534)

Assembly:

* 1 black "ground" wires: Connect the RedBoard ground to pin 1 of the RF transmitter.
* 1 orange "transmitter signal" wire: Connect RedBoard pin ~9 to pin 2 of the RF Transmitter.
* 1 red "power" wire: Connect RedBoard 5V to pin 3 of the RF Transmitter.

#### Receiver

Required materials:

1. RedBoard or Arduino Uno
1. [Breadboard - 1/4 size is sufficient](https://www.sparkfun.com/products/12002)
1. Jumper wires - 2 black, 1 orange, 1 red
1. [RF receiver (pin diagrams linked under Documents -> Datasheet)](https://www.sparkfun.com/products/10532)


Assembly:

* 2 black "ground" wires: Connect RedBoard ground to pin 1 of the RF Receiver. Connect other RedBoard ground to speaker ground.
* 1 orange "receiver signal" wire: Connect pin 3 of the RF Receiver to speaker power
* 1 red "power" wire: connect Redboard 5V to pin 5 of RF Receiver.

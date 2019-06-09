# README

### Four signal radio frequency transmitter and receiver

Code starting place is from [github.com/bboyho/RF_Links](https://github.com/bboyho/RF_Links)

#### Transmitter:

Required materials:

1. RedBoard or Arduino Uno
1. [Breadboard - 1/2 size is sufficient](https://www.sparkfun.com/products/12002)
1. Jumper wires - 6 black, 1 orange, 2 red, 1 yellow, 1 green, 1 blue (or whatever you have)
1. [Buttons - one each red, yellow, green, blue](https://www.sparkfun.com/products/15326)
1. [RF transmitter pin diagrams linked under Documents -> Datasheet](https://www.sparkfun.com/products/10534)

Assembly:

* 6 black "ground" wires: Connect the RedBoard ground to the ground rail of the breadboard. Place the four buttons in the breadboard and connect one side of each to the ground rail. Connect pin 1 of the RF transmitter to ground rail.
* 1 orange "transmitter signal" wire: Connect RedBoard pin ~3 to pin 2 of the RF Transmitter.
* 1 red "power" wire: Connect RedBoard 5V to pin 3 of the RF Transmitter.
* 1 each red, yellow, green, blue "button signal" wires: Connect each other side of the button to RedBoard pins 8, ~9, ~10, ~11.

#### Receiver

Required materials:

1. RedBoard or Arduino Uno
1. [Breadboard - 1/2 size is sufficient](https://www.sparkfun.com/products/12002)
1. Jumper wires - 2 black, 1 orange, 2 red, 1 yellow, 1 green, 1 blue (or whatever you have)
1. [LEDs - one each red, yellow, green, blue](https://www.sparkfun.com/products/12062)
1. [RF receiver (pin diagrams linked under Documents -> Datasheet)](https://www.sparkfun.com/products/10532)


Assembly:

* 2 black "ground" wires: Connect RedBoard ground to breadboard rail (use the rail with tie-in points closer to the rows). Connect ground to pin 1 of the RF Receiver.
* 1 orange "receiver signal" wire: Connect pin 2 of the RF Receiver to RedBoard pin 2.
* 1 red "power" wire: connect Redboard 5V to pin 5 of RF Receiver.
* 1 each red, yellow, green, blue leds: put the short leg in the ground rail, and the long leg in separate rows
* 1 each red, yellow, green, blue "button signal" wires: Connect each other side of the corresponding LED to RedBoard pins 8, ~9, ~10, ~11.

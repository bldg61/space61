/*
 RF ASK Tx and Rx Example Code
 Created in 2011 by NPoole @ SparkFun Electronics

 modified 5 Feb 2015
 by Bobby Chan @ SparkFun Electronics

 modified again
 by <git log --oneline --graph --decorate --all>

 Description:
 This code depends on the VirtualWire Library for Arduino and is
 based on the example code provided by Mike McCauley (mikem@open.com.au)
 To download the most recent VirtualWire Library =>
 http://www.airspayce.com/mikem/arduino/VirtualWire/index.html
 See VirtualWire.h for detailed API docs.
 */

// RF LINK TRANSMITTER CODE
#include <VirtualWire.h>

void setup(){
  Serial.begin(9600);    // Debugging only
  Serial.println("Initialize RF Link Transmitter Code");

  // Initialise the IO and ISR
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);     // Bits per sec
  vw_set_tx_pin(3);         //Pin 3 is connected to "Digital Output" of transmitter

  //Set pins as input for buttons
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);

  //Set pin for LED as status indicator
  pinMode (13, OUTPUT);

  //Initialize button pins
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
}

void loop(){
  char *msg;

  if(digitalRead(8) == LOW){
    digitalWrite(13, true);  //Flash status LED to show transmitting

    char *msg = "1"; //message to send
    tx_debug(msg); //output message to serial monitor for debugging.
    vw_send((uint8_t *)msg, strlen(msg));//send message
    vw_wait_tx(); // Wait until the whole message is gone

    digitalWrite(13, false); //Turn off status LED
  }

  else if(digitalRead(9) == LOW){
    digitalWrite(13, true);  //Flash status LED to show transmitting

    char *msg = "2"; //message to send
    tx_debug(msg); //output message to serial monitor for debugging.
    vw_send((uint8_t *)msg, strlen(msg));//send message
    vw_wait_tx(); // Wait until the whole message is gone

    digitalWrite(13, false); //Turn off status LED
  }

  else if(digitalRead(10) == LOW){
    digitalWrite(13, true);  //Flash status LED to show transmitting

    char *msg = "3";
    tx_debug(msg); //output message to serial monitor for debugging.
    vw_send((uint8_t *)msg, strlen(msg));//send message
    vw_wait_tx(); // Wait until the whole message is gone

    digitalWrite(13, false); //Turn off status LED
  }

  else if(digitalRead(11) == LOW){
    digitalWrite(13, true);  //Flash status LED to show transmitting

    char *msg = "4";
    tx_debug(msg); //output message to serial monitor for debugging.
    vw_send((uint8_t *)msg, strlen(msg));//send message
    vw_wait_tx(); // Wait until the whole message is gone

    digitalWrite(13, false); //Turn off status LED
  }
}

void tx_debug(char *temp_msg){
  //output to serial monitor to indicate which button pressed
  Serial.print("Button was pressed, sending msg = ");
  Serial.println(temp_msg);
}

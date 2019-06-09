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

bool sending = false;

void setup(){
  Serial.begin(9600);        // Debugging only
  Serial.println("Initialize RF Link Transmitter Code");

  // Initialise the IO and ISR
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);            // Bits per sec
  vw_set_tx_pin(3);          //Pin 3 is connected to "Digital Output" of transmitter

  //Set pins as input for buttons
  pinMode(8, INPUT_PULLUP);

  //Set pin for LED as status indicator
  pinMode (13, OUTPUT);

  //Initialize button pins
  digitalWrite(8, HIGH);
}

void loop(){
  char *msg;
  digitalWrite(13, sending);

  if(digitalRead(8) == LOW){
    sending = !sending;
    Serial.print("Please toggle sending... sending set to ");
    Serial.println(sending);
    delay(1000);
  }
  if (sending) {
    char *msg = "1"; //message to send
    vw_send((uint8_t *)msg, strlen(msg));//send message
    vw_wait_tx(); // Wait until the whole message is gone
  }
}

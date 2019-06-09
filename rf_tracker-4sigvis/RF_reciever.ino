/*
 RF ASK Tx and Rx Example Code
 Created in 2011 by NPoole @ SparkFun Electronics
 
 modified 5 Feb 2015
 by Bobby Chan @ SparkFun Electronics

 modified again
 by <git log --oneline --graph --decorate --all> 🤔

 Description:
 This code depends on the VirtualWire Library for Arduino and is
 based on the example code provided by Mike McCauley (mikem@open.com.au)
 To download the most recent VirtualWire Library =>
 http://www.airspayce.com/mikem/arduino/VirtualWire/index.html
 See VirtualWire.h for detailed API docs.
 */

// RF LINK RECEIVER CODE
#include <VirtualWire.h>

void setup()
{
  Serial.begin(9600);  // Debugging only
  Serial.println("Initialize RF Link Rx Code");

  //Initialize the IO and ISR
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);     // Bits per sec
  vw_set_rx_pin(2);         //Pin 2 is connected to "Digital Output" of receiver
  vw_rx_start();           // Start the receiver PLL running

  //Set pins for LED Output
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  //Set pin for LED as status indicator
  pinMode (13, OUTPUT);
}

void loop()
{
  //Initialize/reinitialize LEDs
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);

  //Set buffer array based on max message length
  uint8_t buf[VW_MAX_MESSAGE_LEN];

  //Set variable to indicate buffer length
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) // Non-blocking
  {
    // Flash status LED to show received data
    digitalWrite(13, true);

    // Message with a good checksum received, dump it.
    Serial.print("Received message: ");

    for (int i = 0; i < buflen; i++){
      // Print message received in buffer through this loop
      Serial.print(buf[i]);
      //add space to distinguish characters from each other if showing ASCII decimal #
      //Serial.print(" ");

      //if character received matches, turn on associated LED
      if(buf[i] == '1'){
        digitalWrite(8, HIGH);
      }
      else if(buf[i] == '2'){
        digitalWrite(9, HIGH);
      }
      else if(buf[i] == '3'){
        digitalWrite(10, HIGH);
      }
      else if(buf[i] == '4'){
        digitalWrite(11, HIGH);
      }
    }
    //Print next character on new line
    Serial.println("");

    //Turn off status LED
    digitalWrite(13, false);
  }
}

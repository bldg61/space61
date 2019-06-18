void setup() {
  pinMode(4,INPUT_PULLUP);
  pinMode(9, OUTPUT);
}

void loop() {
  if(digitalRead(4) == LOW) {
    tone(9, 440);
  } else {
    noTone(9);
  }
}




void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delayMicroseconds(1);                       // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delayMicroseconds(1);                       // wait for a second
}
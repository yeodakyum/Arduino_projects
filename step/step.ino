/* Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board and Arduino UNO. More info: https://www.makerguides.com */

// Include the Arduino Stepper.h library:
#include <Stepper.h>

// Define number of steps per rotation:
const int stepsPerRevolution = 2048;
int  input = 0;
// Wiring:
// Pin 8 to IN1 on the ULN2003 driver
// Pin 9 to IN2 on the ULN2003 driver
// Pin 10 to IN3 on the ULN2003 driver
// Pin 11 to IN4 on the ULN2003 driver

// Create stepper object called 'myStepper', note the pin order:

int stepTo = 0;
int Pos = 0 ;
int initial = 0;
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {

  myStepper.setSpeed(10);
  
  // Begin Serial communication at a baud rate of 9600:
  Serial.begin(9600);
   initial = analogRead(A0);
}

void loop() {
    Pos = analogRead(A0);
    if (Pos > initial + 20 ) myStepper.step(1);
    
    if (Pos < initial - 20 ) myStepper.step(-1);

    // Step one revolution in one direction:

 
}
  // Step one revolution in the other direction:
 // Serial.println("counterclockwise");
 // myStepper.step(-stepsPerRevolution);
  //delay(500);

/*Example sketch to control a stepper motor with DRV8825 stepper motor driver, AccelStepper library and Arduino: acceleration and deceleration. More info: https://www.makerguides.com */
// Include the AccelStepper library:
#include <AccelStepper.h>
// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1
int input;
// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);
void setup() {
  // Set the maximum speed and acceleration:
  Serial.begin(9600);
  stepper.setMaxSpeed(250);
  stepper.setAcceleration(1000000);
}
void loop() {
  if(Serial.available()>0){
   // Set the target position:
   input = Serial.parseInt();
   Serial.print("move to:");
   Serial.println(input); 
  }
    stepper.moveTo(input);
  // Run to target position with set speed and acceleration/deceleration:
  stepper.runToPosition();
}

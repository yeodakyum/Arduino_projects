// Include the AccelStepper Library
#include <AccelStepper.h>

// Define pin connections
const int dirPin = 2;
const int stepPin = 3;

// Define motor interface type
#define motorInterfaceType 1

// Creates an instance
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
  // set the maximum speed, acceleration factor,
  // initial speed and the target position
  myStepper.setMaxSpeed(2000);
  myStepper.setAcceleration(400);
  myStepper.setSpeed(1000);
}

void loop() {
  // Change direction once the motor reaches target position

  myStepper.runSpeed();
}

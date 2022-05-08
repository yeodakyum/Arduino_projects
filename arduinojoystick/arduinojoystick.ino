#include <Joystick.h>

// Create the Joystick
Joystick_ Joystick;

// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap13 = 13;
const int pinToButtonMap12 = 12;
const int pinToButtonMap11 = 11;
const int pinToButtonMap10 = 10;
const int pinToButtonMap9 = 9;
const int pinToButtonMap8 = 8;
const int pinToButtonMap7 = 7;
const int pinToButtonMap6 = 6;
const int pinToButtonMap5 = 5;
const int pinToButtonMap4 = 4;
const int pinToButtonMap3 = 3;
const int pinToButtonMap2 = 2;
const int pinToButtonMap1 = A5;

void setup() {
  // Initialize Button Pins
  pinMode(pinToButtonMap1, INPUT_PULLUP);
  pinMode(pinToButtonMap2, INPUT_PULLUP);
  pinMode(pinToButtonMap3, INPUT_PULLUP);
  pinMode(pinToButtonMap4, INPUT_PULLUP);
  pinMode(pinToButtonMap5, INPUT_PULLUP);
  pinMode(pinToButtonMap6, INPUT_PULLUP);
  pinMode(pinToButtonMap7, INPUT_PULLUP);
  pinMode(pinToButtonMap8, INPUT_PULLUP);
  pinMode(pinToButtonMap9, INPUT_PULLUP);
  pinMode(pinToButtonMap10, INPUT_PULLUP);
  pinMode(pinToButtonMap11, INPUT_PULLUP);
  pinMode(pinToButtonMap12, INPUT_PULLUP);
  pinMode(pinToButtonMap13, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();
}

// Last state of the button
int lastButtonState1 = 0;
int lastButtonState2 = 0;
int lastButtonState3 = 0;
int lastButtonState4 = 0;
int lastButtonState5 = 0;
int lastButtonState6 = 0;
int lastButtonState7 = 0;
int lastButtonState8 = 0;
int lastButtonState9 = 0;
int lastButtonState10 = 0;
int lastButtonState11 = 0;
int lastButtonState12 = 0;
int lastButtonState13 = 0;


void loop() {

  // Read pin values
  int currentButtonState1 = !digitalRead(pinToButtonMap1);
  if (currentButtonState1 != lastButtonState1)
  {
    Joystick.setButton(0, currentButtonState1);
    lastButtonState1 = currentButtonState1;
  }





  int currentButtonState3 = !digitalRead(pinToButtonMap3);
  if (currentButtonState3 != lastButtonState3)
  {
    Joystick.setButton(2, currentButtonState3);
    lastButtonState3 = currentButtonState3;
  }

 /* int currentButtonState2 = !digitalRead(pinToButtonMap2);
  if ((digitalRead(pinToButtonMap3) || digitalRead(pinToButtonMap3)))
  {
    Joystick.setButton(1, currentButtonState2);
    lastButtonState2 = currentButtonState2;
  }
  */

  if(digitalRead(pinToButtonMap1) && digitalRead(pinToButtonMap3)){
    delay(100);
    Joystick.setButton(1, 1);
     }
     else{
      Joystick.setButton(1, 0);
     }
  int currentButtonState4 = !digitalRead(pinToButtonMap4);
  if (currentButtonState4 != lastButtonState4)
  {
    Joystick.setButton(3, currentButtonState4);
    lastButtonState4 = currentButtonState4;
  }


  int currentButtonState5 = !digitalRead(pinToButtonMap5);
  if (currentButtonState5 != lastButtonState5)
  {
    Joystick.setButton(4, currentButtonState5);
    lastButtonState5 = currentButtonState5;
  }


  int currentButtonState6 = !digitalRead(pinToButtonMap6);
  if (currentButtonState6 != lastButtonState6)
  {
    Joystick.setButton(5, currentButtonState6);
    lastButtonState6 = currentButtonState6;
  }


  int currentButtonState8 = !digitalRead(pinToButtonMap8);
  if (currentButtonState8 != lastButtonState8)
  {
    Joystick.setButton(7, currentButtonState8);
    lastButtonState8 = currentButtonState8;
  }


  int currentButtonState7 = !digitalRead(pinToButtonMap7);
  if (currentButtonState7 != lastButtonState7)
  {
    Joystick.setButton(6, currentButtonState7);
    lastButtonState7 = currentButtonState7;
  }


  int currentButtonState9 = !digitalRead(pinToButtonMap9);
  if (currentButtonState9 != lastButtonState9)
  {
    Joystick.setButton(8, currentButtonState9);
    lastButtonState9 = currentButtonState9;
  }


  int currentButtonState10 = !digitalRead(pinToButtonMap10);
  if (currentButtonState10 != lastButtonState10)
  {
    Joystick.setButton(9, currentButtonState10);
    lastButtonState10 = currentButtonState10;
  }


  int currentButtonState11 = !digitalRead(pinToButtonMap11);
  if (currentButtonState11 != lastButtonState11)
  {
    Joystick.setButton(10, currentButtonState11);
    lastButtonState11 = currentButtonState11;
  }


  int currentButtonState12 = !digitalRead(pinToButtonMap12);
  if (currentButtonState12 != lastButtonState12)
  {
    Joystick.setButton(11, currentButtonState12);
    lastButtonState12 = currentButtonState12;
  }


  int currentButtonState13 = !digitalRead(pinToButtonMap13);
  if (currentButtonState13 != lastButtonState13)
  {
    Joystick.setButton(12, currentButtonState13);
    lastButtonState13 = currentButtonState13;
  }




  delay(50);
}

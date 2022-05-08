#include "Servo.h"


Servo motA;
Servo motB;
Servo motC;
Servo motD;
void setup() {
  // put your setup code here, to run once:
  
  motA.attach(4, 1000, 2000); // 4번핀 = 모터 A
  motB.attach(5, 1000, 2000); // 5번핀 = 모터 B
  motC.attach(6, 1000, 2000); // 6번핀 = 모터 C
  motD.attach(7, 1000, 2000); // 7번핀 = 모터 D

  motA.write(0); // 모터 A 속도 0
  motB.write(0); // 모터 B 속도 0
  motC.write(0); // 모터 C 속도 0
  motD.write(0); // 모터 D 속도 0

}



void loop() {
  // put your main code here, to run repeatedly:

        delay(5000);
        motA.writeMicroseconds((int)1500);
        delay(1000);
        motB.writeMicroseconds((int)1500);
        delay(1000);
        motC.writeMicroseconds((int)1500);
        delay(1000);
        motD.writeMicroseconds((int)1500);
        delay(1000);
}

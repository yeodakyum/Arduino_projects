#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);


void setup() {
  // put your setup code here, to run once:

pinMode(13,OUTPUT);
pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
}

void loop() {
  // LED조명:
digitalWrite(13,HIGH);
digitalWrite(11,HIGH);
//번호 입력:
int button3= digitalRead(5);
if(button3==1)infoinput();



}



void infoinput(){
lcd.begin();
lcd.backlight();

lcd.setCursor(0,0);

lcd.print("ID:");
  int ID = input();
//비밀번호를 입력하세요


lcd.print("PW:");
int PW = input();
   //lcd 상품번호를 입력하세요



lcd.print("PN:");
int PN = input();

  }

int input(){

  int a1 = digitalRead(5);
  int b2 = digitalRead(7);
  int c3 = digitalRead(6);
  int d4 = digitalRead(2);
  int e5 = digitalRead(3);



  int a=0;
  int b=0;
  int c=0;
  int d=0;
  
  if(a1==1)a=1;
  else if(b2==1)a=2;
  else if(c3==1)a=3;
  else if(d4==1)a=4;
  else if(e5==1)a=5;
lcd.setCursor(0,3);
lcd.print(a);

  
  if(a1==1)b=1;
  else if(b2==1)b=2;
  else if(c3==1)b=3;
  else if(d4==1)b=4;
  else if(e5==1)b=5;
lcd.setCursor(0,4);
lcd.print(b);

  
  if(a1==1)c=1;
  else if(b2==1)c=2;
  else if(c3==1)c=3;
  else if(d4==1)c=4;
  else if(e5==1)c=5;
lcd.setCursor(0,5);
lcd.print(c);

  if(a1==1)d=1;
  else if(b2==1)d=2;
  else if(c3==1)d=3;
  else if(d4==1)d=4;
  else if(e5==1)d=5;
lcd.setCursor(0,6);
lcd.print(d);
  
  int abcd= 1000*a+100*b+10*c+d;
  return(abcd);
}  

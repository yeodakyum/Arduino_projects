int latchPin = 15; // pin D8 on NodeMCU boards
int clockPin = 14; // pin D5 on NodeMCU boards
int dataPin = 13;  // pin D7 on NodeMCU
 
 byte leds = 0;    // Variable to hold the pattern of which LEDs are currently turned on or off
int off = 0;
#include <ESP8266WiFi.h> // ESP 8266 와이파이 라이브러리
#include <ESP8266HTTPClient.h> // HTTP 클라이언트
int data;


String url = "http://openapi.airkorea.or.kr/openapi/services/rest/ArpltnInforInqireSvc/getMsrstnAcctoRltmMesureDnsty?serviceKey=fRd4mNKHdXNcPf4o9YusPZi0ig%2F%2BHydGO1I2%2FfLp8%2Fm%2B6%2BXV4oDW5qjrSqBLydVoQKuz6n6eCPXh1GiQm8Xbdg%3D%3D&numOfRows=1&pageNo=1&stationName=%EC%84%9D%EB%B0%94%EC%9C%84&dataTerm=DAILY&ver=1.3";


void happy(){
  digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
   shiftOut(dataPin, clockPin, LSBFIRST, B01111111);
   shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
   digitalWrite(latchPin, HIGH); delay(1);
   digitalWrite(latchPin, LOW);

   shiftOut(dataPin, clockPin, LSBFIRST, B00010000);
   shiftOut(dataPin, clockPin, LSBFIRST, B10111111);
   shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
   
      digitalWrite(latchPin, HIGH); delay(1);
         digitalWrite(latchPin, LOW);

   shiftOut(dataPin, clockPin, LSBFIRST, B00010000);
   shiftOut(dataPin, clockPin, LSBFIRST, B11011111);
   shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
   
      digitalWrite(latchPin, HIGH); delay(1);   digitalWrite(latchPin, LOW);

   shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
   shiftOut(dataPin, clockPin, LSBFIRST, B11101111);
   shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
   
      digitalWrite(latchPin, HIGH); delay(1);   digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00000100);
   
   shiftOut(dataPin, clockPin, LSBFIRST, B11110111);
   shiftOut(dataPin, clockPin, LSBFIRST, B00010000);
   
      digitalWrite(latchPin, HIGH); delay(1);   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, B00000100); 
   
   shiftOut(dataPin, clockPin, LSBFIRST, B11111011);
   shiftOut(dataPin, clockPin, LSBFIRST, B00010000);
    
      digitalWrite(latchPin, HIGH); delay(1);   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, B01010000);
   
   shiftOut(dataPin, clockPin, LSBFIRST, B11111101);
   shiftOut(dataPin, clockPin, LSBFIRST, B00000101);
    
      digitalWrite(latchPin, HIGH); delay(1);   digitalWrite(latchPin, LOW);

   shiftOut(dataPin, clockPin, LSBFIRST, 0x00);
   shiftOut(dataPin, clockPin, LSBFIRST, B11111110);
   shiftOut(dataPin, clockPin, LSBFIRST, 0x00);
      
      digitalWrite(latchPin, HIGH); delay(1);
  
}

void meh(){
  digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
   shiftOut(dataPin, clockPin, LSBFIRST, B01111111);
   shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
   digitalWrite(latchPin, HIGH); delay(1);
   digitalWrite(latchPin, LOW);

   shiftOut(dataPin, clockPin, LSBFIRST, B00110000);
   shiftOut(dataPin, clockPin, LSBFIRST, B10111111);
   shiftOut(dataPin, clockPin, LSBFIRST, B00001100);
   
      digitalWrite(latchPin, HIGH); delay(1);
         digitalWrite(latchPin, LOW);

   shiftOut(dataPin, clockPin, LSBFIRST, B00110000);
   shiftOut(dataPin, clockPin, LSBFIRST, B11011111);
   shiftOut(dataPin, clockPin, LSBFIRST, B00001100);
   
      digitalWrite(latchPin, HIGH); delay(1);   digitalWrite(latchPin, LOW);

   shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
   shiftOut(dataPin, clockPin, LSBFIRST, B11101111);
   shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
   
      digitalWrite(latchPin, HIGH); delay(1);   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
   
   shiftOut(dataPin, clockPin, LSBFIRST, B11110111);
   shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
   
      digitalWrite(latchPin, HIGH); delay(1);   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, B00000000); 
   
   shiftOut(dataPin, clockPin, LSBFIRST, B11111011);
   shiftOut(dataPin, clockPin, LSBFIRST, B00000000);
    
      digitalWrite(latchPin, HIGH); delay(1);   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, B11110000);
   
   shiftOut(dataPin, clockPin, LSBFIRST, B11111101);
   shiftOut(dataPin, clockPin, LSBFIRST, B00001111);
    
      digitalWrite(latchPin, HIGH); delay(1);   digitalWrite(latchPin, LOW);

   shiftOut(dataPin, clockPin, LSBFIRST, 0x00);
   shiftOut(dataPin, clockPin, LSBFIRST, B11111110);
   shiftOut(dataPin, clockPin, LSBFIRST, 0x00);
      
      digitalWrite(latchPin, HIGH); delay(1);
   
  }


void bad(){
  digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, B00100000);
   shiftOut(dataPin, clockPin, LSBFIRST, B01111111);
   shiftOut(dataPin, clockPin, LSBFIRST, B00001000);
   digitalWrite(latchPin, HIGH); delay(1);
   digitalWrite(latchPin, LOW);

   shiftOut(dataPin, clockPin, LSBFIRST, B10101000);
   shiftOut(dataPin, clockPin, LSBFIRST, B10111111);
   shiftOut(dataPin, clockPin, LSBFIRST, B00101010);
   
      digitalWrite(latchPin, HIGH); delay(1);
         digitalWrite(latchPin, LOW);

   shiftOut(dataPin, clockPin, LSBFIRST, B10001000);
   shiftOut(dataPin, clockPin, LSBFIRST, B11011111);
   shiftOut(dataPin, clockPin, LSBFIRST, B00100010);
   
      digitalWrite(latchPin, HIGH); delay(1);   digitalWrite(latchPin, LOW);

   shiftOut(dataPin, clockPin, LSBFIRST, B10101000);
   shiftOut(dataPin, clockPin, LSBFIRST, B11101111);
   shiftOut(dataPin, clockPin, LSBFIRST, B00101010);
   
      digitalWrite(latchPin, HIGH); delay(1);   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, B00101000);
   
   shiftOut(dataPin, clockPin, LSBFIRST, B11110111);
   shiftOut(dataPin, clockPin, LSBFIRST, B00101000);
   
      digitalWrite(latchPin, HIGH); delay(1);   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, B10001000); 
   
   shiftOut(dataPin, clockPin, LSBFIRST, B11111011);
   shiftOut(dataPin, clockPin, LSBFIRST, B00100010);
    
      digitalWrite(latchPin, HIGH); delay(1);   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, B10101000);
   
   shiftOut(dataPin, clockPin, LSBFIRST, B11111101);
   shiftOut(dataPin, clockPin, LSBFIRST, B00101010);
    
      digitalWrite(latchPin, HIGH); delay(1);   digitalWrite(latchPin, LOW);

   shiftOut(dataPin, clockPin, LSBFIRST, 0x00);
   shiftOut(dataPin, clockPin, LSBFIRST, B11111110);
   shiftOut(dataPin, clockPin, LSBFIRST, 0x00);
      
      digitalWrite(latchPin, HIGH); delay(1);
   
  }

int grabData(){
    if (WiFi.status() == WL_CONNECTED) // 와이파이가 접속되어 있는 경우
  {
    WiFiClient client; // 와이파이 클라이언트 객체
    HTTPClient http; // HTTP 클라이언트 객체

    if (http.begin(client, url)) {  // HTTP
      // 서버에 연결하고 HTTP 헤더 전송
      int httpCode = http.GET();

      // httpCode 가 음수라면 에러
      if (httpCode > 0) { // 에러가 없는 경우
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString(); // 받은 XML 데이터를 String에 저장
          
          /////////////////////////////////////////////////////////////////////////
          int start_point = payload.indexOf("<pm10Value>");
          int end_point = payload.indexOf("</pm10Value>");
          String pm10=payload.substring(start_point+11,end_point); //더하기11은 <pm10Value>글자수
          Serial.println("PM10 : " + pm10);
          int air = pm10.toInt();
          return air;
          ////////////////////////////////////////////////////////////////////////
        }
      } else {
        Serial.printf("[HTTP] GET... 실패, 에러코드: %s\n", http.errorToString(httpCode).c_str());
        return 0;
      }
      http.end();
    } else {
      Serial.printf("[HTTP] 접속 불가\n");
      return 0;
    }
  }
}

  unsigned long cur;
  unsigned long stt;


void setup() 
{
  // Set all the pins of 74HC595 as OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  
   leds = B1000000;

     // 시리얼 세팅
  Serial.begin(115200);
  Serial.println();

  // 와이파이 접속
  WiFi.begin("Bugil_3S", "bugil123!@#"); // 공유기 이름과 비밀번호

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) // 와이파이 접속하는 동안 "." 출력
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
   stt  = millis();
  data = grabData();


}

void loop()
{
   cur = millis();
  

 if(cur - stt > 30000){
  data = grabData();
  Serial.println(data);

  stt  = cur;
 }
 
  if(data <= 30) happy();
  if(data >= 31 && data <80) meh();
  if(data >=80 ) bad(); 


}

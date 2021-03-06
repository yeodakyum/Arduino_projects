#include <ESP8266WiFi.h> // ESP 8266 와이파이 라이브러리
#include <ESP8266HTTPClient.h> // HTTP 클라이언트


String url = "http://openapi.airkorea.or.kr/openapi/services/rest/ArpltnInforInqireSvc/getMsrstnAcctoRltmMesureDnsty?serviceKey=fRd4mNKHdXNcPf4o9YusPZi0ig%2F%2BHydGO1I2%2FfLp8%2Fm%2B6%2BXV4oDW5qjrSqBLydVoQKuz6n6eCPXh1GiQm8Xbdg%3D%3D&numOfRows=1&pageNo=1&stationName=%EC%84%9D%EB%B0%94%EC%9C%84&dataTerm=DAILY&ver=1.3";

void setup()
{
  // 시리얼 세팅
  Serial.begin(115200);
  Serial.println();

  // 와이파이 접속
  WiFi.begin("Iphone1", "yongbow12345"); // 공유기 이름과 비밀번호

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) // 와이파이 접속하는 동안 "." 출력
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
}

void loop() {
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
          ////////////////////////////////////////////////////////////////////////
        }
      } else {
        Serial.printf("[HTTP] GET... 실패, 에러코드: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();
    } else {
      Serial.printf("[HTTP] 접속 불가\n");
    }
    delay(600000);
  }
}

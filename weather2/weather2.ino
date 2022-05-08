#include <DHT.h>


#include <Wire.h>
#include <Adafruit_BMP085.h>
#include "LowPower.h"

#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif


RH_ASK driver(2000, 4, 5, 0); // ESP8266 or ESP32: do not use pin 11 or 2
//RH_ASK driver;

Adafruit_BMP085 bmp;

DHT dht(2, DHT11);

int battery;
int batt_volt;
void deep_sleep();
struct package
{
  float temperature ;
  float pressure ;
  float temperature2;
  float humidity;
  float batt;
};
typedef struct package Package;
Package data;

void setup() {

  Serial.begin(9600);
  Serial.print("hi");
  pinMode(5, OUTPUT); //battery cut
  dht.begin();
  if (!driver.init())
     Serial.println("radio init failed");
  if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP085 sensor, check wiring!");

   
  }

  analogReference(INTERNAL);
}
  
void loop() {

   
    data.batt = analogRead(A0) * 0.0061 ;    
    Serial.print("Temperature = ");
   Serial.print(bmp.readTemperature());
   Serial.println(" *C");
    
    data.temperature =  bmp.readTemperature();   
    Serial.print("dht Temperature = ");
    Serial.print(dht.readTemperature());
    Serial.println(" *C");
    
    data.temperature2 =  dht.readTemperature();
    /*
    erial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    
    */data.pressure = bmp.readPressure();
    
    /*Serial.print("Humidity = ");
    Serial.print(dht.readHumidity());
    Serial.println(" *%");
    */
    data.humidity = dht.readHumidity();
    /*
    Serial.println();
    Serial.print(1024.0 / batt_volt);
    Serial.println("Volt");

    Serial.println(data.temperature);
*/
    driver.send((uint8_t *)&data, sizeof(data));
    driver.waitPacketSent();
    
    
    delay(100);
    deep_sleep();
/*
    if(battery == 1){
        deep_sleep();
        deep_sleep();
        deep_sleep();
        deep_sleep();
    }
    else
        deep_sleep();
    */
}

void deep_sleep(){
  LowPower.powerDown(SLEEP_8S, ADC_OFF,BOD_OFF);
  //LowPower.powerDown(SLEEP_8S, ADC_OFF,BOD_OFF);
}

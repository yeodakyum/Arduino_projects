// ask_receiver.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to receive messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) receiver with an Rx-B1 module
// Tested on Arduino Mega, Duemilanova, Uno, Due, Teensy, ESP-12

#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif

RH_ASK driver;
// RH_ASK driver(2000, 4, 5, 0); // ESP8266 or ESP32: do not use pin 11 or 2
// RH_ASK driver(2000, 3, 4, 0); // ATTiny, RX on D3 (pin 2 on attiny85) TX on D4 (pin 3 on attiny85), 
struct package
{
  float temperature ;
  float pressure ;
  float temperature2;
  float humidity;
  int batt;
};
typedef struct package Package;
Package data;


void setup()
{
#ifdef RH_HAVE_SERIAL
    Serial.begin(9600);	  // Debugging only
#endif
    if (!driver.init())
#ifdef RH_HAVE_SERIAL
         Serial.println("init failed");
#else
	;
#endif
}

void loop()
{
    uint8_t buf[sizeof(data)];
    uint8_t buflen = sizeof(data);

    if (driver.recv(buf, &buflen)) // Non-blocking
    {
	int i;

	// Message with a good checksum received, dump it.
	//driver.printBuffer("Got:", buf, buflen);
          memcpy(&data, &buf, buflen);
          Serial.print("\nTemp:");
          Serial.print(data.temperature);
          Serial.print("\npressure:");
          Serial.print(data.pressure);
          Serial.print("\nTemp2:");
          Serial.print(data.temperature2);
          Serial.print("\nHumidity:");
          Serial.print(data.humidity);
          delay(1000);
    }


}

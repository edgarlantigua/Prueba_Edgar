#include <Arduino.h>
#include <SoftwareSerial.h>

#ifndef D5
#if defined(ESP8266)
#define D8 (15)
#define D5 (14)
#define D7 (13)
#define D6 (12)
#define RX (3)
#define TX (1)
#elif defined(ESP32)
#define D8 (5)
#define D5 (18)
#define D7 (23)
#define D6 (19)
// Los de Edgar
#define RX (7)
#define TX (8)
#endif
#endif

#ifdef ESP32
#define BAUD_RATE 9600
#else
#define BAUD_RATE 9600
#endif

SoftwareSerial testSerial;

void setup()
{
  Serial.begin(115200);
  testSerial.begin(BAUD_RATE, SWSERIAL_8N1, RX, TX, false);
}

void loop()
{
  Serial.println("Data from myport:");
  // while there is data coming in, read it
  // and send to the hardware serial port:
  while (testSerial.available() > 0) {
    char inByte = testSerial.read();
    Serial.write(inByte);
  }
  // blank line to separate data from the two ports:
  Serial.println();
}
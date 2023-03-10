#include <Arduino.h>
#include <SoftwareSerial.h>

#define TX 8
#define RX 7
#define config 
EspSoftwareSerial::UART myport;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial Conection Begining");
  myport.begin(9600, SERIAL_8N1, RX, TX, false);
  if (!myport)
  { // If the object did not initialize, then its configuration is invalid
    Serial.println("Invalid EspSoftwareSerial pin configuration, check config");
    while (1)
    { // Don't continue with invalid configuration
      delay(1000);
      myport.enableRx(false);
    }
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.println("Waiting for data");
  Recopilacion(&myport);
}

void Recopilacion(EspSoftwareSerial::UART *mp)
{
  float dato;
  mp->enableRx(true);
  // wait 1 second for the reply from EspSoftwareSerial if any
  delay(1000);
  if (mp->listen())
  {
    Serial.print("\nResult:");
    while (mp->listen())
    {
      dato = mp->read();
      Serial.println(dato);
    }
  }

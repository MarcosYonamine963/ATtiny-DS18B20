/* 
Sketch for Arduino IDE 
IDE version: 1.8.19
*/

/* 
Board: ATtiny85
Clock: Internal 16MHz

Flash using Arduino as ISP:
https://gist.github.com/MarcosYonamine963/b8ca19667ada640c18193f8fc0057c47

Author: Marcos Yonamine
https://github.com/MarcosYonamine963/ATtiny-DS18B20

v1.0.0
05/jan/2024
*/


#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>

// Serial comunication
#define RX PB2
#define TX PB3

#define ONE_WIRE_BUS PB0

SoftwareSerial Serial(RX, TX);


// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // Start serial communication for debugging purposes
  Serial.begin(9600);
  // Start up the library
  sensors.begin();
}

void loop(void){ 
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  
  Serial.print("Celsius temperature: ");
  // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  Serial.print(sensors.getTempCByIndex(0)); 
  Serial.print(" - Fahrenheit temperature: ");
  Serial.println(sensors.getTempFByIndex(0));
  delay(1000);
}

/* 
Sketch for Arduino IDE 
IDE version: 1.8.19
*/

/*   
Author: Marcos Yonamine
https://github.com/MarcosYonamine963/ATtiny-DS18B20

v2.0.0
29/jun/2024

Board: ATtiny85
Clock: Internal 8MHz

Flash using Arduino as ISP:
https://gist.github.com/MarcosYonamine963/b8ca19667ada640c18193f8fc0057c47

Dependencies:
OneWire.h (Paul Stoffregen)
DallasTemperature.h (Miles Burton)
TinyWireM.h (Adafruit)

https://github.com/platisd/ATtiny85-LCD-library (modified, files at project tree)

*/


/*
Changelogs:
V2.0.0: removed serial communication (to free memory)
        added I2C LCD 16x2 display
        
v1.0.0: initial version
*/

#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>

// LCD I2C Display libs
#include <TinyWireM.h>
#include <LiquidCrystal_attiny.h> // modified from source. Use mc_print(const char c[], uint8_t col, uint8_t line)

/*
I2C interface (LCD Display, PFC8574):
Must connect 4k7 pullup resistors
PB0: SDA
PB2: SCL

OneWire Interface
Must connect 1k pullup resistor
PB3: OneWire DS18B20

*/

#define ONE_WIRE_BUS PB3

LiquidCrystal_I2C lcd(0x27, 16, 2);


// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup(void)
{
  sensors.begin();

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.mc_print("Jiga One-Wire", 0, 0);
  delay(2000);
}


float tempta_val;

float get_tempta_val(void);
void print_tempta_val(float val);

void loop(void){ 
  lcd.mc_print("Jiga One-Wire", 0, 0);

  tempta_val = get_tempta_val();
  print_tempta_val(tempta_val);
 
  delay(10);

}

float get_tempta_val(void)
{
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  return sensors.getTempCByIndex(0);
}

void print_tempta_val(float val)
{
  char strBuffer[8];
  char strTempta[8];

  // sprintf dont work with float on arduino. Use dtostrf to convert float (double) to str.
  // https://stackoverflow.com/questions/27651012/arduino-sprintf-float-not-formatting
  // 5 is minimum width, 2 is precision.
  dtostrf(val, 5, 2, strTempta);
  sprintf(strBuffer, "%s C", strTempta);
  lcd.clear();
  lcd.mc_print(strBuffer, 0, 1);
}

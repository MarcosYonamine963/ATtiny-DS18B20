# ATtiny-DS18B20
Simple project to test DS18B20 temperature sensor.

### Hardware required:

* ATtiny85
* DS18B20
* Pullup Resistor 4.7k (for I2C and OneWire)
* Arduino for flash ATtiny
* 16x2 LCD Display
* PCF8574 I2C module for LCD

Connect one-wire bus with pullup to +5V.

Connect one-wire bus to DS18B20 pin 2, and ATtiny PB3.

Connect PCF8574 module to LCD pins.

Connect ATtiny I2C bus (PB0 and PB2) to PCF8574 I2C bus.

Connect the two pins of I2C bus with pullup resistors to +5V.

### Software required:

* Arduino IDE (v1.8.19) or VSCode (PlatformIO)

## DS18B20 pinout

![image](https://github.com/MarcosYonamine963/ATtiny-DS18B20/assets/92953755/e6e54af2-3839-41b0-a1f3-dfb47cef9ee9)

[DS18B20 datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/ds18b20.pdf)

[PFC8574 datasheet](https://www.ti.com/lit/ds/symlink/pcf8574.pdf)

## How to flash ATtiny

See my gist [ATtiny.md](https://gist.github.com/MarcosYonamine963/b8ca19667ada640c18193f8fc0057c47)


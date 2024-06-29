# ATtiny-DS18B20
Simple project to test DS18B20 temperature sensor.

### Hardware required:

* ATtiny85
* DS18B20
* Pullup Resistor 4.7k
* Arduino for flash ATtiny
* Universal serial TTL converter (ex: PL2303, CP2102, FT232RL)

Connect one-wire bus with pullup to +5V.

Connect one-wire bus to DS18B20 pin 2, and ATtiny PB0.

Connect TTL converter RX to ATtiny Tx (see sketch defines).

Connect TTL converter TX to ATtiny Rx (see sketch defines).

### Software required:

* Arduino IDE or VSCode (platformio)
* Any serial terminal (ex: HTerm, PuTTy)

## DS18B20 pinout

![image](https://github.com/MarcosYonamine963/ATtiny-DS18B20/assets/92953755/e6e54af2-3839-41b0-a1f3-dfb47cef9ee9)

[DS18B20 datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/ds18b20.pdf)

## How to flash ATtiny

See my gist [ATtiny.md](https://gist.github.com/MarcosYonamine963/b8ca19667ada640c18193f8fc0057c47)


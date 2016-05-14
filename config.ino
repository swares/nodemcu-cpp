//# Code for Configuration Parameters

// General Device Info
// Memory Lifetime
// Flash   10k Write Cycles
// EEPROM 100k Write Cycles
// Sram / Dram Unlimited
// +---------------------+----------------+-----------------------+------------------------+------------------------+
// |                     | Arduino UNO R3 |     Arduino Nano      |         ESP-12         |        ESP-12E         |
// +---------------------+----------------+-----------------------+------------------------+------------------------+
// | Power               | 5V             | 5V                    | 3,3V                   | 3,3V                   |
// | Io max              | 40mA           | 40mA                  | 12mA                   | 12mA                   |
// | Clock Frequency     | 16MHz          | 16MHz                 | 26-52MHz               | 26-52MHz               |
// | Microcontroller     | ATmega328      | ATmega168 / ATmega328 | ESP8266                | ESP8266                |
// | Flash Memory        | 32KB           | 16 KB / 32KB          | 512KB                  | 512KB                  |
// | SRAM                | 2 KB           | 1KB / 2 KB            | 64 KB SRAM / 96KB DRAM | 64 KB SRAM / 96KB DRAM |
// | EEPROM              | 1 KB           | 512 bytes / 1 KB      | 4M                      | ?                      |
// | USB                 | Yes            | Yes                   | No                     | No                     |
// | External Power Port | Yes            | No                    | No                     | No                     |
// | Reset Button        | Yes            | Yes                   | No                     | No                     |
// | Pins                | 32             | 30                    | 16                     | 22                     |
// | GPIO                | 14             | 14                    | 13 (9 Digital I/O)     | 16 (11 Digital I/O)    |
// | Analog I/O          | 6              | 8                     | 1                      | 1                      |
// | WiFi                | No             | No                    | Yes                    | Yes                    |
// | Temp Sensor         | No             | No                    | Yes                    | Yes                    |
// | UART                | 1              | 1                     | 1                      | 1                      |
// | PWM                 | 6              | 6                     | 9                      | 9                      |
// | FCC Approved        | Yes            | Yes                   | Yes                    | Yes                    |
// | SPI / I2C           | Yes            | Yes                   | Yes                    | Yes                    |
// | Price (Banggood)    | $ 4,10         | $ 3,20                | $ 3,80                 | $ 3,19                 |
// +---------------------+----------------+-----------------------+------------------------+------------------------+
// - See more at: http://www.esp8266.com/viewtopic.php?f=6&t=4348#sthash.59oBHYJ1.dpuf

//# turn on and off debugging
//#define DEVMODE;

//# logging - output all debugging output to sdcard
//#define output_sdcard_debug_log;

//# Enable Sensor Group
#define station01;
//#define station02;
//#define station03;
//#define station04;
#if defined(station01)
  #define enable_switches;
  #define enable_bmp180;
  #define enable_dht22;
  #define enable_as3935;
  #define enable_ds3231_at24c32;
#endif
#if defined(station02)
  #define enable_ds3231_at24c32;
#endif
#if defined(station03)
  #define enable_ds3231_at24c32
#endif
#if defined(station04)
  #define enable_ds3231_at24c32
#endif

//# sensor parameters below

// if defined load params for the BMP180 sensor
#if defined(enable_bmp180)
  #include <Wire.h>
  #include <Adafruit_Sensor.h>
  #include <Adafruit_BMP085_U.h>
#endif

// if defined load params for the DHT22 sensor
#if defined(enable_dht22)
  #include <stdio.h>
  // Data wire is plugged into port 7 on the Arduino
  // Connect a 4.7K resistor between VCC and the data pin (strong pullup)
  #define DHT22_PIN 7
#endif


// if defined load params for the as3935 lightning sensor
#if defined(enable_as3935)
  // The AS3935 communicates via SPI or I2C. 
  // This example uses the I2C interface via the I2C lib, not Wire lib

  // interrupt trigger global var        
  volatile int8_t AS3935_ISR_Trig = 0;

  // defines for hardware config
  #define SI_PIN               9
  #define IRQ_PIN              2        // digital pins 2 and 3 are available for interrupt capability
  #define AS3935_ADD           0x03     // x03 - standard PWF SEN-39001-R01 config
  #define AS3935_CAPACITANCE   72       // <-- SET THIS VALUE TO THE NUMBER LISTED ON YOUR BOARD 

  // defines for general chip settings
  #define AS3935_INDOORS       0
  #define AS3935_OUTDOORS      1
  #define AS3935_DIST_DIS      0
  #define AS3935_DIST_EN       1
#endif
// ------------------------------

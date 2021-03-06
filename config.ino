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

/*
The following table provides the most used C/C++ types to be used when programming low resource devices (but not only):
Datatypes 	                  Size in Bytes 	Values
boolean, bool 	                        1 	  true(1) or false(0)
char 	                                  1 	  ASCII character or signed value in the range [-128, 127]
unsigned char, byte, uint8_t 	          1 	  ASCII character or unsigned value in the range [0, 255]
int, short 	                            2 	  signed value in the range [-32768, 32767]
unsigned int, word, uint16_t 	          2 	  unsigned value in the range [0, 65535]
long 	                                  4 	  signed value in the range [2147483648, 2147483647]
unsigned long, uint32_t 	              4 	  unsigned value in the range [0, 4294967295]
float, double 	                        4 	  floating point value in the range [-3.4028235e+38, 3.4028235e+38]

NOTE: float and double are the same in this (Arduino) platform

use stack instead of heap whenever possible - stack memory is preferred because the memory is complete freed 
up when the function returns, and also the stack memory is fragmentation free. 
In this means using local variables and avoid using dynamic memory allocation (i.e., malloc, calloc and realloc calls).

when using strings is a must, then it is important to keep them as short as possible - remember, each single char takes
one byte of RAM (the entire 2KB RAM memory of an ATmega328p can be occupied by a string with a length of 2048 chars). 

*/

// base functions and outputs
//# turn on and off debugging
//#define DEVMODE;

//# logging - output all debugging output to sdcard
//#define output_sdcard_debug_log;

//# turn on and off output channels below
#define output_serial;
#if defined(output_serial);
  SERIAL0_BAUD=115200;
  Serial.begin(SERIAL0_BAUD);
#endif

//# turn on and off RTC below // to comment it to turn it off
#define enable_rtc;

//# turn on and off SD Card below // to comment it to turn it off
//#define enable_sdcard;

//# turn on and off WIFI client below // to comment it to turn it off
#define enable_client_wifi;
#if defined(enable_client_wifi);
  const int ESP8266_RETRY=500
  const int ESP8266_BAUD=115200;
  #ifndef LIB_ESP8266WiFi
    #define LIB_ESP8266WiFi
    #include <ESP8266WiFi.h>
  #endif
  const char* ssid     = "your-ssid";
  const char* ap_pass = "your-user";
  const char* ap_user = "your-password";

  //# turn on and off NTP client below // to comment it to turn it off
  #define enable_client_ntp;
  const char* ntpServerName = "time.nist.gov";
  const int NTP_PACKET_SIZE = 48; // NTP time stamp is in the first 48 bytes of the message
  const char* ntp_server = "10.136.151.102";
  unsigned int localPort = 2390;      // local port to listen for UDP packets
  #ifndef LIB_ESP8266WiFi
    #define LIB_ESP8266WiFi
    #include <ESP8266WiFi.h>
  #endif
  #ifndef LIB_WiFiUdp
    #define LIB_WiFiUdp
    #include <WiFiUdp.h>
  #endif

  //# turn on and off output channels below
  #define output_webserver;

  //# turn on and off output channels below
  #define output_mqtt;
  const char* mqtt_server = "broker.mqtt-dashboard.com";
  #ifndef LIB_ESP8266WiFi
    #define LIB_ESP8266WiFi
    #include <ESP8266WiFi.h>
  #endif
  #ifndef LIB_PubSubClient
    #define LIB_PubSubClient
    #include <PubSubClient.h>
  #endif
  // Define mqtt channels to use # 
  // TODO: finish adding ifdef statements below
  #if defined(enable_as3935)
    const char mqtt_chan_sensor_as3935[] PROGMEM = { "ems_sensor_as3935" };
  #endif
  #if defined(enable_bmp180)
    const char mqtt_chan_sensor_bmp180[] PROGMEM = { "ems_sensor_bmp180" };
  #endif
  #if defined(enable_dht22)
    const char mqtt_chan_sensor_dht22[] PROGMEM = { "ems_sensor_dht22" };
  #endif
  #if defined(enable_device_health)
    const char mqtt_chan_device_health[] PROGMEM = { "ems_device_health" };
  #endif
#endif

//# Enable Sensor Group
#define station01;
//#define station02;
//#define station03;
//#define station04;

//# Sensor Groups
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
  #ifndef LIB_Wire
    #define LIB_Wire
    #include <Wire.h>
  #endif
  #ifndef LIB_Adafruit_Sensor
    #define LIB_Adafruit_Sensor
    #include <Adafruit_Sensor.h>
  #endif
  #ifndef LIB_Adafruit_BMP085_U
    #define LIB_Adafruit_BMP085_U
    #include <Adafruit_BMP085_U.h>
  #endif
#endif

// if defined load params for the DHT22 sensor
#if defined(enable_dht22)
  #ifndef LIB_stdio
    #define LIB_stdio
    #include <stdio.h>
  #endif
  // Data wire is plugged into port 7 on the Arduino
  // Connect a 4.7K resistor between VCC and the data pin (strong pullup)
  #define DHT22_PIN 7
#endif

// if defined load params for the as3935 lightning sensor
#if defined(enable_as3935)
  // The AS3935 communicates via SPI or I2C. 
  // This example uses the I2C interface via the I2C lib, not Wire lib
  #ifndef LIB_I2C
    #define LIB_I2C
    #include "I2C.h"
  #endif
  #ifndef LIB_PWFusion_AS3935_I2C
    #define LIB_PWFusion_AS3935_I2C
    #include "PWFusion_AS3935_I2C.h"
  #endif

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

//#if defined(enable_)
//
//#endif

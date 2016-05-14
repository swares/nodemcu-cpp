# Code for Configuration Parameters

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

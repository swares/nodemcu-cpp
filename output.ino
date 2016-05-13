# File to determine outputs

# cfg move to config later

# turn on and off outputs
bool output_serial           = 1;
bool output_webserver        = 1;
bool output_mqtt             = 1;

# turn on and off debugging outputs
bool output_serial_debug     = 0;
bool output_webserver_debug  = 0;
bool output_mqtt_debug       = 0;

# logging - output all debugging output to sdcard
bool output_sdcard_debug_log = 0;


# Use Arduino AJAX Web Server with pages saved on sdcard or eeprom or program mem.
# - Javascript, AJAX, Images, Links, CSS.
# http://blog.startingelectronics.com/arduino-web-server-tutorial/

#  Space saving measures
# use conditional compilation
void setup(){
#if defined(DEVMODE)
    Serial.begin(115200);
    Serial.print("Devmode ON");
#else
  // Setup the LCD
    myGLCD.InitLCD();
#endif

# use strings in flash
Serial.println(F("Sram sram sram sram. Lovely sram! Wonderful sram! Sram sra-a-a-a-a-am sram sra-a-a-a-a-am sram. Lovely sram! Lovely sram! Lovely sram! Lovely sram! Lovely sram! Sram sram sram sram!"));

// save some unsigned ints
const PROGMEM  uint16_t charSet[]  = { 65000, 32796, 16843, 10, 11234};

// save some chars
const char signMessage[] PROGMEM  = {"I AM PREDATOR,  UNSEEN COMBATANT. CREATED BY THE UNITED STATES DEPART"};


# Trim down unneeded functions / code in libs

Flash   10k Write Cycles
EEPROM 100k Write Cycles
Sram / Dram Unlimited
+---------------------+----------------+-----------------------+------------------------+------------------------+
|                     | Arduino UNO R3 |     Arduino Nano      |         ESP-12         |        ESP-12E         |
+---------------------+----------------+-----------------------+------------------------+------------------------+
| Power               | 5V             | 5V                    | 3,3V                   | 3,3V                   |
| Io max              | 40mA           | 40mA                  | 12mA                   | 12mA                   |
| Clock Frequency     | 16MHz          | 16MHz                 | 26-52MHz               | 26-52MHz               |
| Microcontroller     | ATmega328      | ATmega168 / ATmega328 | ESP8266                | ESP8266                |
| Flash Memory        | 32KB           | 16 KB / 32KB          | 512KB                  | 512KB                  |
| SRAM                | 2 KB           | 1KB / 2 KB            | 64 KB SRAM / 96KB DRAM | 64 KB SRAM / 96KB DRAM |
| EEPROM              | 1 KB           | 512 bytes / 1 KB      | 4M                      | ?                      |
| USB                 | Yes            | Yes                   | No                     | No                     |
| External Power Port | Yes            | No                    | No                     | No                     |
| Reset Button        | Yes            | Yes                   | No                     | No                     |
| Pins                | 32             | 30                    | 16                     | 22                     |
| GPIO                | 14             | 14                    | 13 (9 Digital I/O)     | 16 (11 Digital I/O)    |
| Analog I/O          | 6              | 8                     | 1                      | 1                      |
| WiFi                | No             | No                    | Yes                    | Yes                    |
| Temp Sensor         | No             | No                    | Yes                    | Yes                    |
| UART                | 1              | 1                     | 1                      | 1                      |
| PWM                 | 6              | 6                     | 9                      | 9                      |
| FCC Approved        | Yes            | Yes                   | Yes                    | Yes                    |
| SPI / I2C           | Yes            | Yes                   | Yes                    | Yes                    |
| Price (Banggood)    | $ 4,10         | $ 3,20                | $ 3,80                 | $ 3,19                 |
+---------------------+----------------+-----------------------+------------------------+------------------------+
- See more at: http://www.esp8266.com/viewtopic.php?f=6&t=4348#sthash.59oBHYJ1.dpuf

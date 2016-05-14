//# File to determine inputs / outputs

//# turn on and off output channels
#define output_serial;
#define output_webserver;
#define output_mqtt;

// load web pages if output_webserver is defined
#if defined(output_webserver)
  // http headers
  const char web_http200[] PROGMEM  = { "HTTP/1.1 200 OK\nContent-Type: text/html\nConnection: keep-alive\n\n" };
  const char web_http404[] PROGMEM  = { "HTTP/1.1 404 Error\nContent-Type: text/html\nConnection: keep-alive\n\n" };
  // html index and error pages
  const char web_index[]   PROGMEM  = { "<!DOCTYPE html><html><head><title>Environmental Monitoring Station - Index</title><script>function GetSwitchState() {nocache = '&nocache=' + Math.random() * 1000000;var request = new XMLHttpRequest();request.onreadystatechange = function() {if (this.readyState == 4) {if (this.status == 200) {if (this.responseText != null) {document.getElementById('switch_txt'.innerHTML = this.responseText;}}}};request.open('GET', 'ajax_switch' + nocache, true);request.send(null);setTimeout('GetSwitchState()', 1000);}</script></head><body onload='GetSwitchState()'><h1>Environmental Monitoring Station</h1><p id='switch_txt'>Switch state: Not requested...</p></body></html>" };
  const char web_error[]   PROGMEM  = { "<!DOCTYPE html><html><head><title>Environmental Monitoring Station - Error</title></head><body><h1>Environmental Monitoring Station - Error</h1><p id='error_txt'>Some Error Occured</p></body></html>" };
  // load web pages if enable_switches is defined
  #if defined(enable_switches)
    const char web_index[]   PROGMEM  = { "<!DOCTYPE html><html><head><title>Environmental Monitoring Station - Switches</title><script>function GetSwitchState() {nocache = '&nocache=' + Math.random() * 1000000;var request = new XMLHttpRequest();request.onreadystatechange = function() {if (this.readyState == 4) {if (this.status == 200) {if (this.responseText != null) {document.getElementById('switch_txt'.innerHTML = this.responseText;}}}};request.open('GET', 'ajax_switch' + nocache, true);request.send(null);setTimeout('GetSwitchState()', 1000);}</script></head><body onload='GetSwitchState()'><h1>Environmental Monitoring Station - Switches</h1><p id='switch_txt'>Switch state: Not requested...</p></body></html>" };
  #endif
  // load web pages if enable_bmp180 is defined
  #if defined(enable_bmp180)
    const char web_bmp180[]  PROGMEM  = { "" };
  #endif
  // load web pages if enable_dht22 is defined
  #if defined(enable_dht22)
    const char web_dht22[]   PROGMEM  = { "" };
  #endif
  // load web pages if enable_as3935 is defined
  #if defined(enable_as3935)
    const char web_as3935[]  PROGMEM  = { "" };
  #endif
  // load web pages if enable_ds3231_at24c32 is defined
  #if defined(enable_ds3231_at24c32)
    const char web_ds3231_at24c32[] PROGMEM  = { "" };
  #endif
#endif

//# Use Arduino AJAX Web Server with pages saved on sdcard or eeprom or program mem.
//# - Javascript, AJAX, Images, Links, CSS.
//# http://blog.startingelectronics.com/arduino-web-server-tutorial/

//# use strings in flash
//Serial.println(F("Sram sram sram sram. Lovely sram! Wonderful sram! Sram sra-a-a-a-a-am sram sra-a-a-a-a-am sram. Lovely sram! Lovely sram! Lovely sram! Lovely sram! Lovely sram! Sram sram sram sram!"));

// save some unsigned ints
// const PROGMEM  uint16_t charSet[]  = { 65000, 32796, 16843, 10, 11234};

//# Trim down unneeded functions / code in libs

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

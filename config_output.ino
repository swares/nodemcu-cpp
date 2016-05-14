//# File to determine inputs / outputs

//# turn on and off output channels
#define output_serial;
#define output_webserver;
#define output_mqtt;

//# Use Arduino AJAX Web Server with pages saved on sdcard or eeprom or program mem.
//# - Javascript, AJAX, Images, Links, CSS.
//# htDS3231_AT24C32log.startingelectronics.com/arduino-web-server-tutorial/

// load serial messages if output_serial is defined
#if defined(output_serial)
  // serial headers
  const char serial_hearer[] PROGMEM  = { "Environmental Monitoring Station - Index" };
  const char serial_error[] PROGMEM  = { "Environmental Monitoring Station - Error" };
  // load serial messages if enable_bmp180 is defined
  #if defined(enable_bmp180)
    const char serial_bmp180_sensor[] PROGMEM  = { "Sensor:       " };
    const char serial_bmp180_driver[] PROGMEM  = { "Driver Ver:   " };
    const char serial_bmp180_uniqid[] PROGMEM  = { "Unique ID:    " };
    const char serial_bmp180_max_val_hpa[] PROGMEM  = { "Max Value hPa:    " };
    const char serial_bmp180_min_val_hpa[] PROGMEM  = { "Min Value - hPa:    " };
    const char serial_bmp180_res_hpa[] PROGMEM  = { "Resolution - hPa:" };   
    const char serial_bmp180_devider[] PROGMEM  = { "------------------------------------" };
    const char serial_bmp180_test[] PROGMEM  = { "Pressure Sensor Test" }; 
    const char serial_bmp180_pressure_hpa[] PROGMEM  = { "Pressure - hPa:    " };
    const char serial_bmp180_temp_c[] PROGMEM  = { "Temperature - C:" };
    const char serial_bmp180_altitude_m[] PROGMEM  = { "Altitude - m:    " }; 
    const char serial_bmp180_sensor_error[] PROGMEM  = { "Sensor error" };
    const char serial_bmp180_sensor_none[] PROGMEM  = { "Ooops, no BMP085 or BMP185 detected ... Check your wiring or I2C ADDR!" };
  #endif


#endif

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
    const char web_bmp180[]  PROGMEM  = { "<!DOCTYPE html><html><head><title>Environmental Monitoring Station - BMP180</title><script>function Get_BMP180_State() {nocache = '&nocache=' + Math.random() * 1000000;var request = new XMLHttpRequest();request.onreadystatechange = function() {if (this.readyState == 4) {if (this.status == 200) {if (this.responseText != null) {document.getElementById('bmp180_txt'.innerHTML = this.responseText;}}}};request.open('GET', 'ajax_switch' + nocache, true);request.send(null);setTimeout('Get_BMP180_State()', 1000);}</script></head><body onload='Get_BMP180_State()'><h1>Environmental Monitoring Station - BMP180</h1><p id='bmp180_txt'>State: Not requested...</p></body></html>" };
  #endif
  // load web pages if enable_dht22 is defined
  #if defined(enable_dht22)
    const char web_dht22[]   PROGMEM  = { "<!DOCTYPE html><html><head><title>Environmental Monitoring Station - DHT22</title><script>function Get_DHT22_State() {nocache = '&nocache=' + Math.random() * 1000000;var request = new XMLHttpRequest();request.onreadystatechange = function() {if (this.readyState == 4) {if (this.status == 200) {if (this.responseText != null) {document.getElementById('dht22_txt'.innerHTML = this.responseText;}}}};request.open('GET', 'ajax_switch' + nocache, true);request.send(null);setTimeout('Get_DHT22_State()', 1000);}</script></head><body onload='Get_DHT22_State()'><h1>Environmental Monitoring Station - DHT22</h1><p id='dht22_txt'>State: Not requested...</p></body></html>" };
  #endif
  // load web pages if enable_as3935 is defined
  #if defined(enable_as3935)
    const char web_as3935[]  PROGMEM  = { "<!DOCTYPE html><html><head><title>Environmental Monitoring Station - AS3935</title><script>function Get_AS3935_State() {nocache = '&nocache=' + Math.random() * 1000000;var request = new XMLHttpRequest();request.onreadystatechange = function() {if (this.readyState == 4) {if (this.status == 200) {if (this.responseText != null) {document.getElementById('as3935_txt'.innerHTML = this.responseText;}}}};request.open('GET', 'ajax_switch' + nocache, true);request.send(null);setTimeout('Get_AS3935_State()', 1000);}</script></head><body onload='Get_AS3935_State()'><h1>Environmental Monitoring Station - AS3935</h1><p id='as3935_txt'>State: Not requested...</p></body></html>" };
  #endif
  // load web pages if enable_ds3231_at24c32 is defined
  #if defined(enable_ds3231_at24c32)
    const char web_ds3231_at24c32[] PROGMEM  = { "<!DOCTYPE html><html><head><title>Environmental Monitoring Station - DS3231_AT24C32</title><script>function Get_DS3231_AT24C32_State() {nocache = '&nocache=' + Math.random() * 1000000;var request = new XMLHttpRequest();request.onreadystatechange = function() {if (this.readyState == 4) {if (this.status == 200) {if (this.responseText != null) {document.getElementById('ds3231_at24c32_txt'.innerHTML = this.responseText;}}}};request.open('GET', 'ajax_switch' + nocache, true);request.send(null);setTimeout('Get_DS3231_AT24C32_State()', 1000);}</script></head><body onload='Get_DS3231_AT24C32_State()'><h1>Environmental Monitoring Station - DS3231_AT24C32</h1><p id='ds3231_at24c32_txt'>State: Not requested...</p></body></html>" };
  #endif
#endif


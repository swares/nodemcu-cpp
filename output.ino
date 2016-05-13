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

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

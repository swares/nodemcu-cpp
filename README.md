# nodemcu-cpp
Test Iot - non lua version for nodemcu lua IoT board

        Name             : Environmental Monitor #1
        Location         : Front Porch
        Device           : Nodemcu
        Power Source     : Solar Pannel + LIon Battery Pack
        Power Level      : 3.3v.
        Power Components : Solar Pannel + LIon Battery Pack + AMS1117
        Sensing          : Air: Humidity, Temperature.  
                         : EMP: Lightning Range, Power.

        Name             : Environmental Monitor #2
        Location         : Garage Door, beside or above
        Device           : Ardunio Mega 2560
        Power Source     : Adapter from security lighting 120v / 5v Adapter
        Power Level      : 5v.
        Power Components : Plug Adapter for light fixture, Power Adapter for Arduino 5v
        Sensing          : Air: CO, Quality, Smog, Particulates.

        Config / Main
        -------------
        config.ino         Configuration Parameters
        init.ino           Main Code
        
        Networking
        ----------
        network_mqtt.ino   MQTT Client
        network_ntp.ino    NTP Client
        network_wifi.ino   WIFI Client
        
        Sensors
        -------
        sensor_bmp180.ino  Barometric Air Pressure, Air Temperature Sensor
        sensor_dht22.ino   Airborn Humidity, Air Temperature Sensor
        sensor_as3935.ino  Lightning Distance, Lightning Power

        Libraries
        ---------
        PWFusion_AS3935_I2C  http://www.playingwithfusion.com/include/getfile.php?fileid=7043
        

Layout

        Layout
        init.ino
        config.ino - config parameters and libs
        config_output.ino - output and output message definitions
        rtc_ds3231.ino - rtc
        sdcard.ino - (optional) sdcard logging
        sensor_...
        client_wifi.ino - wifi client
          client_ntp.ino - ntp client
          client_mqtt.ino - mqtt pubsubclient
          server_httpd.ino - httpd server
        
        Clients
        clients return 1 or higher on success (true), 0 on failure (false)
        
        Functions
        int connect_to_wifi()
        int get_time_ntp()
        int get_time_rtc()

        int sensor_bmp180_read()  // 
        int sensor_dht22_read()   // 
        int sensor_as3935_int()   // runs via intrerupt should be powered?

        int publish_mqtt()        // send in: a channel string, a message string
        int start_httpd()         // using wake on lan to awake to service clients when sleeping

        // check free memory on arduino
        extern unsigned int __bss_end;
        extern unsigned int __heap_start;
        extern void *__brkval;

        uint16_t getFreeSram() {
          uint8_t newVariable;
          // heap is empty, use bss as start memory address
          if ((uint16_t)__brkval == 0)
            return (((uint16_t)&newVariable) - ((uint16_t)&__bss_end));
          // use heap end as the start of the memory address
          else
            return (((uint16_t)&newVariable) - ((uint16_t)__brkval));
        };

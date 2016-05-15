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
        client_wifi.ino - wifi client
          client_ntp.ino - ntp client
          client_mqtt.ino - mqtt pubsubclient
          server_httpd.ino - httpd server
        

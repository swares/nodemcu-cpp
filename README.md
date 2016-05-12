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
        network_wifi.ino   WIFI Access
        
        Sensors
        -------
        sensor_bmp180.ino  Barometric Air Pressure, Air Temperature Sensor
        sensor_dht22.ino   Airborn Humidity, Air Temperature Sensor
        sensor_as3935.ino  Lightning Distance, Lightning Power

        Libraries
        ---------
        
        
        

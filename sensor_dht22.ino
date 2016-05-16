//# Code for the DHT22 Humidity / Temprature #include <DHT22.h>

// Setup a DHT22 instance
DHT22 myDHT22(DHT22_PIN);

void setup(void)
{
  #if defined(output_serial)
    Serial.println(serial_dht22_title);
  #endif
}

void loop(void)
{ 
  DHT22_ERROR_t errorCode;
  
  // The sensor can only be read from every 1-2s, and requires a minimum
  // 2s warm-up after power-on.
  delay(2000);
  
  #if defined(output_serial)
    Serial.print(serial_dht22_req_data);
  #endif
  errorCode = myDHT22.readData();
  switch(errorCode)
  {
    case DHT_ERROR_NONE:
      #if defined(output_serial)
        Serial.print(serial_dht22_got_data);
        Serial.print(myDHT22.getTemperatureC());
        Serial.print(serial_dht22_c);
        Serial.print(myDHT22.getHumidity());
        Serial.println(serial_dht22_percent);
      #endif
      // Alternately, with integer formatting which is clumsier but more compact to store and
	  // can be compared reliably for equality:
	  //	  
      char buf[128];
      sprintf(buf, "Integer-only reading: Temperature %hi.%01hi C, Humidity %i.%01i %% RH",
                   myDHT22.getTemperatureCInt()/10, abs(myDHT22.getTemperatureCInt()%10),
                   myDHT22.getHumidityInt()/10, myDHT22.getHumidityInt()%10);
      #if defined(output_serial)
        Serial.println(buf);
      #endif
      break;
    case DHT_ERROR_CHECKSUM:
      #if defined(output_serial)
        Serial.print(serial_dht22_sensor_checksum);
        Serial.print(myDHT22.getTemperatureC());
        Serial.print(serial_dht22_c);
        Serial.print(myDHT22.getHumidity());
        Serial.println(serial_dht22_percent);
      #endif
      break;
    case DHT_BUS_HUNG:
      #if defined(output_serial)
        Serial.println(serial_dht22_sensor_buss_hung);
      #endif
      break;
    case DHT_ERROR_NOT_PRESENT:
      #if defined(output_serial)
        Serial.println(serial_dht22_sensor_none);
      #endif
      break;
    case DHT_ERROR_ACK_TOO_LONG:
      #if defined(output_serial)
        Serial.println(serial_dht22_sensor_ack_timeout);
      #endif
      break;
    case DHT_ERROR_SYNC_TIMEOUT:
      #if defined(output_serial)
        Serial.println(serial_dht22_sensor_sync_timeout);
      #endif
      break;
    case DHT_ERROR_DATA_TIMEOUT:
      #if defined(output_serial)
        Serial.println(serial_dht22_sensor_data_timeout);
      #endif
      break;
    case DHT_ERROR_TOOQUICK:
      #if defined(output_serial)
        Serial.println(serial_dht22_sensor_poll_too_quick);
      #endif
      break;
  }
}

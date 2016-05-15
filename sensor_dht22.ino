//# Code for the DHT22 Humidity / Temprature #include <DHT22.h>

// Setup a DHT22 instance
DHT22 myDHT22(DHT22_PIN);

void setup(void)
{
  // start serial port
  Serial.println(serial_dht22_title);
}

void loop(void)
{ 
  DHT22_ERROR_t errorCode;
  
  // The sensor can only be read from every 1-2s, and requires a minimum
  // 2s warm-up after power-on.
  delay(2000);
  
  Serial.print(serial_dht22_req_data);
  errorCode = myDHT22.readData();
  switch(errorCode)
  {
    case DHT_ERROR_NONE:
      Serial.print(serial_dht22_got_data);
      Serial.print(myDHT22.getTemperatureC());
      Serial.print(serial_dht22_c);
      Serial.print(myDHT22.getHumidity());
      Serial.println(serial_dht22_percent);
      // Alternately, with integer formatting which is clumsier but more compact to store and
	  // can be compared reliably for equality:
	  //	  
      char buf[128];
      sprintf(buf, "Integer-only reading: Temperature %hi.%01hi C, Humidity %i.%01i %% RH",
                   myDHT22.getTemperatureCInt()/10, abs(myDHT22.getTemperatureCInt()%10),
                   myDHT22.getHumidityInt()/10, myDHT22.getHumidityInt()%10);
      Serial.println(buf);
      break;
    case DHT_ERROR_CHECKSUM:
      Serial.print(serial_dht22_sensor_checksum);
      Serial.print(myDHT22.getTemperatureC());
      Serial.print(serial_dht22_c);
      Serial.print(myDHT22.getHumidity());
      Serial.println(serial_dht22_percent);
      break;
    case DHT_BUS_HUNG:
      Serial.println(serial_dht22_sensor_buss_hung);
      break;
    case DHT_ERROR_NOT_PRESENT:
      Serial.println(serial_dht22_sensor_none);
      break;
    case DHT_ERROR_ACK_TOO_LONG:
      Serial.println(serial_dht22_sensor_ack_timeout);
      break;
    case DHT_ERROR_SYNC_TIMEOUT:
      Serial.println(serial_dht22_sensor_sync_timeout);
      break;
    case DHT_ERROR_DATA_TIMEOUT:
      Serial.println(serial_dht22_sensor_data_timeout);
      break;
    case DHT_ERROR_TOOQUICK:
      Serial.println(serial_dht22_sensor_poll_too_quick);
      break;
  }
}

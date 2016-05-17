//# Place holder for WIFI networking code

int connect_to_wifi() {
  // We start by connecting to a WiFi network
  #if defined(output_serial)  
    Serial.println();
    Serial.println();
    Serial.print(serial_wifi_title);
    Serial.println(ssid);
  #endif
  #if defined(output_mqtt)
//    client.print(serial_wifi_title);
//    client.println(ssid);
  #endif

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(ESP8266_RETRY);
    #if defined(output_serial)
      Serial.print(serial_wifi_waiting);
    #endif
    #if defined(output_mqtt)
//      client.print(serial_wifi_waiting);
    #endif
  }

  #if defined(output_serial)
    Serial.println("");
    Serial.println(serial_wifi_connected);  
    Serial.println(serial_wifi_ip_address);
    Serial.println(WiFi.localIP());
  #endif
  #if defined(output_mqtt)
//    client.println(serial_wifi_connected);  
//    client.println(serial_wifi_ip_address);
//    client.println(WiFi.localIP());
  #endif
  
  return 1;
}

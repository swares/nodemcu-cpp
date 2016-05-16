//# Place holder for WIFI networking code

private connect_to_ap() {
  // We start by connecting to a WiFi network
  #if defined(output_serial)  
    Serial.println();
    Serial.println();
    Serial.print(serial_wifi_title);
    Serial.println(ssid);
  #endif
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    #if defined(output_serial)
      Serial.print(serial_wifi_waiting);
    #endif
  }

  #if defined(output_serial)
    Serial.println("");
    Serial.println(serial_wifi_connected);  
    Serial.println(serial_wifi_ip_address);
    Serial.println(WiF
    i.localIP());
  #endif
  return WiFi.localIP()
}

void start(){
  connect_to_ap()  
//  myip = connect_to_ap()  
//  return myip
}

# Place holder for WIFI networking code

void setup() {
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
    Serial.println(WiFi.localIP());
  #endif
}

int value = 0;

void loop() {
  delay(5000);
  ++value;

  #if defined(output_serial)
    Serial.print(serial_wifi_connecting);
    Serial.println(host);
  #endif
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    #if defined(output_serial)
      Serial.println(serial_wifi_connection_failed);
    #endif
    return;
  }
  
  // We now create a URI for the request
  String url = "/input/";
  url += streamId;
  url += "?private_key=";
  url += privateKey;
  url += "&value=";
  url += value;
  
  #if defined(output_serial)
    Serial.print(serial_wifi_rerquesting_url0);
    Serial.println(url);
  #endif
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      #if defined(output_serial)
        Serial.println(serial_wifi_client_timeout);
      #endif
      client.stop();
      return;
    }
  }
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    #if defined(output_serial)
      Serial.print(line);
    #endif
  }
  
  #if defined(output_serial)
    Serial.println();
    Serial.println(serial_wifi_closing);
  #endif
}


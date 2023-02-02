
#include "AsyncTelnet.h"

AsyncTelnet Test(); // AsyncTelnet::AsyncTelnet(uint16_t port = 23);

// callback function when data is received by telnet
void data_cb_f(const char *data, size_t len){
  Serial.write(data,len);
}

// callback function when Telnet client is connected
void conn_cb_f(void*, AsyncClient* c){
  Serial.print("Client connected");
}

void setup() {
  // standard wifi connection
  WiFi.disconnect(true, true);
  delay(200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("ssid","password");
  if (WiFi.waitForConnectResult() != WL_CONNECTED) return;
  WiFi.setAutoReconnect(true);

  // attach callbacks first, before the begin function
  Test.onConnect(conn_cb_f);
  Test.onTelnetResponse(data_cb_f);
  Test.begin(); // AsyncTelnet::begin(bool checkConnection = true, bool mDNS = false);
}

void loop() {
}

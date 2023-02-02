
#include "AsyncTelnet.h"

AsyncTelnet Test();

void data_cb_f(const char *data, size_t len){
  Serial.write(data,len);
}
void conn_cb_f(void*, AsyncClient* c){
  Serial.print("Client connected");
}

void setup() {
  WiFi.disconnect(true, true);
  delay(200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("ssid","password");
  if (WiFi.waitForConnectResult() != WL_CONNECTED) return;
  WiFi.setAutoReconnect(true);

  Test.onConnect(conn_cb_f);
  Test.onTelnetResponse(data_cb_f);
  Test.begin(); // AsyncTelnet::begin(bool checkConnection = true, bool mDNS = false);
}

void loop() {
}

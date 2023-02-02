#pragma once
#ifndef AsyncTelnet_h
#define AsyncTelnet_h

#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#else
#error Platform not supported
#endif
#include <ESPmDNS.h>

typedef std::function<void(void*, AsyncClient*)> ConnHandler;
typedef std::function<void(AsyncClient*)> DisconnHandler;
typedef std::function<void(const char *data, size_t len)> ResponseHandler;

class AsyncTelnet {
  public:
    AsyncTelnet(uint16_t port = 23);

    bool begin(bool checkConnection = true, bool mDNS = false);
    void stop();

    size_t write(const char* data);
    size_t write(const char* data, size_t size, uint8_t apiflags=ASYNC_WRITE_FLAG_COPY);

    bool isClientConnected(AsyncClient *client);
    void disconnectClient();

    IPAddress getIP() const;
    IPAddress getLastAttemptIP() const;

    void onConnect(ConnHandler callbackFunc);
    void onDisconnect(DisconnHandler callbackFunc);
    void onTelnetResponse(ResponseHandler callbackFunc);

    protected:
      AsyncServer server;
      AsyncClient *client;
      boolean isConnected = false;
      IPAddress ip;
      uint16_t server_port = 23;

      ConnHandler on_connect = NULL;
      DisconnHandler on_disconnect = NULL;
      ResponseHandler on_data  = NULL;  
};

#endif
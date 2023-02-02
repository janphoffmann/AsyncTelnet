# AsyncTelnet
Async Telnet connection for ESP32 with Arduino IDE

This work is basically a rewrite of https://github.com/LennartHennigs/ESPTelnet

Being an Async library everything is done in callbacks, there is no need to call anything in the loop() function

# dependencies
- ESP32 Core - https://github.com/espressif/arduino-esp32/tree/master/cores/esp32
- WiFi       - https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFi
- ESPmDNS    - https://github.com/espressif/arduino-esp32/tree/master/libraries/ESPmDNS
- AsyncTCP   - https://github.com/me-no-dev/AsyncTCP

# usage
- include the library ->#include "AsyncTelnet.h"
- create an instance  ->AsyncTelnet TestInstance(port); // possilby define a port, default = 23
- declare the callbackfunctions you want -> void telnet_message(const char *data, size_t len){ ... }
- in Setup() function setup your WiFi as usual,
- - then attatch the callback functions to the declared instance -> TestInstance.onTelnetResponse(telnet_message);
- - then call the begin() function -> TestInstance.begin(checkConnection, mDNS); // checkconnection is default true, mDNS default false!
Thats it.

If you want to connect it to Serial, check out my AsyncTelnetSerial library that is derived from this.

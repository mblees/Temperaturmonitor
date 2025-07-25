#ifndef _OTA_H
#define _OTA_H

#include <Arduino.h>
#include "config.h"

#include <ArduinoOTA.h>

#if ENABLE_WIFI
  #include <WiFi.h>
  #include <SimpleMDNS.h>
  #include <WiFiUdp.h>
#endif

#if ENABLE_ETHERNET
  #include "_ethernet.h"
#endif

// based on https://github.com/earlephilhower/arduino-pico/discussions/2556

void init_ota(void);
void handle_ota(void);

#endif // _OTA_H

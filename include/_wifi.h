#ifndef _WIFI_H
#define _WIFI_H

#include <Arduino.h>
#include "config.h"
#include "WiFi.h"

void init_wifi(void);
void connect_wifi(void);
void scan_for_networks(void);

#endif // _WIFI_H
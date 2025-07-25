#ifndef _MAC_GEN_H
#define _MAC_GEN_H

#include <Arduino.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/flash.h"

void get_unique_id(uint8_t* id);
void get_unique_mac_adress(uint8_t* id, byte* mac_adress);

#endif // _MAC_GEN_H

#ifndef _ETHERNET_H
#define _ETHERNET_H

#include <Arduino.h>
#include <W5100lwIP.h>
#include "_mac_gen.h"

#define WIZNET_MISO 16
#define WIZNET_CS 17
#define WIZNET_SCLK 18
#define WIZNET_MOSI 19
#define WIZNET_RSTn 20
#define WIZNET_INT 21

static Wiznet5100lwIP eth(WIZNET_CS, SPI, WIZNET_INT);

void init_ethernet(const IPAddress static_ip);
void wait_for_ethernet();
uint8_t check_for_ethernet_link();
uint8_t check_for_ethernet_connection();

#endif // _ETHERNET_H

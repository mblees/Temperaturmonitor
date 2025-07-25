#ifndef _MQTT_H
#define _MQTT_H

#include <Arduino.h>
#include "config.h"

#include <PubSubClient.h>
#include <SPI.h>

#include "_ethernet.h"

// based on https://github.com/earlephilhower/arduino-pico/discussions/2556

static WiFiClient ethClient;
static PubSubClient client(ethClient);
static IPAddress mqtt_server(MQTT_IP_1, MQTT_IP_2, MQTT_IP_3, MQTT_IP_4);

void mqtt_loop();
void mqtt_subscribe(const char *topic);
void mqtt_publish(const char *topic, const char *message);
void mqtt_connect(void);
void mqtt_callback(char *topic, byte *payload, unsigned int length);
uint8_t is_mqtt_connected();
void wait_for_mqtt();

#endif // _MQTT_H

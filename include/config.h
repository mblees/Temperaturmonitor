#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

// Serial Configuration
#define SERIAL_BAUDRATE 115200
#define WAIT_FOR_SERIAL true

// MQTT Configuration
#define ENABLE_MQTT true
#define MQTT_IP_1 192 // IP address of the MQTT broker, separated by dots
#define MQTT_IP_2 168
#define MQTT_IP_3 29
#define MQTT_IP_4 108
const static String mqtt_client_name = "Type_of_the_Controller"; // W5100S-EVB-Pico, Pico2W, etc.

// Ethernet Configuration
#define ENABLE_ETHERNET false

// WIFI Configuration
#define ENABLE_WIFI true
#define WIFI_SSID "EmRoLab-ng" // Replace with your WiFi SSID
#define WIFI_PASSWORD "#HTWdS5307%_" // Replace with your WiFi password

// OTA Configuration
#define ENABLE_OTA true

// LED Configuration
#define LED_AMOUNT 30 
#define LED_DATA_PIN 8
#define LED_BRIGHTNESS 255  // maximum brightness can draw high current

// Servo Configuration
#define SERVO_DATA_PIN 9

#endif // CONFIG_H

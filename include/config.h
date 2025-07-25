#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

// Serial Configuration
#define SERIAL_BAUDRATE 115200
#define WAIT_FOR_SERIAL true

// Ethernet Configuration
#define ENABLE_ETHERNET false

// WIFI Configuration
#define ENABLE_WIFI true
#define WIFI_SSID "KGB" // Replace with your WiFi SSID
#define WIFI_PASSWORD "cLCXBX3hugb36tbD" // Replace with your WiFi password

// BME280 Sensor Configuration
#define BME280_ADRS 0x76 // Default I2C address for BME280
#define SDA_PIN 2
#define SCL_PIN 3

#endif // CONFIG_H
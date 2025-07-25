#ifndef _BME280_H
#define _BME280_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BME280.h>
#include "config.h"

class BME280Sensor {
public:
    BME280Sensor();
    bool begin(uint8_t address = 0x76);
    float getTemperature();
    float getHumidity();
    float getPressure();
    float getAltitude(float seaLevelhPa = 1013.25);

private:
    Adafruit_BME280 bme;
    bool initialized;
};

#endif // _BME280_H

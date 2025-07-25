#include "bme280.h"

BME280Sensor::BME280Sensor() : initialized(false) {}

bool BME280Sensor::begin(uint8_t address) {
    initialized = bme.begin(address);
    return initialized;
}

float BME280Sensor::getTemperature() {
    if (!initialized) return NAN;
    return bme.readTemperature();
}

float BME280Sensor::getHumidity() {
    if (!initialized) return NAN;
    return bme.readHumidity();
}

float BME280Sensor::getPressure() {
    if (!initialized) return NAN;
    return bme.readPressure();
}

float BME280Sensor::getAltitude(float seaLevelhPa) {
    if (!initialized) return NAN;
    return bme.readAltitude(seaLevelhPa);
}

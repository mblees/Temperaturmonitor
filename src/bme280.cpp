#include "bme280.h"

BME280Sensor::BME280Sensor() : initialized(false) {}

bool BME280Sensor::begin(uint8_t address) {
    Wire1.setSDA(SDA_PIN);
    Wire1.setSCL(SCL_PIN);
    Wire1.begin();
    initialized = bme.begin(address, &Wire1);
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


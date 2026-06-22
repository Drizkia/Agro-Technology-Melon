#include "WaterTempSensor.h"

WaterTempSensor::WaterTempSensor(uint8_t pin) {
    _pin = pin;
}

void WaterTempSensor::begin() {
    oneWire = new OneWire(_pin);

    sensors = new DallasTemperature(oneWire);

    sensors->begin();
}

float WaterTempSensor::getTemperature() {
    sensors->requestTemperatures();

    return sensors->getTempCByIndex(0);
}
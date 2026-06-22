#include "PHSensor.h"
#include <EEPROM.h>

PHSensor::PHSensor(uint8_t pin) {
    _pin = pin;
}

void PHSensor::begin() {
    EEPROM.begin(32);

    ph.begin();
}

float PHSensor::readPH() {
    const int samples = 20;

    uint32_t adcSum = 0;

    for (int i = 0; i < samples; i++) {
        adcSum += analogRead(_pin);
    }

    float adc = adcSum / (float)samples;

    float voltage = adc * 3300.0f / 4095.0f;

    float temperature = 25.0f;

    return ph.readPH(voltage, temperature);
}
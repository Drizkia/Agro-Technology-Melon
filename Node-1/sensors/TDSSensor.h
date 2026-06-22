#ifndef TDS_SENSOR_H
#define TDS_SENSOR_H

#include <Arduino.h>

class TDSSensor {
public:

    explicit TDSSensor(uint8_t pin);

    void begin();

    float readPPM(float waterTemp);

private:

    uint8_t _pin;
};

#endif
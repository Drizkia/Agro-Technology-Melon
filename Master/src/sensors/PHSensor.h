#ifndef PH_SENSOR_H
#define PH_SENSOR_H

#include <Arduino.h>
#include <DFRobot_PH.h>

class PHSensor {
public:

    explicit PHSensor(uint8_t pin);

    void begin();

    float readPH();

private:

    uint8_t _pin;

    DFRobot_PH ph;
};

#endif
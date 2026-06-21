#ifndef RELAY_MANAGER_H
#define RELAY_MANAGER_H

#include <Arduino.h>

enum RelayChannel {
    RELAY_WATER = 1,
    RELAY_NUTRIENT_A,
    RELAY_NUTRIENT_B,
    RELAY_IRRIGATION,
    RELAY_5,
    RELAY_6,
    RELAY_7,
    RELAY_8
};

class RelayManager {
public:

    void begin();

    void on(RelayChannel relay);

    void off(RelayChannel relay);

    void allOff();

private:

    uint8_t getPin(RelayChannel relay);
};

#endif
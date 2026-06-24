#ifndef RELAY_MANAGER_H
#define RELAY_MANAGER_H

#include <Arduino.h>

enum RelayChannel {
    RELAY_WATER = 1, //1
    RELAY_NUTRIENT_A, //2
    RELAY_NUTRIENT_B, //3
    RELAY_IRRIGATION, //4
    RELAY_MIXER, //5
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
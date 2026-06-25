#ifndef RELAY_MANAGER_H
#define RELAY_MANAGER_H

#include <Arduino.h>

enum RelayChannel {
    RELAY_SOLENOID_WATER = 1,
    RELAY_SOLENOID_A,
    RELAY_SOLENOID_B,
    RELAY_SOLENOID_IRRIG,
    RELAY_PUMP_WATER,
    RELAY_PUMP_A,
    RELAY_PUMP_B,
    RELAY_PUMP_MIX
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
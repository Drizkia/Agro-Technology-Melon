#ifndef RELAY_MANAGER_H
#define RELAY_MANAGER_H

#include <Arduino.h>

class RelayManager {
public:

    void begin();

    void on(uint8_t relayPin);

    void off(uint8_t relayPin);
};

#endif

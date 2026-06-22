#include "RelayManager.h"
#include "../config/PinConfig.h"

void RelayManager::begin() {
    pinMode(RELAY_1_PIN, OUTPUT);
    pinMode(RELAY_2_PIN, OUTPUT);
    pinMode(RELAY_3_PIN, OUTPUT);
    pinMode(RELAY_4_PIN, OUTPUT);
    pinMode(RELAY_5_PIN, OUTPUT);
    pinMode(RELAY_6_PIN, OUTPUT);
    pinMode(RELAY_7_PIN, OUTPUT);
    pinMode(RELAY_8_PIN, OUTPUT);

    allOff();
}

uint8_t RelayManager::getPin(RelayChannel relay) {
    switch(relay) {
        case RELAY_WATER:       return RELAY_1_PIN;
        case RELAY_NUTRIENT_A:  return RELAY_2_PIN;
        case RELAY_NUTRIENT_B:  return RELAY_3_PIN;
        case RELAY_IRRIGATION:  return RELAY_4_PIN;
        case RELAY_5:           return RELAY_5_PIN;
        case RELAY_6:           return RELAY_6_PIN;
        case RELAY_7:           return RELAY_7_PIN;
        case RELAY_8:           return RELAY_8_PIN;
    }

    return RELAY_1_PIN;
}

void RelayManager::on(RelayChannel relay) {
    digitalWrite(getPin(relay), LOW);
}

void RelayManager::off(RelayChannel relay) {
    digitalWrite(getPin(relay), HIGH);
}

void RelayManager::allOff() {
    off(RELAY_WATER);
    off(RELAY_NUTRIENT_A);
    off(RELAY_NUTRIENT_B);
    off(RELAY_IRRIGATION);
    off(RELAY_5);
    off(RELAY_6);
    off(RELAY_7);
    off(RELAY_8);
}
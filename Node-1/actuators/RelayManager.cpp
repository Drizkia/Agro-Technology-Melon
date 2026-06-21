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

    off(RELAY_1_PIN);
    off(RELAY_2_PIN);
    off(RELAY_3_PIN);
    off(RELAY_4_PIN);
    off(RELAY_5_PIN);
    off(RELAY_6_PIN);
    off(RELAY_7_PIN);
    off(RELAY_8_PIN);
}

void RelayManager::on(uint8_t relayPin) {
    digitalWrite(relayPin, LOW);
}

void RelayManager::off(uint8_t relayPin) {
    digitalWrite(relayPin, HIGH);
}
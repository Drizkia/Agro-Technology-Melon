#include "FlowMeter.h"

FlowMeter::FlowMeter(uint8_t pin) {
    _pin = pin;

    pulseCount = 0;

    lastCalcTime = millis();

    lastPulseCount = 0;
}

void FlowMeter::begin(void (*isr)()) {
    pinMode(_pin, INPUT_PULLUP);

    attachInterrupt(
        digitalPinToInterrupt(_pin),
        isr,
        RISING
    );
}

float FlowMeter::getVolumeLiter() {
    return pulseCount / PULSES_PER_LITER;
}

float FlowMeter::getFlowRate() {
    unsigned long currentTime = millis();

    float elapsed = (currentTime - lastCalcTime) / 1000.0f;

    if(elapsed <= 0)
        return 0;

    uint32_t pulses =
        pulseCount - lastPulseCount;

    lastPulseCount = pulseCount;

    lastCalcTime = currentTime;

    return (pulses / PULSES_PER_LITER)
           * (60.0f / elapsed);
}

void FlowMeter::reset() {
    pulseCount = 0;
}
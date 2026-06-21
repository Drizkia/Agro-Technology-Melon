#include "config/PinConfig.h"

#include "actuators/RelayManager.h"
#include "sensors/FlowMeter.h"

RelayManager relay;

// FLOW METERS
FlowMeter flowWater(FLOW_WATER_PIN);
FlowMeter flowA(FLOW_A_PIN);
FlowMeter flowB(FLOW_B_PIN);

// ISR
void IRAM_ATTR flowWaterISR() {
    flowWater.pulseCount++;
}

void IRAM_ATTR flowAISR() {
    flowA.pulseCount++;
}

void IRAM_ATTR flowBISR() {
    flowB.pulseCount++;
}

void setup() {
    Serial.begin(115200);

    relay.begin();

    flowWater.begin(flowWaterISR);
    flowA.begin(flowAISR);
    flowB.begin(flowBISR);

    Serial.println("System Ready");
}

void loop() {
    static unsigned long lastPrint = 0;

    if(millis() - lastPrint >= 1000) {
        lastPrint = millis();

        Serial.println("==========");

        Serial.print("Water Volume : ");
        Serial.println(
            flowWater.getVolumeLiter(),
            3
        );

        Serial.print("A Volume : ");
        Serial.println(
            flowA.getVolumeLiter(),
            3
        );

        Serial.print("B Volume : ");
        Serial.println(
            flowB.getVolumeLiter(),
            3
        );
    }
}
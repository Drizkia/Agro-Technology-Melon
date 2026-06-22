#include "config/PinConfig.h"

#include "actuators/RelayManager.h"
#include "sensors/FlowMeter.h"
#include "sensors/WaterLevel.h"
#include "sensors/WaterTempSensor.h"
#include "rtc/RTCManager.h"

RelayManager relay;

// FLOW METERS
FlowMeter flowWater(FLOW_WATER_PIN);
FlowMeter flowA(FLOW_A_PIN);
FlowMeter flowB(FLOW_B_PIN);

// Water Level
WaterLevel waterLevel(
    ULTRASONIC_TRIG,
    ULTRASONIC_ECHO
);

// Water Temperature
WaterTempSensor waterTemp(
    DS18B20_PIN
);

RTCManager rtcManager;

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

    waterLevel.begin();

    Wire.begin(
        I2C_SDA_PIN,
        I2C_SCL_PIN
    );

    waterTemp.begin();

    rtcManager.begin();

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

    Serial.print("Level : ");
    Serial.print(
        waterLevel.getLevelPercent()
    );
    Serial.println("%");

    if(millis() - lastPrint >= 3000) {
        lastPrint = millis();

        Serial.println();

        Serial.println("==== SYSTEM ====");

        Serial.print("Water Temp : ");
        Serial.print(
            waterTemp.getTemperature()
        );
        Serial.println(" C");

        Serial.print("Plant Age : ");
        Serial.print(
            rtcManager.getPlantAgeDays()
        );
        Serial.println(" days");
    }
}
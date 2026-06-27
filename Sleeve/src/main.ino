#include "config/PinConfig.h"
#include "sensor/SoilSensor.h"
#include "communication/ESPNowSender.h"

constexpr unsigned long SEND_INTERVAL_MS = 1000UL; // <Konfigurasi : Ubah interval (ms) jeda pengiriman data dari Sleeve ke Master>

SoilSensor    soilSensor(
    SOIL_SENSOR_1_PIN,
    SOIL_SENSOR_2_PIN,
    SOIL_SENSOR_3_PIN,
    SOIL_SENSOR_4_PIN
);

ESPNowSender  espNow;

unsigned long lastSendTime = 0;

void setup() {
    Serial.begin(115200);

    soilSensor.begin();

    if (!espNow.begin()) {
        Serial.println("[Main] ESP-NOW init failed. Halting.");
        while (true) { delay(1000); }
    }

    Serial.println("[Main] Sleeve ready.");
}

void loop() {
    soilSensor.update();

    unsigned long now = millis();

    if (now - lastSendTime >= SEND_INTERVAL_MS) {
        lastSendTime = now;

        SoilData data = soilSensor.getData();

        bool sent = espNow.send(data);

        Serial.printf(
            "[Soil] S1:%4u S2:%4u S3:%4u S4:%4u Avg:%4u | Send:%s\n",
            data.sensor1,
            data.sensor2,
            data.sensor3,
            data.sensor4,
            data.averageRawADC,
            sent ? "OK" : "FAIL"
        );
    }
}

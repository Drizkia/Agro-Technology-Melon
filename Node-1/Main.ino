#include "actuators/RelayManager.h"
#include "communication/ESPNowManager.h"
#include "fsm/FertigationFSM.h"

RelayManager relayManager;
ESPNowManager espNowManager;
FertigationFSM fertigationFSM;

void setup() {
    Serial.begin(115200);

    relayManager.begin();

    espNowManager.begin();

    fertigationFSM.begin();
}

void loop() {
    fertigationFSM.update();

    if(espNowManager.hasNewData())
    {
        SoilData soil =
            espNowManager.getSoilData();

        Serial.print("Moisture: ");
        Serial.println(soil.moistureAvg);
    }
}
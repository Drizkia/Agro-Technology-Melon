#include "ESPNowManager.h"

SoilData ESPNowManager::receivedData;
volatile bool ESPNowManager::newDataFlag = false;

void ESPNowManager::begin() {
    WiFi.mode(WIFI_STA);

    esp_now_init();

    esp_now_register_recv_cb(onDataRecv);
}

void ESPNowManager::onDataRecv(
    const esp_now_recv_info_t *info,
    const uint8_t *incomingData,
    int len)
{
    memcpy(
        &receivedData,
        incomingData,
        sizeof(SoilData)
    );

    newDataFlag = true;
}

bool ESPNowManager::hasNewData() {
    return newDataFlag;
}

SoilData ESPNowManager::getSoilData() {
    newDataFlag = false;

    return receivedData;
}
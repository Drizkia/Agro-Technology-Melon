#ifndef ESPNOW_MANAGER_H
#define ESPNOW_MANAGER_H

#include <esp_now.h>
#include <WiFi.h>

#include "SoilData.h"

class ESPNowManager {
public:

    void begin();

    bool hasNewData();

    SoilData getSoilData();

private:

    static SoilData receivedData;

    static volatile bool newDataFlag;

    static void onDataRecv(
        const esp_now_recv_info_t *info,
        const uint8_t *incomingData,
        int len
    );
};

#endif
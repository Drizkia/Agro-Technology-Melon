#include "RTCManager.h"

void RTCManager::begin() {
    rtc.begin();

    if(!rtc.initialized())
    {
        Serial.println(
            "RTC NOT DETECTED"
        );
    }
}

DateTime RTCManager::now() {
    return rtc.now();
}

uint16_t RTCManager::getPlantAgeDays() {
    DateTime currentDate =
        rtc.now();

    TimeSpan age =
        currentDate - plantingDate;

    return age.days();
}
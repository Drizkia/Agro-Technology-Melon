#include "RTCManager.h"

void RTCManager::begin() {
    rtc.begin();

    if(!rtc.begin()) {
        Serial.println("RTC Error");

        while(true);
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
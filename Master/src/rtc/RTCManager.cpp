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
    DateTime currentDate = rtc.now();

    TimeSpan age = currentDate - plantingDate;

    return age.days();
}

uint8_t RTCManager::getDay() {
    return rtc.now().day();
}

uint8_t RTCManager::getMonth() {
    return rtc.now().month();
}

uint16_t RTCManager::getYear() {
    return rtc.now().year();
}

uint8_t RTCManager::getHour() {
    DateTime now = rtc.now();

    return now.hour();
}

uint8_t RTCManager::getMinute() {
    DateTime now = rtc.now();

    return now.minute();
}
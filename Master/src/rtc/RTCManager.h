#ifndef RTC_MANAGER_H
#define RTC_MANAGER_H

#include <Arduino.h>
#include <RTClib.h>

class RTCManager {
public:

    void begin();

    DateTime now();

    uint16_t getPlantAgeDays();

private:

    RTC_PCF8563 rtc;

    DateTime plantingDate =
        DateTime(2026, 6, 1, 0, 0, 0);
};

#endif
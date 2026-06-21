#ifndef SOIL_DATA_H
#define SOIL_DATA_H

#include <Arduino.h>

struct SoilData {
    float moistureAvg;

    bool isDry;

    uint32_t timestamp;
};

#endif
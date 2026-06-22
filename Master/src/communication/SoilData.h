#ifndef SOIL_DATA_H
#define SOIL_DATA_H

#include <stdint.h>

struct SoilData {
    float moisture1;
    float moisture2;
    float moisture3;
    float moisture4;

    float averageMoisture;

    bool isDry;

    unsigned long timestamp;
};

#endif
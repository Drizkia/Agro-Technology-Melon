#ifndef SOIL_DATA_H
#define SOIL_DATA_H

#include <stdint.h>

struct SoilData {
    uint16_t sensor1;        // Raw ADC sensor 1
    uint16_t sensor2;        // Raw ADC sensor 2
    uint16_t sensor3;        // Raw ADC sensor 3
    uint16_t sensor4;        // Raw ADC sensor 4

    uint16_t averageRawADC;  // Rata-rata dari 4 sensor (setelah filter)
};

#endif

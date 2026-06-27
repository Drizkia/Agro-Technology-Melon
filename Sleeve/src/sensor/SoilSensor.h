#ifndef SOIL_SENSOR_H
#define SOIL_SENSOR_H

#include <Arduino.h>

#include "../communication/SoilData.h"
#include "../utils/MovingAverage.h"
#include "../utils/MedianFilter.h"

// Window moving average per sensor
constexpr uint8_t MA_WINDOW = 10; // <Konfigurasi : Ubah jumlah sampel moving average untuk kehalusan data per sensor>

// Window median filter (saat sampling ADC)
constexpr uint8_t MEDIAN_WINDOW = 7; // <Konfigurasi : Ubah jumlah sampel median filter (harus ganjil) untuk buang noise mendadak/spike>

class SoilSensor {
public:
    SoilSensor(
        uint8_t pin1,
        uint8_t pin2,
        uint8_t pin3,
        uint8_t pin4
    );

    void begin();

    // Baca semua sensor, perbarui filter, dan perbarui data internal
    void update();

    // Kembalikan SoilData terkini
    SoilData getData() const;

private:
    uint8_t _pins[4];

    MovingAverage<uint16_t, MA_WINDOW> _ma[4];
    MedianFilter<MEDIAN_WINDOW>        _median;

    SoilData _data;
};

#endif

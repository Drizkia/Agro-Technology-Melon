#ifndef MEDIAN_FILTER_H
#define MEDIAN_FILTER_H

#include <Arduino.h>

template <uint8_t N>
class MedianFilter {
public:
    // Ambil N sampel dari pin ADC, kembalikan nilai median
    uint16_t sample(uint8_t pin) {
        uint16_t buf[N];

        for (uint8_t i = 0; i < N; i++) {
            buf[i] = (uint16_t)analogRead(pin);
        }

        // Insertion sort (N kecil, efisien di embedded)
        for (uint8_t i = 1; i < N; i++) {
            uint16_t key = buf[i];
            int8_t j = i - 1;
            while (j >= 0 && buf[j] > key) {
                buf[j + 1] = buf[j];
                j--;
            }
            buf[j + 1] = key;
        }

        return buf[N / 2];
    }
};

#endif

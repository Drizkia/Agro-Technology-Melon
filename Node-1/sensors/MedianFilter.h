#ifndef MEDIAN_FILTER_H
#define MEDIAN_FILTER_H

#include <Arduino.h>

template<typename T, size_t N>
class MedianFilter {
public:

    T process(T value) {
        buffer[index] = value;

        index++;

        if(index >= N) index = 0;

        T sorted[N];

        memcpy(sorted, buffer, sizeof(buffer));

        for (size_t i = 0; i < N - 1; i++) {
            for (size_t j = i + 1; j < N; j++) {
                if (sorted[i] > sorted[j]) {
                    T temp = sorted[i];
                    sorted[i] = sorted[j];
                    sorted[j] = temp;
                }
            }
        }

        return sorted[N / 2];
    }

private:
    T buffer[N] = {};

    size_t index = 0;
};

#endif
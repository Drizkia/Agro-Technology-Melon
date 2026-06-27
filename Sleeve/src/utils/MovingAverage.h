#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H

#include <Arduino.h>

template <typename T, uint8_t N>
class MovingAverage {
public:
    MovingAverage() : _index(0), _count(0), _sum(0) {
        for (uint8_t i = 0; i < N; i++) {
            _buf[i] = 0;
        }
    }

    void add(T value) {
        _sum -= _buf[_index];
        _buf[_index] = value;
        _sum += value;
        _index = (_index + 1) % N;
        if (_count < N) _count++;
    }

    T get() const {
        if (_count == 0) return 0;
        return (T)(_sum / _count);
    }

    void reset() {
        _index = 0;
        _count = 0;
        _sum   = 0;
        for (uint8_t i = 0; i < N; i++) {
            _buf[i] = 0;
        }
    }

private:
    T       _buf[N];
    uint8_t _index;
    uint8_t _count;
    long    _sum;
};

#endif

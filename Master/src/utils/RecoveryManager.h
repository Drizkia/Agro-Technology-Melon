#ifndef RECOVERY_MANAGER_H
#define RECOVERY_MANAGER_H

#include <Preferences.h>

struct RecoveryData {
    uint8_t state;

    uint32_t waterPulse;
    uint32_t nutrientAPulse;
    uint32_t nutrientBPulse;

    uint8_t day;
    uint8_t month;
    uint16_t year;

    bool batchRunning;
};

class RecoveryManager {
public:
    void begin();

    void save(const RecoveryData& data);

    RecoveryData load();

    void clear();

private:
    Preferences prefs;
};

#endif
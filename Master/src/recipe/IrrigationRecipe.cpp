#include "IrrigationRecipe.h"

IrrigationConfig IrrigationRecipe::getRecipe(uint16_t ageDays) {
    IrrigationConfig config;

    if (ageDays <= 7) {
        config.dryThreshold = 0;
    } else if (ageDays <= 20) {
        config.dryThreshold = 0;
    } else if (ageDays <= 58) {
        config.dryThreshold = 0;
    } else if (ageDays <= 70) {
        config.dryThreshold = 0;
    }

    return config;
}
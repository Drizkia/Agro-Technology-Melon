#ifndef SECRET_RECIPE_H
#define SECRET_RECIPE_H

#include <stdint.h>

const float DEFAULT_MIN_PH = 0;
const float DEFAULT_MAX_PH = 0;
const uint16_t DEFAULT_PPM = 0;

struct RecipeStage {
    uint16_t maxAgeDays;
    uint16_t targetPPM;
};

const RecipeStage RECIPE_STAGES[] = {
    // day , PPM
    {10, 800},
    {20, 1000},
    {30, 1200}
};

const int NUM_STAGES = sizeof(RECIPE_STAGES) / sizeof(RECIPE_STAGES[0]);

#endif
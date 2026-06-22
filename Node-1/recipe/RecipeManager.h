#ifndef RECIPE_MANAGER_H
#define RECIPE_MANAGER_H

#include <Arduino.h>

struct NutrientRecipe {
    float targetPPM;
    float targetMinPH;
    float targetMaxPH;
};

class RecipeManager {
public:

    NutrientRecipe getRecipe(
        uint16_t ageDays
    );
};

#endif
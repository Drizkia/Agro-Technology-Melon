#include "FertigationFSM.h"
#include "../config/Constants.h"

FertigationFSM::FertigationFSM(
    SensorManager& sensors,
    RelayManager& relays,
    RTCManager& rtc,
    RecipeManager& recipe,
    IrrigationRecipe& irrigation
)
:
sensorManager(sensors),
relayManager(relays),
rtcManager(rtc),
recipeManager(recipe),
irrigationRecipe(irrigation) {
    state = FertigationState::IDLE;
    stateStartTime = 0;
}

// Begin
void FertigationFSM::begin() {
    changeState(
        FertigationState::WAIT_DAILY_MIX
    );
}

// Update
void FertigationFSM::update() {
    sensorManager.update();

    sensor =
        sensorManager.getData();

    switch(state) {
        case FertigationState::IDLE:
            handleIdle();
            break;

        case FertigationState::WAIT_DAILY_MIX:
            handleWaitDailyMix();
            break;

        case FertigationState::PREPARE_DAILY_MIX:
            handlePrepareDailyMix();
            break;

        case FertigationState::FILL_WATER:
            handleFillWater();
            break;

        case FertigationState::ADD_NUTRIENT_A:
            handleAddNutrientA();
            break;

        case FertigationState::MIX_A:
            handleMixA();
            break;

        case FertigationState::ADD_NUTRIENT_B:
            handleAddNutrientB();
            break;

        case FertigationState::MIX_B:
            handleMixB();
            break;

        case FertigationState::VALIDATE:
            handleValidate();
            break;

        case FertigationState::CORRECT_PPM:
            handleCorrectPPM();
            break;

        case FertigationState::READY:
            handleReady();
            break;

        case FertigationState::IRRIGATION:
            handleIrrigation();
            break;

        case FertigationState::ERROR:
            handleError();
            break;
    }
}

// ChangeState
void FertigationFSM::changeState(FertigationState newState) {
    state = newState;

    stateStartTime =
        millis();
}

// GetState
FertigationState
FertigationFSM::getState() const {
    return state;
}

void FertigationFSM::handleIdle() {}
void FertigationFSM::handleWaitDailyMix(){}
void FertigationFSM::handlePrepareDailyMix(){}

void FertigationFSM::handleFillWater(){}
void FertigationFSM::handleAddNutrientA(){}
void FertigationFSM::handleMixA(){}
void FertigationFSM::handleAddNutrientB(){}
void FertigationFSM::handleMixB(){}
void FertigationFSM::handleValidate(){}
void FertigationFSM::handleCorrectPPM(){}
void FertigationFSM::handleReady(){}
void FertigationFSM::handleIrrigation(){}

void FertigationFSM::handleError(){}
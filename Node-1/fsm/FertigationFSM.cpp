#include "FertigationFSM.h"

void FertigationFSM::begin() {
    currentState = CHECK_VOLUME;
}

void FertigationFSM::update() {
    switch(currentState) {
        case CHECK_VOLUME:
            break;

        case FILL_WATER:
            break;

        case DOSING_A:
            break;

        case DOSING_B:
            break;

        case CHECK_PH_TDS:
            break;

        case READY:
            break;

        case IRRIGATION:
            break;
    }
}
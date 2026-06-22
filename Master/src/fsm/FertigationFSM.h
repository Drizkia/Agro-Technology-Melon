#ifndef FERTIGATION_FSM_H
#define FERTIGATION_FSM_H

class FertigationFSM {
public:

    enum State
    {
        CHECK_VOLUME,
        FILL_WATER,
        DOSING_A,
        DOSING_B,
        CHECK_PH_TDS,
        READY,
        IRRIGATION
    };

    void begin();

    void update();

private:

    State currentState;
};

#endif
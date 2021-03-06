#ifndef SUBJECT_LIGHTLATCH_H
#define SUBJECT_LIGHTLATCH_H

#include "subject.base.h"


class LightLatchSubject : public BaseSubject,
                          public Runnable
{
public:

    enum LIGHTLEVEL
    {
        DARK,
        DIM,
        BRIGHT
    };

    static LightLatchSubject *create(AnalogPinReader *pin);

    void run(void);

    LIGHTLEVEL getState(void);


private:

    LightLatchSubject(AnalogPinReader *pin);

    const int MAX_DARK  = 100;
    const int MAX_DIM   = 1000;

    AnalogPinReader *_pin;
    LIGHTLEVEL _state;
    LIGHTLEVEL _lastState;

    bool changeStateToDark(int value);
    bool changeStateToDim(int value);
    bool changeStateToBright(int value);

    void setState(LIGHTLEVEL state);

};


#endif

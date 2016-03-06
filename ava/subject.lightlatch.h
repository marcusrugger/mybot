#ifndef SUBJECT_LIGHTLATCH_H
#define SUBJECT_LIGHTLATCH_H

#include "subject.h"


class LightLatchSubject : public BaseSubject,
                          public Tickable
{
public:

    enum LIGHTLEVEL
    {
        DARK,
        DIM,
        BRIGHT
    };

    static LightLatchSubject *create(AnalogPinReader *pin);

    void tick(void);

    LIGHTLEVEL getState(void);


private:

    LightLatchSubject(AnalogPinReader *pin);

    AnalogPinReader *_pin;

};


#endif

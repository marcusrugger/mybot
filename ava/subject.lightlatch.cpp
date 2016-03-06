#include "subject.lightlatch.h"


LightLatchSubject *LightLatchSubject::create(AnalogPinReader *pin)
{
    return new LightLatchSubject(pin);
}


LightLatchSubject::LightLatchSubject(AnalogPinReader *pin)
:   _pin(pin)
{}


void LightLatchSubject::tick(void)
{}


LightLatchSubject::LIGHTLEVEL LightLatchSubject::getState(void)
{
    return DARK;
}

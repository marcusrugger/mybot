#include "subject.lightlatch.h"


LightLatchSubject *LightLatchSubject::create(AnalogPinReader *pin)
{
    return new LightLatchSubject(pin);
}


LightLatchSubject::LightLatchSubject(AnalogPinReader *pin)
:   _pin(pin)
{}


void LightLatchSubject::tick(void)
{
    int value = _pin->readPin();

    // Serial.print("LatchLightSubject::tick: value: ");
    // Serial.println(value);

    if      (changeStateToDark(value))   setState(DARK);
    else if (changeStateToDim(value))    setState(DIM);
    else if (changeStateToBright(value)) setState(BRIGHT);
}


LightLatchSubject::LIGHTLEVEL LightLatchSubject::getState(void)
{
    return _state;
}


bool LightLatchSubject::changeStateToDark(int value)
{
    return _state != DARK && value <= MAX_DARK;
}


bool LightLatchSubject::changeStateToDim(int value)
{
    return _state != DIM && value > MAX_DARK && value <= MAX_DIM;
}


bool LightLatchSubject::changeStateToBright(int value)
{
    return _state != BRIGHT && value > MAX_DIM;
}


void LightLatchSubject::setState(LIGHTLEVEL state)
{
    _lastState = _state;
    _state = state;
    notify();
}

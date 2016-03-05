#include "ultrasonic.h"


MBotUltrasonicSubject *MBotUltrasonicSubject::_instance;


MBotUltrasonicSubject *MBotUltrasonicSubject::instance(DigitalPin *pin)
{
    if (NULL == _instance)
        _instance = new MBotUltrasonicSubject(pin);

    return _instance;
}


MBotUltrasonicSubject::MBotUltrasonicSubject(DigitalPin *pin)
:   _pin(pin)
{}


void MBotUltrasonicSubject::tick(void)
{
    const int DISTANCE_BLOCKED  = 100;
    const int DISTANCE_FAR      = 1000;
    long d = distance();

    // Serial.print("MBotUltrasonicSubject::tick: distance: ");
    // Serial.println(d);

    if (d > 0 && d < DISTANCE_BLOCKED && _state != BLOCKED)
    {
        changeStateToBlocked();
    }
    else if (d >= DISTANCE_BLOCKED  && d < DISTANCE_FAR && _state != NEAR)
    {
        changeStateToNear();
    }
    else if ((d == 0 || d >= DISTANCE_FAR) && _state != FAR)
    {
        changeStateToFar();
    }
}


void MBotUltrasonicSubject::changeStateToBlocked(void)
{
    _isBlocked = true;
    _lastState = _state;
    _state = BLOCKED;
    notify();
}


void MBotUltrasonicSubject::changeStateToNear(void)
{
    _isBlocked = false;
    _lastState = _state;
    _state = NEAR;
    notify();
}


void MBotUltrasonicSubject::changeStateToFar(void)
{
    _isBlocked = false;
    _lastState = _state;
    _state = FAR;
    notify();
}


long MBotUltrasonicSubject::distance(void)
{
    return readSensor(22200) / 6;
}


long MBotUltrasonicSubject::readSensor(unsigned long timeout)
{
    _pin->setLow();     delayMicroseconds(2);
    _pin->setHigh();    delayMicroseconds(10);
    _pin->setLow();

    return _pin->readPulse(HIGH, timeout);
}

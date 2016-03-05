#include "ultrasonic.h"


MBotUltrasonicSubject *MBotUltrasonicSubject::create(DistanceProvider *distanceProvider)
{
    return new MBotUltrasonicSubject(distanceProvider);
}


MBotUltrasonicSubject::MBotUltrasonicSubject(DistanceProvider *distanceProvider)
:   _distanceProvider(distanceProvider)
{}


void MBotUltrasonicSubject::tick(void)
{
    unsigned long d = _distanceProvider->distance();

    // Serial.print("MBotUltrasonicSubject::tick: distance: ");
    // Serial.println(d);

    if (changeStateToBlocked(d))
    {
        setStateToBlocked();
    }
    else if (changeStateToNear(d))
    {
        setStateToNear();
    }
    else if (changeStateToFar(d))
    {
        setStateToFar();
    }
}


bool MBotUltrasonicSubject::changeStateToBlocked(unsigned long d)
{
    return _state != BLOCKED && d > 0 && d <= MAX_DISTANCE_BLOCKED;
}


bool MBotUltrasonicSubject::changeStateToNear(unsigned long d)
{
    return _state != NEAR && d > MAX_DISTANCE_BLOCKED  && d <= MAX_DISTANCE_NEAR;
}


bool MBotUltrasonicSubject::changeStateToFar(unsigned long d)
{
    return _state != FAR && (d == 0 || d > MAX_DISTANCE_NEAR);
}


void MBotUltrasonicSubject::setStateToBlocked(void)
{
    _isBlocked = true;
    _lastState = _state;
    _state = BLOCKED;
    notify();
}


void MBotUltrasonicSubject::setStateToNear(void)
{
    _isBlocked = false;
    _lastState = _state;
    _state = NEAR;
    notify();
}


void MBotUltrasonicSubject::setStateToFar(void)
{
    _isBlocked = false;
    _lastState = _state;
    _state = FAR;
    notify();
}

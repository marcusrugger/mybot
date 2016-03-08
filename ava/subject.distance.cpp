#include "subject.distance.h"


DistanceSubject *DistanceSubject::create(DistanceProvider *distanceProvider)
{
    return new DistanceSubject(distanceProvider);
}


DistanceSubject::DistanceSubject(DistanceProvider *distanceProvider)
:   _distanceProvider(distanceProvider)
{}


void DistanceSubject::run(void)
{
    unsigned long d = _distanceProvider->distance();

    // Serial.print("DistanceSubject::run: distance: ");
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


bool DistanceSubject::changeStateToBlocked(unsigned long d)
{
    return _state != BLOCKED && d > 0 && d <= MAX_DISTANCE_BLOCKED;
}


bool DistanceSubject::changeStateToNear(unsigned long d)
{
    return _state != NEAR && d > MAX_DISTANCE_BLOCKED  && d <= MAX_DISTANCE_NEAR;
}


bool DistanceSubject::changeStateToFar(unsigned long d)
{
    return _state != FAR && (d == 0 || d > MAX_DISTANCE_NEAR);
}


void DistanceSubject::setStateToBlocked(void)
{
    _isBlocked = true;
    _lastState = _state;
    _state = BLOCKED;
    notify();
}


void DistanceSubject::setStateToNear(void)
{
    _isBlocked = false;
    _lastState = _state;
    _state = NEAR;
    notify();
}


void DistanceSubject::setStateToFar(void)
{
    _isBlocked = false;
    _lastState = _state;
    _state = FAR;
    notify();
}

#include "ultrasonic.h"


MBotUltrasonicSubject *MBotUltrasonicSubject::_instance;


MBotUltrasonicSubject *MBotUltrasonicSubject::instance(void)
{
    if (NULL == _instance)
        _instance = new MBotUltrasonicSubject();

    return _instance;
}


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
    digitalWrite(_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_pin, LOW);
    pinMode(_pin, INPUT);
    return pulseIn(_pin, HIGH, timeout);
}

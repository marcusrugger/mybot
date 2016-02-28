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
    long d = distance();

    // Serial.print("MBotUltrasonicSubject::tick: distance: ");
    // Serial.println(d);

    if (d < 100)
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

#include "hardware.ultrasonic.h"


UltrasonicSensor *UltrasonicSensor::create(DigitalPin *pin)
{
    return new UltrasonicSensor(pin);
}


UltrasonicSensor::UltrasonicSensor(DigitalPin *pin)
:   _pin(pin)
{}


unsigned long UltrasonicSensor::distance(void)
{
    return readSensor(22200) / 6;
}


unsigned long UltrasonicSensor::readSensor(unsigned long timeout)
{
    _pin->setLow();     delayMicroseconds(2);
    _pin->setHigh();    delayMicroseconds(10);
    _pin->setLow();

    return _pin->readPulse(HIGH, timeout);
}

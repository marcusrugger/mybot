#include "hardware.buzzer.h"
#include "robot.h"


SimpleBuzzer *SimpleBuzzer::create(DigitalPinWriter *pin)
{
    return new SimpleBuzzer(pin);
}


SimpleBuzzer::SimpleBuzzer(DigitalPinWriter *pin)
:   _pin(pin),
    _buzzerOn(false),
    _pinState(false)
{
    _pin->setLow();
}


void SimpleBuzzer::setBuzzer(bool flag)
{
    if (flag)
        setBuzzerOn();
    else
        setBuzzerOff();
}


void SimpleBuzzer::setBuzzerOn(void)
{
    _buzzerOn = true;
    _wait_time = 2;
    _wait_start = Robot::getMillis();
}


void SimpleBuzzer::setBuzzerOff(void)
{
    _buzzerOn = false;
    _pinState = false;
    _pin->setLow();
}


void SimpleBuzzer::tick(void)
{
    if (_buzzerOn && isTimeExpired())
    {
        _pinState = !_pinState;
        _pin->set(_pinState);
        _wait_start = Robot::getMillis();
    }
}


bool SimpleBuzzer::isTimeExpired(void)
{
    return Robot::getMillis() - _wait_start > _wait_time;
}

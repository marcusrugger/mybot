#include "motor.h"


Motor::Motor(uint8_t pinPwm, uint8_t pinDir)
:   _pinPwm(pinPwm),
    _pinDir(pinDir)
{
    pinMode(_pinDir, OUTPUT);
}


void Motor::run(int speed)
{
    if (speed >= 0)
        setMotor(HIGH, limitSpeed(speed));
    else
        setMotor(LOW, limitSpeed(-speed));
}


uint8_t Motor::limitSpeed(int speed)
{
    return speed > MAX_SPEED ? MAX_SPEED : speed;
}


int Motor::setMotor(uint8_t state, uint8_t speed)
{
    digitalWrite(_pinDir, state);
    analogWrite(_pinPwm, limitSpeed(speed));
}


void Motor::stop(void)
{
    run(0);
}

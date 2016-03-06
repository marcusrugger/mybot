#include "motor.h"


MBotMotor::MBotMotor(uint8_t pinPwm, uint8_t pinDir, bool reverse)
:   _pinPwm(pinPwm),
    _pinDir(pinDir),
    _reverse(reverse)
{
    pinMode(_pinDir, OUTPUT);
}


void MBotMotor::run(int speed)
{
    speed = translateDirection(speed);

    if (speed >= 0)
        setMotor(HIGH, speed);
    else
        setMotor(LOW, -speed);
}


int MBotMotor::translateDirection(int speed)
{
    return _reverse ? -speed : speed;
}


uint8_t MBotMotor::limitSpeed(int speed)
{
    return speed > MAX_SPEED ? MAX_SPEED : speed;
}


void MBotMotor::setMotor(uint8_t state, uint8_t speed)
{
    digitalWrite(_pinDir, state);
    analogWrite(_pinPwm, limitSpeed(speed));
}


void MBotMotor::stop(void)
{
    run(0);
}

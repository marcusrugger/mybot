#include "motion.h"


MBotMotion::MBotMotion(Motor *motorLeft, Motor *motorRight)
:   _motorLeft(motorLeft),
    _motorRight(motorRight)
{}


void MBotMotion::forward(void)
{
    _motorLeft->run(Motor::MAX_FORWARD);
    _motorRight->run(Motor::MAX_FORWARD);
}


void MBotMotion::backward(void)
{
    _motorLeft->run(Motor::MAX_REVERSE);
    _motorRight->run(Motor::MAX_REVERSE);
}


void MBotMotion::rotateLeft(void)
{
    _motorLeft->run(Motor::MAX_REVERSE);
    _motorRight->run(Motor::MAX_FORWARD);
}


void MBotMotion::rotateRight(void)
{
    _motorLeft->run(-Motor::MAX_FORWARD);
    _motorRight->run(-Motor::MAX_REVERSE);
}


void MBotMotion::stop(void)
{
    _motorLeft->stop();
    _motorRight->stop();
}

#include "motion.h"


Motion::Motion(Motor *motorLeft, Motor *motorRight)
:   _motorLeft(motorLeft),
    _motorRight(motorRight)
{}


void Motion::forward(void)
{
    _motorLeft->run(Motor::MAX_SPEED);
    _motorRight->run(Motor::MAX_SPEED);
}


void Motion::backward(void)
{
    _motorLeft->run(-Motor::MAX_SPEED);
    _motorRight->run(-Motor::MAX_SPEED);
}


void Motion::rotateLeft(void)
{
    _motorLeft->run(-Motor::MAX_SPEED);
    _motorRight->run(Motor::MAX_SPEED);
}


void Motion::rotateRight(void)
{
    _motorLeft->run(Motor::MAX_SPEED);
    _motorRight->run(-Motor::MAX_SPEED);
}


void Motion::stop(void)
{
    _motorLeft->stop();
    _motorRight->stop();
}

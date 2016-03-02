#include "motion.h"


MBotMotion::MBotMotion(Motor *motorLeft, Motor *motorRight)
:   _motorLeft(motorLeft),
    _motorRight(motorRight)
{
    MBotMotion::speed(MEDIUM);
}


void MBotMotion::speed(SPEED speed)
{
    switch (speed)
    {
        case STOP:
            _speed_forward = 0;
            _speed_reverse = 0;
        break;

        case SLOW:
            _speed_forward = Motor::MAX_FORWARD / 4;
            _speed_reverse = Motor::MAX_REVERSE / 4;
        break;

        case MEDIUM:
            _speed_forward = Motor::MAX_FORWARD / 2;
            _speed_reverse = Motor::MAX_REVERSE / 2;
        break;

        case FAST:
            _speed_forward = Motor::MAX_FORWARD;
            _speed_reverse = Motor::MAX_REVERSE;
        break;
    }
}


void MBotMotion::forward(void)
{
    _motorLeft->run(_speed_forward);
    _motorRight->run(_speed_forward);
}


void MBotMotion::backward(void)
{
    _motorLeft->run(_speed_reverse);
    _motorRight->run(_speed_reverse);
}


void MBotMotion::rotateLeft(void)
{
    _motorLeft->run(_speed_reverse);
    _motorRight->run(_speed_forward);
}


void MBotMotion::rotateRight(void)
{
    _motorLeft->run(_speed_forward);
    _motorRight->run(_speed_reverse);
}


void MBotMotion::stop(void)
{
    _motorLeft->stop();
    _motorRight->stop();
}

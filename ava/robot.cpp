#include <Arduino.h>
#include "robot.h"
#include "scheduler.h"
#include "hardware.buzzer.h"


Robot *Robot::_instance = NULL;
unsigned long Robot::_millis;


void Robot::setMillis(unsigned long millis)
{ _millis = millis; }


unsigned long Robot::getMillis(void)
{ return _millis; }


Robot *Robot::createRobot(RobotFactory &factory)
{
    if (NULL == _instance)
        _instance = new Robot(factory);

    return _instance;
}


Robot *Robot::instance(void)
{
    return _instance;
}


Robot::Robot(RobotFactory &factory)
:   _factory(factory)
{
    _scheduler      = factory.createScheduler();
    _idleloop       = factory.createIdleloop();
    _commandQueue   = factory.createCommandQueue();
    _movement       = factory.assembleMotionControl();

    _buzzer = factory.assembleBuzzer(PIN_MCORE_BUZZER);
    _scheduler->schedule(_buzzer);
}


void Robot::alertUser(void)
{
    _buzzer->setBuzzerOn();
}

#include <Arduino.h>
#include "robot.h"
#include "scheduler.h"


Robot *Robot::_instance = NULL;


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
    _movement       = factory.assembleMotionControl();
    _commandQueue   = factory.createCommandQueue();
}

#include <Arduino.h>
#include "robot.h"
#include "scheduler.h"


Robot *Robot::_instance = NULL;


Robot *Robot::createRobot(RobotFactory &factory)
{
    if (NULL == _instance)
        _instance = new Robot(factory);
    else
        Serial.println("Robot::createRobot: Error, Robot already exists.");

    return _instance;
}


Robot *Robot::instance(void)
{
    if (NULL == _instance)
        Serial.println("Robot::instance: Error, Robot does not exist.");

    return _instance;
}


Robot::Robot(RobotFactory &factory)
:   _factory(factory)
{
    _scheduler  = factory.createScheduler();
    _idleloop   = factory.createIdleloop();
    _movement   = factory.createMotionControl();
}

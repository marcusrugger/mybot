#include <Arduino.h>
#include "robot.h"
#include "task.runner.h"
#include "hardware.buzzer.h"


Robot *Robot::_instance = NULL;
unsigned long Robot::_millis;


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
    _buzzer         = factory.createBuzzer();
    _movement       = factory.assembleMotionControl();
    _display        = factory.assembleSegmentDisplay(13, 12);
}


void Robot::alertUser(void)
{
    // Serial.println("Robot::alertUser");
    _buzzer->soundUserAlert();
}

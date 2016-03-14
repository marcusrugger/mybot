#ifndef ROBOT_H
#define ROBOT_H

#include "interfaces.h"

class Scheduler;
class Runnable;
class CommandQueue;


class Robot
{
public:

    static Robot *createRobot(RobotFactory &factory);
    static Robot *instance(void);

    RobotFactory    &factory(void)      { return _factory;      }
    Scheduler       *scheduler(void)    { return _scheduler;    }
    Runnable        *idleloop(void)     { return _idleloop;     }
    Moveable        *movement(void)     { return _movement;     }
    CommandQueue    *commandQueue(void) { return _commandQueue; }

    void alertUser(void);

private:

    Robot(RobotFactory &factory);

    static Robot *_instance;
    static unsigned long _millis;

    RobotFactory    &_factory;
    Scheduler       *_scheduler;
    Runnable        *_idleloop;
    Moveable        *_movement;
    CommandQueue    *_commandQueue;
    Buzzer          *_buzzer;

};


#endif

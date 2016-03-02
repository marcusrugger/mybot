#ifndef ROBOT_H
#define ROBOT_H

#include "interfaces.h"

class Scheduler;
class Tickable;
class CommandQueue;


class Robot
{
public:

    static Robot *createRobot(RobotFactory &factory);
    static Robot *instance(void);

    RobotFactory    &factory(void)      { return _factory;      }
    Scheduler       *scheduler(void)    { return _scheduler;    }
    Tickable        *idleloop(void)     { return _idleloop;     }
    Moveable        *movement(void)     { return _movement;     }
    CommandQueue    *commandQueue(void) { return _commandQueue; }

private:

    Robot(RobotFactory &factory);

    static Robot *_instance;

    RobotFactory    &_factory;
    Scheduler       *_scheduler;
    Tickable        *_idleloop;
    Moveable        *_movement;
    CommandQueue    *_commandQueue;

};


#endif

#ifndef MBOTFACTORY_H
#define MBOTFACTORY_H


#include "interfaces.h"

class Moveable;


class MBotFactory : public RobotFactory
{
public:

    MBotFactory(void);

    Scheduler   *createScheduler(void);
    Tickable    *createIdleloop(void);
    Tickable    *createTimer(Tickable *tickee, uint16_t milli);
    Moveable    *createMotionControl(void);

    void buildButtonProcessor(void);
    void buildUltrasonicProcessor(void);

};


#endif

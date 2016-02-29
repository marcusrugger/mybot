#ifndef MBOTFACTORY_H
#define MBOTFACTORY_H


#include "interfaces.h"

class Moveable;


class MBotFactory : public RobotFactory
{
public:

    MBotFactory(void);

    Scheduler       *createScheduler(void);
    Tickable        *createIdleloop(void);
    Tickable        *createTimer(Tickable *tickee, uint16_t milli);
    Moveable        *createMotionControl(void);
    PinReader       *createPinReader(uint8_t pin, uint8_t mode);
    ButtonSubject   *createButtonSubject(PinReader *pin);
    Observer        *createButtonProcessor(ButtonSubject *subject, Moveable *move);

};


#endif

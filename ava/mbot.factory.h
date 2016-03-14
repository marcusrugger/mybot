#ifndef MBOTFACTORY_H
#define MBOTFACTORY_H


#include "mcore.h"
#include "interfaces.h"

class Moveable;


class MBotFactory : public RobotFactory
{
public:

    MBotFactory(PINMAP *pinmap);

    Scheduler           *createScheduler(void);
    Runnable            *createIdleloop(void);
    Runnable            *createTimer(Runnable *tickee, uint16_t milli);
    CommandQueue        *createCommandQueue(void);
    AnalogPinReader     *createAnalogPinReader(uint8_t pin, uint8_t mode);
    Motor               *createMotor(uint8_t pinPwm, uint8_t pinDir, bool reverse);
    Buzzer              *createBuzzer(void);

    Moveable            *assembleMotionControl(void);
    ButtonSubject       *assembleButtonSubject(int pinNumber);
    DistanceSubject     *assembleUltrasonicSubject(int pinNumber);
    LightLatchSubject   *assembleLightLatchSubject(int pinNumber);

private:

    PINMAP *_pinmap;

};


#endif

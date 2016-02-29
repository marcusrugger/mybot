#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>
#include "mcore.h"
#include "scheduler.h"
#include "subject.h"
#include "motion.h"


class MBotUltrasonicSubject : public BaseSubject,
                              public Tickable
{
public:

    static MBotUltrasonicSubject *instance(void);

    void tick(void);

private:

    const uint8_t _pin = PIN_MCORE_ULTRASONIC_SENSOR;
    static MBotUltrasonicSubject *_instance;

    long distance(void);
    long readSensor(unsigned long timeout);
};


class MBotUltrasonicObserver : public Observer
{
public:

    MBotUltrasonicObserver(Moveable *move) : _move(move) {}


    void update(void)
    {
        _move->stop();
    }


private:

    Moveable *_move;
};

#endif

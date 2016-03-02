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

    enum DISTANCE
    {
        BLOCKED,    // Distances less than 100mm
        NEAR,       // Distances from 100mm to 1000mm
        FAR         // Distances greater than 1000mm
    };

    void tick(void);

    bool isBlocked(void)        { return _isBlocked; };
    DISTANCE getState(void)     { return _state;     }
    DISTANCE getLastState(void) { return _lastState; }

private:

    const uint8_t _pin = PIN_MCORE_ULTRASONIC_SENSOR;
    static MBotUltrasonicSubject *_instance;

    bool _isBlocked = false;
    DISTANCE _state = BLOCKED;
    DISTANCE _lastState = BLOCKED;

    long distance(void);
    long readSensor(unsigned long timeout);

    void changeStateToBlocked(void);
    void changeStateToNear(void);
    void changeStateToFar(void);
};


class MBotPathSensor : public Observer
{
public:

    MBotPathSensor(MBotUltrasonicSubject *subject, Command *pathBlocked, Command *pathCleared)
    :   _subject(subject),
        _pathBlocked(pathBlocked),
        _pathCleared(pathCleared)
    {}


    void update(void)
    {
        if (_subject->isBlocked())
            _pathBlocked->execute();
        else
            _pathCleared->execute();
    }


private:

    MBotUltrasonicSubject *_subject;
    Command *_pathBlocked;
    Command *_pathCleared;

};

#endif

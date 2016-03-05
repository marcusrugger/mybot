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

    static MBotUltrasonicSubject *create(DistanceProvider *distanceProvider);

    enum DISTANCE
    {
        BLOCKED,    // Distances <= MAX_DISTANCE_BLOCKED
        NEAR,       // Distances > MAX_DISTANCE_BLOCKED and <= MAX_DISTANCE_NEAR
        FAR         // Distances > MAX_DISTANCE_NEAR
    };

    void tick(void);

    bool isBlocked(void)        { return _isBlocked; };
    DISTANCE getState(void)     { return _state;     }
    DISTANCE getLastState(void) { return _lastState; }

private:

    MBotUltrasonicSubject(DistanceProvider *distanceProvider);

    DistanceProvider *_distanceProvider;
    bool _isBlocked = false;
    DISTANCE _state = BLOCKED;
    DISTANCE _lastState = BLOCKED;

    const unsigned long MAX_DISTANCE_BLOCKED    = 100;
    const unsigned long MAX_DISTANCE_NEAR       = 1000;

    bool changeStateToBlocked(unsigned long d);
    bool changeStateToNear(unsigned long d);
    bool changeStateToFar(unsigned long d);

    void setStateToBlocked(void);
    void setStateToNear(void);
    void setStateToFar(void);
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

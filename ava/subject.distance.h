#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>
#include "mcore.h"
#include "task.runner.h"
#include "subject.base.h"
#include "motion.h"


class DistanceSubject : public BaseSubject,
                        public Runnable
{
public:

    static DistanceSubject *create(DistanceProvider *distanceProvider);

    enum DISTANCE
    {
        BLOCKED,    // Distances <= MAX_DISTANCE_BLOCKED
        NEAR,       // Distances > MAX_DISTANCE_BLOCKED and <= MAX_DISTANCE_NEAR
        FAR         // Distances > MAX_DISTANCE_NEAR
    };

    void run(void);

    bool isBlocked(void)        { return _isBlocked; };
    DISTANCE getState(void)     { return _state;     }
    DISTANCE getLastState(void) { return _lastState; }

private:

    DistanceSubject(DistanceProvider *distanceProvider);

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

#endif

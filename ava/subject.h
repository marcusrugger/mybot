#ifndef SUBJECT_H
#define SUBJECT_H

#include <Arduino.h>
#include "mcore.h"
#include "interfaces.h"
#include "robot.h"
#include "scheduler.h"

class Observer;


class BaseSubject : public Subject
{
public:

    virtual void attach(Observer *observer);
    virtual void detach(const Observer *observer);

protected:

    void notify(void) const;

private:

    static const unsigned int MAX_OBSERVERS = 8;
    Observer *_observers[MAX_OBSERVERS];
    unsigned int _count = 0;

};


#endif

#ifndef SUBJECT_H
#define SUBJECT_H

#include <Arduino.h>
#include "mcore.h"
#include "interfaces.h"
#include "robot.h"
#include "scheduler.h"
#include "observer.h"


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


class ButtonSubject : public BaseSubject,
                      public Tickable
{
public:

    enum ButtonState
    {
        BUTTON_UP,
        BUTTON_DOWN
    };

    ButtonSubject(AnalogPinReader *pin) : _pin(pin)
    {}

    ButtonState getState(void)
    {
        return _pin->readPin() > 100 ? BUTTON_UP : BUTTON_DOWN;
    }

protected:

    void tick(void)
    {
        ButtonState current_state = getState();
        if (current_state != _state)
        {
            _state = current_state;
            notify();
        }
    }

private:

    AnalogPinReader *_pin;
    ButtonState _state;

};


#endif

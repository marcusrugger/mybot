#ifndef SUBJECT_H
#define SUBJECT_H

#include <Arduino.h>
#include "scheduler.h"
#include "observer.h"

class Subject
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

class PinState
{
public:

    PinState(uint8_t pin)
    :   _pin(pin)
    {
        pinMode(_pin, INPUT_PULLUP);
    }

    int16_t readPin(void)
    {
        return analogRead(_pin);
    }

private:

    uint8_t _pin;

};


class ButtonSubject : public Subject,
                      public Tickable
{
public:

    enum ButtonState
    {
        BUTTON_UP,
        BUTTON_DOWN
    };

    ButtonState getState(void)
    {
        return _pin.readPin() > 100 ? BUTTON_UP : BUTTON_DOWN;
    }

protected:

    ButtonSubject(uint8_t pin) : _pin(pin)
    {
        TaskRunner::instance()->schedule(this);
    }

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

    PinState _pin;
    ButtonState _state;

};


class MCoreButtonSubject : public ButtonSubject
{
public:

    static ButtonSubject *instance(void)
    {
        if (NULL == _instance)
            _instance = new MCoreButtonSubject();

        return _instance;
    }

protected:

    MCoreButtonSubject(void) : ButtonSubject(A7)
    {}

private:

    static MCoreButtonSubject *_instance;

};

#endif

#ifndef OBSERVER_H
#define OBSERVER_H

class ButtonSubject;
class Moveable;

class Observer
{
public:

    virtual void update(void);

};

class ButtonObserver : public Observer
{
public:

    ButtonObserver(ButtonSubject *subject, Moveable *move);

private:

    void update(void);

    ButtonSubject *_subject;
    Moveable *_move;

};

#endif

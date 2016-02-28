#ifndef OBSERVER_H
#define OBSERVER_H

class ButtonSubject;
class Moveable;

class Observer
{
public:

    virtual void update(void);

};

class ButtonObserver : public Observer,
                       public Tickable
{
public:

    ButtonObserver(ButtonSubject *subject, Moveable *move);

private:

    void update(void);
    void tick(void);

    ButtonSubject *_subject;
    Moveable *_move;
    Timer *_timer;

};

#endif

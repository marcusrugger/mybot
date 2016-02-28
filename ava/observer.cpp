#include "mcore.h"
#include "subject.h"
#include "observer.h"
#include "motion.h"
#include "scheduler.h"




class Mover : public Tickable
{
public:

    static Tickable *forward(void);
    static Tickable *backward(void);
    static Tickable *rotateLeft(void);
    static Tickable *rotateRight(void);

    void Tick(void)
    {
        // motorLeft->run(speedLeft);
        // motorRight->run(speedRight);
    }

protected:

private:

    int speedLeft;
    int speedRight;

};







void Observer::update(void)
{}


ButtonObserver::ButtonObserver(ButtonSubject *subject, Moveable *move)
:   _subject(subject),
    _move(move),
    _timer(NULL)
{
    _subject->attach(this);
}

void ButtonObserver::update(void)
{
    ButtonSubject::ButtonState state = _subject->getState();

    if (ButtonSubject::BUTTON_UP == state && NULL == _timer)
    {
        Serial.println("Button changed state: up");
        _move->forward();
        _timer = new Timer(this, 5000);
        TaskRunner::instance()->schedule(_timer);
    }
    else if (ButtonSubject::BUTTON_DOWN == state)
    {
        Serial.println("Button changed state: down");
        _move->stop();
    }
}

void ButtonObserver::tick(void)
{
    _move->stop();
    TaskRunner::instance()->unschedule(_timer);
    delete _timer;
    _timer = NULL;
}
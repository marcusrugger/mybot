#include "mcore.h"
#include "robot.h"
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


MoveOnButtonRelease::MoveOnButtonRelease(ButtonSubject *subject, Moveable *move)
:   _factory(Robot::instance()->factory()),
    _scheduler(Robot::instance()->scheduler()),
    _subject(subject),
    _move(move),
    _timer(NULL)
{
    _subject->attach(this);
}

void MoveOnButtonRelease::update(void)
{
    ButtonSubject::ButtonState state = _subject->getState();

    if (ButtonSubject::BUTTON_UP == state && NULL == _timer)
    {
        Serial.println("Button changed state: up");
        _move->forward();

        _timer = _factory.createTimer(this, 5000);
        _scheduler->schedule(_timer);
    }
    else if (ButtonSubject::BUTTON_DOWN == state)
    {
        Serial.println("Button changed state: down");
        _move->stop();
    }
}

void MoveOnButtonRelease::tick(void)
{
    _move->stop();
    _scheduler->unschedule(_timer);
    delete _timer;
    _timer = NULL;
}
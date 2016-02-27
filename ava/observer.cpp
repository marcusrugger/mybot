#include "subject.h"
#include "observer.h"
#include "motion.h"


void Observer::update(void)
{}


ButtonObserver::ButtonObserver(ButtonSubject *subject, Moveable *move)
:   _subject(subject),
    _move(move)
{
    _subject->attach(this);
}

void ButtonObserver::update(void)
{
    ButtonSubject::ButtonState state = _subject->getState();

    if (ButtonSubject::BUTTON_UP == state)
    {
        Serial.println("Button changed state: up");
        _move->stop();
    }
    else
    {
        Serial.println("Button changed state: down");
        _move->rotateRight();
    }
}

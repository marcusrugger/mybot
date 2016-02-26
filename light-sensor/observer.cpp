#include "subject.h"
#include "observer.h"


void Observer::update(void)
{}


mCoreButtonObserver::mCoreButtonObserver(ButtonSubject *subject)
:   _subject(subject)
{
    _subject->attach(this);
}

void mCoreButtonObserver::update(void)
{
    ButtonSubject::ButtonState state = _subject->getState();

    if (ButtonSubject::BUTTON_UP == state)
        Serial.println("Button changed state: up");
    else
        Serial.println("Button changed state: down");
}

#include "subject.h"
#include "observer.h"


void Observer::update(void)
{}


mCoreButtonObserver::mCoreButtonObserver(void)
{
    mCoreButtonSubject::instance()->attach(this);
}

void mCoreButtonObserver::update(void)
{
    mCoreButtonSubject::ButtonState state = mCoreButtonSubject::instance()->getState();

    if (mCoreButtonSubject::BUTTON_UP == state)
        Serial.println("Button changed state: up");
    else
        Serial.println("Button changed state: down");
}

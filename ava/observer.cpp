#include "mcore.h"
#include "robot.h"
#include "subject.h"
#include "observer.h"
#include "motion.h"
#include "scheduler.h"


MBotButtonObserver::MBotButtonObserver(ButtonSubject *subject,
                                       Command *buttonPressed,
                                       Command *buttonReleased)
:   _subject(subject),
    _buttonPressed(buttonPressed),
    _buttonReleased(buttonReleased)
{
    _subject->attach(this);
}


void MBotButtonObserver::update(void)
{
    ButtonSubject::ButtonState state = _subject->getState();

    if (ButtonSubject::BUTTON_UP == state)
        _buttonReleased->execute();
    else if (ButtonSubject::BUTTON_DOWN == state)
        _buttonPressed->execute();
}

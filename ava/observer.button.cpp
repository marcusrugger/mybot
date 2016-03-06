#include "mcore.h"
#include "robot.h"
#include "subject.button.h"
#include "observer.button.h"
#include "motion.h"
#include "scheduler.h"


ButtonObserver::ButtonObserver(ButtonSubject *subject,
                                       Command *buttonPressed,
                                       Command *buttonReleased)
:   _subject(subject),
    _buttonPressed(buttonPressed),
    _buttonReleased(buttonReleased)
{
    _subject->attach(this);
}


void ButtonObserver::update(void)
{
    ButtonProvider::ButtonState state = _subject->getButtonState();

    if (ButtonProvider::BUTTON_UP == state)
        _buttonReleased->execute();
    else if (ButtonProvider::BUTTON_DOWN == state)
        _buttonPressed->execute();
}

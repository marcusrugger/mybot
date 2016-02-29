#include "mcore.h"
#include "mbotbuilder.h"
#include "robot.h"
#include "subject.h"


MBotBuilder::MBotBuilder(RobotFactory &factory)
:   _factory(factory),
    _robot(Robot::createRobot(factory))
{}


void MBotBuilder::buildRobot(void)
{
    buildButtonProcessor();
}


void MBotBuilder::buildButtonProcessor(void)
{
    Scheduler       *scheduler  = _robot->scheduler();
    PinReader       *pin        = _factory.createPinReader(PIN_MCORE_BUTTON, INPUT_PULLUP);
    ButtonSubject   *subject    = _factory.createButtonSubject(pin);
    Observer        *observer   = _factory.createButtonProcessor(subject, _robot->movement());
    scheduler->schedule(subject);
}

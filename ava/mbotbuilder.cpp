#include "mbotbuilder.h"
#include "mcore.h"
#include "motor.h"
#include "motion.h"
#include "scheduler.h"
#include "subject.h"
#include "observer.h"
#include "robot.h"
#include "ultrasonic.h"


MBotBuilder::MBotBuilder(RobotFactory &factory)
:   _factory(factory),
    _robot(Robot::createRobot(factory))
{}


void MBotBuilder::buildButtonProcessor(void)
{
    Scheduler       *scheduler  = _robot->scheduler();
    PinReader       *pin        = _factory.createPinReader(PIN_MCORE_BUTTON, INPUT_PULLUP);
    ButtonSubject   *subject    = new ButtonSubject(pin);
    Observer        *observer   = new MoveOnButtonRelease(subject);
    scheduler->schedule(subject);
}


void MBotBuilder::buildUltrasonicProcessor(void)
{
    Scheduler               *scheduler  = _robot->scheduler();
    Moveable                *move       = _robot->movement();
    MBotUltrasonicSubject   *subject    = MBotUltrasonicSubject::instance();
    Observer                *observer   = new MBotUltrasonicObserver(move);
    subject->attach(observer);
    scheduler->schedule(subject);
}

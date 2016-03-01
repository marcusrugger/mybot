#include "mbotbuilder.h"
#include "mcore.h"
#include "motor.h"
#include "motion.h"
#include "scheduler.h"
#include "subject.h"
#include "observer.h"
#include "robot.h"
#include "ultrasonic.h"
#include "commands.h"
#include "statemachine.h"


MBotBuilder::MBotBuilder(RobotFactory &factory)
:   _factory(factory),
    _robot(Robot::createRobot(factory))
{}


void MBotBuilder::buildButtonProcessor(void)
{
    Scheduler       *scheduler  = _robot->scheduler();

    ButtonSubject *subject;
    {
        PinReader *pin = _factory.createPinReader(PIN_MCORE_BUTTON, INPUT_PULLUP);
        subject = new ButtonSubject(pin);
        scheduler->schedule(subject);
    }

    MBotStateContext *context = MBotStateContext::instance();
    ButtonPressedCommand *buttonPressed = new ButtonPressedCommand(context);
    ButtonReleasedCommand *buttonReleased = new ButtonReleasedCommand(context);
    Observer *observer = new MBotButtonObserver(subject, buttonPressed, buttonReleased);
}


void MBotBuilder::buildUltrasonicProcessor(void)
{
    Scheduler               *scheduler  = _robot->scheduler();
    Moveable                *move       = _robot->movement();
    MBotUltrasonicSubject   *subject    = MBotUltrasonicSubject::instance();

    MBotStateContext *context = MBotStateContext::instance();
    Command     *pathBlocked    = new FrontPathBlockedCommand(context);
    Command     *pathCleared    = new FrontPathClearedCommand(context);
    Observer    *observer       = new MBotPathSensor(subject, pathBlocked, pathCleared);
    subject->attach(observer);
    scheduler->schedule(subject);
}

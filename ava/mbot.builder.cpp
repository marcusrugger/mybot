#include "mbot.builder.h"
#include "mcore.h"
#include "motor.h"
#include "motion.h"
#include "scheduler.h"
#include "subject.h"
#include "observer.h"
#include "robot.h"
#include "ultrasonic.h"
#include "commands.h"
#include "mbot.statemachine.h"


MBotBuilder::MBotBuilder(RobotFactory &factory)
:   _factory(factory),
    _robot(Robot::createRobot(factory))
{}


void MBotBuilder::buildCommandQueue(void)
{
    _robot->scheduler()->schedule(_robot->commandQueue());
}


void MBotBuilder::buildCommandButtonProcessor(void)
{
    Scheduler *scheduler = _robot->scheduler();

    ButtonSubject *subject;
    {
        PinReader *pin = _factory.createPinReader(PIN_MCORE_BUTTON, INPUT_PULLUP);
        subject = new ButtonSubject(pin);
        scheduler->schedule(subject);
    }

    Observer *observer;
    {
        MBotStateContext *context = MBotStateContext::instance();
        Command *buttonPressed = context->buttonPressedCommand();
        Command *buttonReleased = context->buttonReleasedCommand();
        observer = new MBotButtonObserver(subject, buttonPressed, buttonReleased);
    }
}


void MBotBuilder::buildUltrasonicProcessor(void)
{
    Scheduler               *scheduler  = _robot->scheduler();
    Moveable                *move       = _robot->movement();
    MBotUltrasonicSubject   *subject    = MBotUltrasonicSubject::instance();

    MBotStateContext *context = MBotStateContext::instance();
    Command     *pathBlocked    = context->frontPathBlockedCommand();
    Command     *pathCleared    = context->frontPathClearedCommand();
    Observer    *observer       = new MBotPathSensor(subject, pathBlocked, pathCleared);
    subject->attach(observer);
    scheduler->schedule(subject);
}

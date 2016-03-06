#include "mbot.builder.h"
#include "mcore.h"
#include "motor.h"
#include "motion.h"
#include "scheduler.h"
#include "hardware.button.h"
#include "subject.button.h"
#include "observer.button.h"
#include "robot.h"
#include "commands.h"
#include "mbot.statemachine.h"
#include "hardware.ultrasonic.h"
#include "subject.distance.h"
#include "subject.lightlatch.h"


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
    ButtonSubject *subject = _factory.assembleButtonSubject(PIN_MCORE_BUTTON);
    _robot->scheduler()->schedule(subject);

    MBotStateContext *context = MBotStateContext::instance();
    Command     *buttonPressed  = context->buttonPressedCommand();
    Command     *buttonReleased = context->buttonReleasedCommand();
    Observer    *observer       = new ButtonObserver(subject, buttonPressed, buttonReleased);

    subject->attach(observer);
}


void MBotBuilder::buildUltrasonicProcessor(void)
{
    DistanceSubject *subject = _factory.assembleUltrasonicSubject(PIN_MCORE_ULTRASONIC_SENSOR);
    _robot->scheduler()->schedule(subject);

    MBotStateContext *context = MBotStateContext::instance();
    Command     *pathBlocked    = context->frontPathBlockedCommand();
    Command     *pathCleared    = context->frontPathClearedCommand();
    Observer    *observer       = new DistanceObserver(subject, pathBlocked, pathCleared);

    subject->attach(observer);
    }


void MBotBuilder::buildLightProcessor(void)
{
    LightLatchSubject *subject = _factory.assembleLightLatchSubject(PIN_MCORE_LIGHT_SENSOR);
    _robot->scheduler()->schedule(subject);
}

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
#include "sensor.ultrasonic.h"


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
        AnalogPinReader *pin = _factory.createAnalogPinReader(PIN_MCORE_BUTTON, INPUT_PULLUP);
        subject = new ButtonSubject(pin);
        scheduler->schedule(subject);
    }

    // create observer
    {
        MBotStateContext *context = MBotStateContext::instance();
        Command *buttonPressed = context->buttonPressedCommand();
        Command *buttonReleased = context->buttonReleasedCommand();
        new MBotButtonObserver(subject, buttonPressed, buttonReleased);
    }
}


void MBotBuilder::buildUltrasonicProcessor(void)
{
    Scheduler               *scheduler  = _robot->scheduler();
    DigitalPin              *pin        = new ControllerDigitalPin(PIN_MCORE_ULTRASONIC_SENSOR);
    DistanceProvider        *sensor     = UltrasonicSensor::create(pin);
    MBotUltrasonicSubject   *subject    = MBotUltrasonicSubject::create(sensor);

    MBotStateContext *context = MBotStateContext::instance();
    Command     *pathBlocked    = context->frontPathBlockedCommand();
    Command     *pathCleared    = context->frontPathClearedCommand();
    Observer    *observer       = new MBotPathSensor(subject, pathBlocked, pathCleared);
    subject->attach(observer);
    scheduler->schedule(subject);
}

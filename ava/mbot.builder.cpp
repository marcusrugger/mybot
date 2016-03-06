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
        AnalogPinReader *pin    = _factory.createAnalogPinReader(PIN_MCORE_BUTTON, INPUT_PULLUP);
        ButtonProvider  *button = new HardwareButton(pin);
        subject = new ButtonSubject(button);
        scheduler->schedule(subject);
    }

    // create observer
    {
        MBotStateContext *context = MBotStateContext::instance();
        Command *buttonPressed = context->buttonPressedCommand();
        Command *buttonReleased = context->buttonReleasedCommand();
        new ButtonObserver(subject, buttonPressed, buttonReleased);
    }
}


void MBotBuilder::buildUltrasonicProcessor(void)
{
    Scheduler         *scheduler  = _robot->scheduler();
    DigitalPin        *pin        = new ControllerDigitalPin(PIN_MCORE_ULTRASONIC_SENSOR);
    DistanceProvider  *sensor     = UltrasonicSensor::create(pin);
    DistanceSubject   *subject    = DistanceSubject::create(sensor);

    MBotStateContext *context = MBotStateContext::instance();
    Command     *pathBlocked    = context->frontPathBlockedCommand();
    Command     *pathCleared    = context->frontPathClearedCommand();
    Observer    *observer       = new DistanceObserver(subject, pathBlocked, pathCleared);
    subject->attach(observer);
    scheduler->schedule(subject);
}

#include "mbot.builder.h"
#include "mcore.h"
#include "motor.h"
#include "motion.h"
#include "task.runner.h"
#include "hardware.button.h"
#include "subject.button.h"
#include "observer.button.h"
#include "observer.distance.h"
#include "robot.h"
#include "command.move.h"
#include "mbot.statemachine.h"
#include "hardware.ultrasonic.h"
#include "hardware.buzzer.h"
#include "hardware.rgbledwriter.h"
#include "hardware.rgbledarray.h"
#include "subject.distance.h"
#include "subject.lightlatch.h"
#include "task.blinker.h"
#include "task.displaycounter.h"
#include "task.countdowntimer.h"
#include "task.displayanimator.h"
#include "protocol.segmentdisplay.h"


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
    Runnable      *timer   = _factory.createTimer(subject, 100);
    _robot->scheduler()->schedule(timer);

    MBotStateContext *context = MBotStateContext::instance();
    Command     *buttonPressed  = context->buttonPressedCommand();
    Command     *buttonReleased = context->buttonReleasedCommand();
    Observer    *observer       = new ButtonObserver(subject, buttonPressed, buttonReleased);

    subject->attach(observer);
}


void MBotBuilder::buildUltrasonicProcessor(void)
{
    DistanceSubject *subject = _factory.assembleUltrasonicSubject(PIN_MCORE_ULTRASONIC_SENSOR);
    Runnable        *timer   = _factory.createTimer(subject, 200);
    _robot->scheduler()->schedule(timer);

    MBotStateContext *context = MBotStateContext::instance();
    Command     *pathBlocked    = context->frontPathBlockedCommand();
    Command     *pathCleared    = context->frontPathClearedCommand();
    Observer    *observer       = new DistanceObserver(subject, pathBlocked, pathCleared);

    subject->attach(observer);
}


void MBotBuilder::buildLightProcessor(void)
{
    LightLatchSubject *subject = _factory.assembleLightLatchSubject(PIN_MCORE_LIGHT_SENSOR);
    Runnable          *timer   = _factory.createTimer(subject, 200);
    _robot->scheduler()->schedule(timer);
}


void MBotBuilder::buildBlinker(void)
{
    RGBLedWriter *writer   = RGBLedWriter::create(PIN_MCORE_LEDS);
    RGBLedArray  *ledArray = RGBLedArray::create(writer, 2);
    BlinkerTask  *blinker  = BlinkerTask::create(ledArray);
    Runnable     *timer    = _factory.createTimer(blinker, 200);
    _robot->scheduler()->schedule(timer);
}


void MBotBuilder::buildDisplayCounter(void)
{
    DataStream *stream = _robot->display();
    Runnable   *task   = DisplayCounterTask::create(stream);
    Runnable   *timer  = _factory.createTimer(task, 100);
    _robot->scheduler()->schedule(timer);
}


void MBotBuilder::buildCountDownTimer(void)
{
    DataStream *stream = _robot->display();
    Runnable   *task   = CountDownTimerTask::create(stream, 60);
    Runnable   *timer  = _factory.createTimer(task, 1000);
    _robot->scheduler()->schedule(timer);
}


void MBotBuilder::buildDisplayAnimator(void)
{
    DigitalPin      *pinClock   = new ControllerDigitalPin(2);
    DigitalPin      *pinData    = new ControllerDigitalPin(8);
    DataSerializer  *writer     = SegmentDisplayProtocol::create(pinClock, pinData);
    Runnable        *task       = DisplayAnimatorTask::create(writer);
    Runnable        *timer      = _factory.createTimer(task, 100);
    _robot->scheduler()->schedule(timer);
}

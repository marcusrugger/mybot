#include "mbotfactory.h"
#include "mcore.h"
#include "motor.h"
#include "motion.h"
#include "scheduler.h"
#include "subject.h"
#include "observer.h"
#include "robot.h"
#include "ultrasonic.h"


MBotFactory::MBotFactory(void)
{}


Scheduler *MBotFactory::createScheduler(void)
{
    return TaskRunner::instance();
}


Tickable *MBotFactory::createIdleloop(void)
{
    return TaskRunner::instance();
}


Tickable *MBotFactory::createTimer(Tickable *tickee, uint16_t milli)
{
    return new Timer(tickee, milli);
}


Moveable *MBotFactory::createMotionControl(void)
{
    Motor *motorLeft    = new MBotMotor(PIN_MOTOR_LEFT_PWM, PIN_MOTOR_LEFT_DIR, MOTOR_LEFT_REVERSE);
    Motor *motorRight   = new MBotMotor(PIN_MOTOR_RIGHT_PWM, PIN_MOTOR_RIGHT_DIR, MOTOR_RIGHT_REVERSE);
    return new MBotMotion(motorLeft, motorRight);
}


void MBotFactory::buildButtonProcessor(void)
{
    Scheduler       *scheduler  = Robot::instance()->scheduler();
    PinReader       *pin        = new ControllerPin(PIN_MCORE_BUTTON, INPUT_PULLUP);
    ButtonSubject   *subject    = new ButtonSubject(pin);
    Observer        *observer   = new MoveOnButtonRelease(subject);
    scheduler->schedule(subject);
}


void MBotFactory::buildUltrasonicProcessor(void)
{
    Scheduler               *scheduler  = Robot::instance()->scheduler();
    Moveable                *move       = Robot::instance()->movement();
    MBotUltrasonicSubject   *subject    = MBotUltrasonicSubject::instance();
    Observer                *observer   = new MBotUltrasonicObserver(move);
    subject->attach(observer);
    scheduler->schedule(subject);
}

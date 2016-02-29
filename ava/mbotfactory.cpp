#include "mbotfactory.h"
#include "mcore.h"
#include "motor.h"
#include "motion.h"
#include "scheduler.h"
#include "subject.h"
#include "observer.h"


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


PinReader *MBotFactory::createPinReader(uint8_t pin, uint8_t mode)
{
    return new ControllerPin(pin, mode);
}


ButtonSubject *MBotFactory::createButtonSubject(PinReader *pin)
{
    return new ButtonSubject(pin);
}


Observer *MBotFactory::createButtonProcessor(ButtonSubject *subject, Moveable *move)
{
    return new MoveOnButtonRelease(subject, move);
}

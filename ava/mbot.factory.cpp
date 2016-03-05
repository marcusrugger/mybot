#include "mbot.factory.h"
#include "mcore.h"
#include "motor.h"
#include "motion.h"
#include "scheduler.h"
#include "subject.h"
#include "observer.h"
#include "robot.h"
#include "ultrasonic.h"
#include "commandqueue.h"


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


CommandQueue *MBotFactory::createCommandQueue(void)
{
    return new CommandQueue();
}


AnalogPinReader *MBotFactory::createAnalogPinReader(uint8_t pin, uint8_t mode)
{
    return new ControllerPin(pin, mode);
}


Motor *MBotFactory::createMotor(uint8_t pinPwm, uint8_t pinDir, bool reverse)
{
    return new MBotMotor(pinPwm, pinDir, reverse);
}


Moveable *MBotFactory::createMotionControl(void)
{
    Motor *motorLeft    = createMotor(PIN_MOTOR_LEFT_PWM, PIN_MOTOR_LEFT_DIR, MOTOR_LEFT_REVERSE);
    Motor *motorRight   = createMotor(PIN_MOTOR_RIGHT_PWM, PIN_MOTOR_RIGHT_DIR, MOTOR_RIGHT_REVERSE);
    return new MBotMotion(motorLeft, motorRight);
}

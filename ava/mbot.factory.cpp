#include "mbot.factory.h"
#include "mcore.h"
#include "motor.h"
#include "motion.h"
#include "task.runner.h"
#include "subject.base.h"
#include "observer.button.h"
#include "robot.h"
#include "subject.distance.h"
#include "subject.lightlatch.h"
#include "commandqueue.h"
#include "hardware.button.h"
#include "hardware.ultrasonic.h"
#include "hardware.buzzer.h"
#include "task.timer.h"


MBotFactory::MBotFactory(void)
{}


Scheduler *MBotFactory::createScheduler(void)
{
    return TaskRunner::instance();
}


Runnable *MBotFactory::createIdleloop(void)
{
    return TaskRunner::instance();
}


Runnable *MBotFactory::createTimer(Runnable *tickee, uint16_t milli)
{
    return new TimerTask(tickee, milli);
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


Moveable *MBotFactory::assembleMotionControl(void)
{
    Motor *motorLeft    = createMotor(PIN_MOTOR_LEFT_PWM, PIN_MOTOR_LEFT_DIR, MOTOR_LEFT_REVERSE);
    Motor *motorRight   = createMotor(PIN_MOTOR_RIGHT_PWM, PIN_MOTOR_RIGHT_DIR, MOTOR_RIGHT_REVERSE);
    return new MBotMotion(motorLeft, motorRight);
}


ButtonSubject *MBotFactory::assembleButtonSubject(int pinNumber)
{
    AnalogPinReader *pin    = createAnalogPinReader(pinNumber, INPUT_PULLUP);
    ButtonProvider  *button = new HardwareButton(pin);
    return new ButtonSubject(button);
}


DistanceSubject *MBotFactory::assembleUltrasonicSubject(int pinNumber)
{
    DigitalPin        *pin      = new ControllerDigitalPin(PIN_MCORE_ULTRASONIC_SENSOR);
    DistanceProvider  *sensor   = UltrasonicSensor::create(pin);
    return DistanceSubject::create(sensor);
}


LightLatchSubject *MBotFactory::assembleLightLatchSubject(int pinNumber)
{
    AnalogPinReader *pin = createAnalogPinReader(pinNumber, INPUT);
    return LightLatchSubject::create(pin);
}

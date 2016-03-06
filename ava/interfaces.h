#ifndef INTERFACES_H
#define INTERFACES_H

#include <Arduino.h>


class AnalogPinReader;

class ButtonSubject;
class DistanceSubject;
class LightLatchSubject;

class CommandQueue;


class Motor
{
public:

    static const int MAX_SPEED = 255;
    static const int MAX_FORWARD = MAX_SPEED;
    static const int MAX_REVERSE = -MAX_SPEED;

    virtual void run(int speed) = 0;
    virtual void stop(void) = 0;

};


class Moveable
{
public:

    enum SPEED
    {
        STOP,
        SLOW,
        MEDIUM,
        FAST
    };

    virtual void speed(SPEED speed) = 0;

    virtual void forward(void) = 0;
    virtual void backward(void) = 0;
    virtual void rotateLeft(void) = 0;
    virtual void rotateRight(void) = 0;

    virtual void stop(void) = 0;

};


class Tickable
{
public:

    virtual void tick(void) = 0;

};


class Scheduler
{
public:

    virtual void schedule(Tickable *task) = 0;
    virtual void unschedule(Tickable *task) = 0;

};


class Observer
{
public:

    virtual void update(void);

};


class Subject
{
public:

    virtual void attach(Observer *observer) = 0;
    virtual void detach(const Observer *observer) = 0;

};


class Command
{
public:

    virtual ~Command(void) {}

    virtual void execute(void) = 0;

};


class HardwareFactory
{
public:

    virtual AnalogPinReader *createAnalogPinReader(uint8_t pin, uint8_t mode) = 0;
    virtual Motor           *createMotor(uint8_t pinPwm, uint8_t pinDir, bool reverse = false) = 0;

};


class SystemFactory
{
public:

    virtual Scheduler       *createScheduler(void) = 0;
    virtual Tickable        *createIdleloop(void) = 0;
    virtual Tickable        *createTimer(Tickable *tickee, uint16_t milli) = 0;
    virtual CommandQueue    *createCommandQueue(void);
    virtual Moveable        *assembleMotionControl(void) = 0;

};


class RobotFactory
{
public:

    virtual Scheduler           *createScheduler(void) = 0;
    virtual Tickable            *createIdleloop(void) = 0;
    virtual Tickable            *createTimer(Tickable *tickee, uint16_t milli) = 0;
    virtual CommandQueue        *createCommandQueue(void);
    virtual AnalogPinReader     *createAnalogPinReader(uint8_t pin, uint8_t mode) = 0;
    virtual Motor               *createMotor(uint8_t pinPwm, uint8_t pinDir, bool reverse = false) = 0;

    virtual Moveable            *assembleMotionControl(void) = 0;
    virtual ButtonSubject       *assembleButtonSubject(int pinNumber) = 0;
    virtual DistanceSubject     *assembleUltrasonicSubject(int pinNumber) = 0;
    virtual LightLatchSubject   *assembleLightLatchSubject(int pinNumber) = 0;

};


class RobotBuilder
{
public:

    virtual void buildCommandQueue(void) = 0;
    virtual void buildCommandButtonProcessor(void) = 0;
    virtual void buildUltrasonicProcessor(void) = 0;
    virtual void buildLightProcessor(void) = 0;

};


#endif

#ifndef INTERFACES_H
#define INTERFACES_H

#include <Arduino.h>


class AnalogPinReader;

class ButtonSubject;
class DistanceSubject;
class LightLatchSubject;
class PinWatcherSubject;
class SimpleBuzzer;
class SegmentDisplay;

class CommandQueue;


class Motor
{
public:

    static const int MAX_SPEED = 255;
    static const int MAX_FORWARD = MAX_SPEED;
    static const int MAX_REVERSE = -MAX_SPEED;

    virtual ~Motor(void) {}

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

    virtual ~Moveable(void) {}

    virtual void speed(SPEED speed) = 0;

    virtual void forward(void) = 0;
    virtual void backward(void) = 0;
    virtual void rotateLeft(void) = 0;
    virtual void rotateRight(void) = 0;

    virtual void stop(void) = 0;

};


class Runnable
{
public:
    virtual ~Runnable(void) {}
    virtual void run(void) = 0;
};


class Observer
{
public:
    virtual ~Observer(void) {}
    virtual void update(void) = 0;
};


class Command
{
public:
    virtual ~Command(void) {}
    virtual void execute(void) = 0;
};


class Latch
{
public:
    virtual ~Latch(void) {}
    virtual bool isLatched(void) = 0;
};


class DataSerializer
{
public:
    virtual ~DataSerializer(void) {}
    virtual void writeData(const uint8_t *data, uint16_t length) = 0;
};


class DataStream
{
public:
    virtual ~DataStream(void) {}
    virtual void writeHex(uint16_t number) = 0;
    virtual void writeDec(uint16_t number) = 0;
};


class Scheduler
{
public:

    virtual ~Scheduler(void) {}

    virtual void schedule(Runnable *task) = 0;
    virtual void unschedule(Runnable *task) = 0;

};


class Subject
{
public:

    virtual ~Subject(void) {}

    virtual void attach(Observer *observer) = 0;
    virtual void detach(const Observer *observer) = 0;

};


class Buzzer
{
public:

    virtual ~Buzzer(void) {}

    virtual void soundUserAlert(void) = 0;

};


class HardwareFactory
{
public:

    virtual ~HardwareFactory(void) {}

    virtual AnalogPinReader *createAnalogPinReader(uint8_t pin, uint8_t mode) = 0;
    virtual Motor           *createMotor(uint8_t pinPwm, uint8_t pinDir, bool reverse = false) = 0;

};


class SystemFactory
{
public:

    virtual ~SystemFactory(void) {}

    virtual Scheduler       *createScheduler(void) = 0;
    virtual Runnable        *createIdleloop(void) = 0;
    virtual Runnable        *createTimer(Runnable *tickee, uint16_t milli) = 0;
    virtual CommandQueue    *createCommandQueue(void);

};


class AssemblyFactory
{
public:

    virtual ~AssemblyFactory(void) {}

    virtual Moveable            *assembleMotionControl(void) = 0;
    virtual ButtonSubject       *assembleButtonSubject(int pinNumber) = 0;
    virtual DistanceSubject     *assembleUltrasonicSubject(int pinNumber) = 0;
    virtual LightLatchSubject   *assembleLightLatchSubject(int pinNumber) = 0;
    virtual SegmentDisplay      *assembleSegmentDisplay(int pinClock, int pinData) = 0;

};


class RobotFactory
{
public:

    virtual ~RobotFactory(void) {}

    virtual Scheduler           *createScheduler(void) = 0;
    virtual Runnable            *createIdleloop(void) = 0;
    virtual Runnable            *createTimer(Runnable *tickee, uint16_t milli) = 0;
    virtual CommandQueue        *createCommandQueue(void) = 0;
    virtual AnalogPinReader     *createAnalogPinReader(uint8_t pin, uint8_t mode) = 0;
    virtual Motor               *createMotor(uint8_t pinPwm, uint8_t pinDir, bool reverse = false) = 0;
    virtual Buzzer              *createBuzzer(void) = 0;

    virtual Moveable            *assembleMotionControl(void) = 0;
    virtual ButtonSubject       *assembleButtonSubject(int pinNumber) = 0;
    virtual DistanceSubject     *assembleUltrasonicSubject(int pinNumber) = 0;
    virtual LightLatchSubject   *assembleLightLatchSubject(int pinNumber) = 0;
    virtual SegmentDisplay      *assembleSegmentDisplay(int pinClock, int pinData) = 0;

};


class RobotBuilder
{
public:

    virtual ~RobotBuilder(void) {}

    virtual void buildCommandQueue(void) = 0;
    virtual void buildCommandButtonProcessor(void) = 0;
    virtual void buildUltrasonicProcessor(void) = 0;
    virtual void buildLightProcessor(void) = 0;
    virtual void buildBlinker(void) = 0;
    virtual void buildDisplayCounter(void) = 0;
    virtual void buildCountDownTimer(void) = 0;
    virtual void buildDisplayAnimator(void) = 0;

};


#endif

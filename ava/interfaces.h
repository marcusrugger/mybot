#ifndef INTERFACES_H
#define INTERFACES_H

#include <Arduino.h>


class PinReader;
class ButtonSubject;


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


class RobotFactory
{
public:

    virtual Scheduler       *createScheduler(void) = 0;
    virtual Tickable        *createIdleloop(void) = 0;
    virtual Tickable        *createTimer(Tickable *tickee, uint16_t milli) = 0;

    virtual Moveable        *createMotionControl(void) = 0;
    virtual PinReader       *createPinReader(uint8_t pin, uint8_t mode) = 0;
    virtual ButtonSubject   *createButtonSubject(PinReader *pin) = 0;

    virtual Observer        *createButtonProcessor(ButtonSubject *subject, Moveable *move) = 0;

};


#endif

#ifndef MOTION_H
#define MOTION_H

#include <Arduino.h>
#include "motor.h"


class Moveable
{
public:

    virtual void forward(void) = 0;
    virtual void backward(void) = 0;
    virtual void rotateLeft(void) = 0;
    virtual void rotateRight(void) = 0;

    virtual void stop(void) = 0;

};


class MBotMotion : public Moveable
{
public:

    MBotMotion(Motor *motorLeft, Motor *motorRight);

    void forward(void);
    void backward(void);
    void rotateLeft(void);
    void rotateRight(void);

    void stop(void);


private:

    Motor *_motorLeft;
    Motor *_motorRight;

};

#endif

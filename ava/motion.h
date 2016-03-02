#ifndef MOTION_H
#define MOTION_H

#include <Arduino.h>
#include "interfaces.h"
#include "motor.h"


class MBotMotion : public Moveable
{
public:

    MBotMotion(Motor *motorLeft, Motor *motorRight);

    void speed(SPEED speed);

    void forward(void);
    void backward(void);
    void rotateLeft(void);
    void rotateRight(void);

    void stop(void);


private:

    Motor *_motorLeft;
    Motor *_motorRight;

    int _speed_forward;
    int _speed_reverse;

};

#endif

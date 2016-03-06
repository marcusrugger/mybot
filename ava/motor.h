#ifndef MOTOR_H
#define MOTOR_H


#include <Arduino.h>
#include "interfaces.h"


class MBotMotor : public Motor
{
public:

    static const int MAX_SPEED = 255;

    MBotMotor(uint8_t pinPwm, uint8_t pinDir, bool reverse = false);

    void run(int speed);
    void stop(void);


private:

    int translateDirection(int speed);
    uint8_t limitSpeed(int speed);
    void setMotor(uint8_t state, uint8_t speed);

    uint8_t _pinPwm;
    uint8_t _pinDir;
    bool _reverse;

};


#endif

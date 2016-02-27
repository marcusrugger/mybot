#ifndef MOTOR_H
#define MOTOR_H


#include <Arduino.h>


class Motor
{
public:

    Motor(uint8_t pinPwm, uint8_t pinDir);

    void run(int speed);
    void stop(void);


private:

    uint8_t limitSpeed(int speed);
    int setMotor(uint8_t state, uint8_t speed);

    uint8_t _pinPwm;
    uint8_t _pinDir;

};


#endif

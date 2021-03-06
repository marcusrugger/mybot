#ifndef MCORE_H
#define MCORE_H

#include <Arduino.h>
#include "controller.pin.h"


enum ATmega328P_AU
{
    PIN_PD3     = 1,
    PIN_PD4     = 2,
    PIN_GND3    = 3,
    PIN_VCC4    = 4,
    PIN_GND5    = 5,
    PIN_VCC6    = 6,
    PIN_PB6     = 7,
    PIN_PB7     = 8,
    PIN_PD5     = 9,
    PIN_PD6     = 10,
    PIN_PD7     = 11,
    PIN_PB0     = 12,
    PIN_PB1     = 13,
    PIN_PB2     = 14,
    PIN_PB3     = 15,
    PIN_PB4     = 16,
    PIN_PB5     = 17,
    PIN_AVCC    = 18,
    PIN_ADC6    = 19,
    PIN_AREF    = 20,
    PIN_GND21   = 21,
    PIN_ADC7    = 22,
    PIN_PC0     = 23,
    PIN_PC1     = 24,
    PIN_PC2     = 25,
    PIN_PC3     = 26,
    PIN_PC4     = 27,
    PIN_PC5     = 28,
    PIN_PC6     = 29,
    PIN_PD0     = 30,
    PIN_PD1     = 31,
    PIN_PD2     = 32
};


// Clock values
const uint16_t timer_resolution = 1000;
const uint16_t tick_delay       = 10;
const uint16_t ticks_per_second = timer_resolution / tick_delay;

inline uint16_t milli_to_ticks(uint16_t milliseconds)
{
    return milliseconds / tick_delay;
}


/************************************************************************
 * Pin mapping: http://forum.makeblock.cc/t/mbot-pin-mapping/3261
 */


const uint8_t PIN_MCORE_ULTRASONIC_SENSOR   = A3;
const uint8_t PIN_MCORE_LIGHT_SENSOR        = A6;
const uint8_t PIN_MCORE_BUTTON              = A7;


// Motor pinouts
const uint8_t PIN_MOTOR_RIGHT_DIR   = 4;
const uint8_t PIN_MOTOR_RIGHT_PWM   = 5;
const uint8_t PIN_MOTOR_LEFT_PWM    = 6;
const uint8_t PIN_MOTOR_LEFT_DIR    = 7;

// Motor directions
const bool MOTOR_RIGHT_REVERSE      = false;
const bool MOTOR_LEFT_REVERSE       = true;


const uint8_t PIN_MCORE_IR_RCV      = 2;
const uint8_t PIN_MCORE_IR_TX       = 3;
const uint8_t PIN_MCORE_BUZZER      = 8;
const uint8_t PIN_MCORE_LEDS        = 13;


const uint8_t PIN_ORION_BUZZER      = SCL;
const uint8_t PIN_ORION_FRONT_SERVO = 12;




struct PINMAP
{
    uint8_t motor_right_dir;
    uint8_t motor_right_pwm;
    uint8_t motor_left_dir;
    uint8_t motor_left_pwm;
    uint8_t motor_left_reverse;
    uint8_t motor_right_reverse;
    uint8_t front_servo;
    uint8_t buzzer;
    uint8_t ultrasonic_sensor_1;
    uint8_t ultrasonic_sensor_2;
    uint8_t led_array;

    PINMAP(void)
    {
        motor_right_dir     = PIN_MOTOR_RIGHT_DIR;
        motor_right_pwm     = PIN_MOTOR_RIGHT_PWM;
        motor_left_dir      = PIN_MOTOR_LEFT_DIR;
        motor_left_pwm      = PIN_MOTOR_LEFT_PWM;
        motor_right_reverse = MOTOR_RIGHT_REVERSE;
        motor_left_reverse  = MOTOR_LEFT_REVERSE;
        buzzer              = PIN_MCORE_BUZZER;
        ultrasonic_sensor_1 = PIN_MCORE_ULTRASONIC_SENSOR;
        ultrasonic_sensor_2 = PIN_MCORE_ULTRASONIC_SENSOR;
        led_array           = PIN_MCORE_LEDS;
    }
};


struct MCORE_PINMAP : public PINMAP
{
    MCORE_PINMAP(void) : PINMAP() {}
};


struct ORION_PINMAP : public PINMAP
{
    ORION_PINMAP(void)
    {
        front_servo = PIN_ORION_FRONT_SERVO;
        buzzer      = PIN_ORION_BUZZER;
    }
};



inline void enableInterrupts(void)
{ interrupts(); }

inline void disableInterrupts(void)
{ noInterrupts(); }


class DistanceProvider
{
public:

    // Returns distance in mm
    virtual unsigned long distance(void) = 0;

};


class ButtonProvider
{
public:

    enum ButtonState
    {
        BUTTON_UP,
        BUTTON_DOWN
    };

    virtual ButtonState getButtonState(void) = 0;

};


class ServoProvider
{};


#endif

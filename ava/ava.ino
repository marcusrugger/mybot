#include <Arduino.h>

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>

#include "mcore.h"
#include "scheduler.h"
#include "subject.h"
#include "motor.h"
#include "motion.h"
#include "ultrasonic.h"


Moveable *movement;
ButtonObserver *button;
MBotUltrasonicObserver *ultrasonic_observer;


void createMotors(void)
{
    Motor *motorLeft    = new MBotMotor(PIN_MOTOR_LEFT_PWM, PIN_MOTOR_LEFT_DIR, MOTOR_LEFT_REVERSE);
    Motor *motorRight   = new MBotMotor(PIN_MOTOR_RIGHT_PWM, PIN_MOTOR_RIGHT_DIR, MOTOR_RIGHT_REVERSE);
    movement            = new MBotMotion(motorLeft, motorRight);
}


void createButtonObserver(void)
{
    button = new ButtonObserver(MCoreButtonSubject::instance(), movement);
}


void createUltrasonicObserver(void)
{
    TaskRunner::instance()->schedule(MBotUltrasonicSubject::instance());

    ultrasonic_observer = new MBotUltrasonicObserver(movement);
    MBotUltrasonicSubject::instance()->attach(ultrasonic_observer);
}


void setup()
{
    Serial.begin(9600);

    createMotors();
    createButtonObserver();
    createUltrasonicObserver();

    Serial.println("Setup complete.");
}


void loop()
{
    uint16_t enter_tick = millis();

    TaskRunner::instance()->tick();

    uint16_t tick_time = millis() - enter_tick;
    if (tick_time < tick_delay)
        delay(tick_delay - tick_time);
}

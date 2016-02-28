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


ButtonObserver *button;


void setup()
{
    Serial.begin(9600);

    Motor *motorLeft  = new MBotMotor(PIN_MOTOR_LEFT_PWM, PIN_MOTOR_LEFT_DIR, MOTOR_LEFT_REVERSE);
    Motor *motorRight = new MBotMotor(PIN_MOTOR_RIGHT_PWM, PIN_MOTOR_RIGHT_DIR, MOTOR_RIGHT_REVERSE);

    Moveable *move = new MBotMotion(motorLeft, motorRight);

    button = new ButtonObserver(MCoreButtonSubject::instance(), move);

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

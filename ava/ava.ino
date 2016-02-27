#include <Arduino.h>

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>

#include "scheduler.h"
#include "subject.h"
#include "motor.h"
#include "motion.h"


class mCoreLightSensor
{
public:

    mCoreLightSensor(uint8_t ledPin, uint8_t sensorPin)
    :   _ledPin(ledPin),
        _sensorPin(sensorPin)
    {}

    int16_t read(void)
    {
        return analogRead(_sensorPin);
    }

    void lightOn(void)
    {
        digitalWrite(_ledPin, HIGH);
    }

    void lightOff(void)
    {
        digitalWrite(_ledPin, LOW);
    }


private:

    uint8_t _ledPin;
    uint8_t _sensorPin;

};

mCoreLightSensor lightSensor(8, A7);

ButtonObserver *button;


void setup()
{
    Serial.begin(9600);

    Motor *motorLeft  = new MBotMotor(6, 7);
    Motor *motorRight = new MBotMotor(5, 4, true);

    Moveable *move = new MBotMotion(motorLeft, motorRight);

    button = new ButtonObserver(MCoreButtonSubject::instance(), move);

    Serial.println("Setup complete.");
}


void loop()
{
    const uint16_t tick_delay = 100;
    uint16_t enter_tick = millis();

    TaskRunner::instance()->tick();

    uint16_t tick_time = millis() - enter_tick;
    if (tick_time < tick_delay)
        delay(tick_delay - tick_time);
}

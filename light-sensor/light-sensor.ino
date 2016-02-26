#include <Arduino.h>

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>

#include "subject.h"


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


class Looper
{
public:

    void Setup(void)
    {
        Serial.begin(9600);
    }

    void Loop(void)
    {
        Serial.print("light sensor: ");
        Serial.println(lightSensor.read());

        delay(5000);
    }

    // void Loop(void)
    // {
    //     if (flag = !flag)
    //         lightSensor.lightOn();
    //     else
    //         lightSensor.lightOff();

    //     delay(5000);
    // }


private:

    bool flag = false;

};


Looper looper;


void setup()
{
    looper.Setup();
}


void loop()
{
    looper.Loop();
}

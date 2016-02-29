#include <Arduino.h>

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>

#include "mcore.h"
#include "interfaces.h"
#include "mbotfactory.h"
#include "mbotbuilder.h"
#include "mbotdirector.h"
#include "scheduler.h"
#include "subject.h"
#include "robot.h"
#include "motion.h"
#include "ultrasonic.h"


Tickable *idleloop;
MBotFactory factory;


void createRobot(void)
{
    MBotBuilder     builder(factory);
    MBotDirector    director(builder);

    director.buildRobot();

    idleloop = Robot::instance()->idleloop();
}


void setup()
{
    Serial.begin(9600);

    createRobot();

    Serial.println("Setup complete.");
}


void loop()
{
    uint16_t enter_tick = millis();

    idleloop->tick();

    uint16_t tick_time = millis() - enter_tick;
    if (tick_time < tick_delay)
        delay(tick_delay - tick_time);
}

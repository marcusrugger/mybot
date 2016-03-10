#include <Arduino.h>

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>

#include "mcore.h"
#include "interfaces.h"
#include "mbot.factory.h"
#include "mbot.builder.h"
#include "mbot.director.h"
#include "robot.h"


static Runnable *idleloop;
static MBotFactory factory;


void createRobot(void)
{
    MBotBuilder     builder(factory);
    MBotDirector    director(builder);

    director.buildRobot();
}


void setup()
{
    Serial.begin(9600);

    createRobot();
    idleloop = Robot::instance()->idleloop();

    Serial.println("Setup complete.");
}


void loop()
{
    idleloop->run();
}

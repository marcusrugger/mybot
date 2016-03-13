#include <Arduino.h>

#include "mcore.h"
#include "interfaces.h"
#include "mbot.factory.h"
#include "mbot.builder.h"
#include "mbot.director.h"
#include "robot.h"


static Runnable *idleloop;
static ORION_PINMAP pinmap;
static MBotFactory factory(&pinmap);


void createRobot(void)
{
    MBotBuilder builder(factory);
    MBotDirector::buildOrion(builder);
}


void setup()
{
    Serial.begin(9600);

    createRobot();
    idleloop = Robot::instance()->idleloop();
}


void loop()
{
    idleloop->run();
}

#include "mcore.h"
#include "mbot.director.h"
#include "robot.h"
#include "subject.base.h"


void MBotDirector::buildMBot(RobotBuilder &builder)
{
    builder.buildCommandQueue();
    builder.buildCommandButtonProcessor();
    builder.buildUltrasonicProcessor();
    builder.buildLightProcessor();
    builder.buildBlinker();
    // builder.buildBuzzer();
}


void MBotDirector::buildOrion(RobotBuilder &builder)
{
    builder.buildCommandQueue();
    builder.buildUltrasonicProcessor();
}


void MBotDirector::buildThermometer(RobotBuilder &builder)
{
    builder.buildDisplayCounter();
}

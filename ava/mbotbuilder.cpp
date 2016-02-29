#include "mcore.h"
#include "mbotbuilder.h"
#include "robot.h"
#include "subject.h"


MBotBuilder::MBotBuilder(RobotFactory &factory)
:   _factory(factory),
    _robot(Robot::createRobot(factory))
{}


void MBotBuilder::buildRobot(void)
{
    _factory.buildButtonProcessor();
    _factory.buildUltrasonicProcessor();
}

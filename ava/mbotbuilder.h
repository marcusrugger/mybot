#ifndef MBOTBUILDER_H
#define MBOTBUILDER_H

#include "interfaces.h"

class Robot;


class MBotBuilder
{
public:

    MBotBuilder(RobotFactory &factory);

    void buildRobot(void);


private:

    RobotFactory &_factory;
    Robot *_robot;


    void buildButtonProcessor(void);

};


#endif

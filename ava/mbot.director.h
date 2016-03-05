#ifndef MBOTDIRECTOR_H
#define MBOTDIRECTOR_H

#include "interfaces.h"

class Robot;


class MBotDirector
{
public:

    MBotDirector(RobotBuilder &builder);

    void buildRobot(void);


private:

    RobotBuilder &_builder;

};


#endif

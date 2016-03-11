#ifndef COMMAND_BUZZER_H
#define COMMAND_BUZZER_H

#include "interfaces.h"


class BuzzerCommand : public Command
{
public:

    static bool queue(void);

    void execute(void);

};

#endif

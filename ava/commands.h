#ifndef COMMANDS_H
#define COMMANDS_H

#include "interfaces.h"


class MBotStateContext;


class MBotCommand : public Command
{
protected:

    MBotCommand(MBotStateContext *machine);

    MBotStateContext *_machine;

};


class ButtonPressedCommand : public MBotCommand
{
public:

    ButtonPressedCommand(MBotStateContext *machine) : MBotCommand(machine) {}

    void execute(void);

};


class ButtonReleasedCommand : public MBotCommand
{
public:

    ButtonReleasedCommand(MBotStateContext *machine) : MBotCommand(machine) {}

    void execute(void);

};


class FrontPathBlockedCommand : public MBotCommand
{
public:

    FrontPathBlockedCommand(MBotStateContext *machine) : MBotCommand(machine) {}

    void execute(void);

};


class FrontPathClearedCommand : public MBotCommand
{
public:

    FrontPathClearedCommand(MBotStateContext *machine) : MBotCommand(machine) {}

    void execute(void);

};


#endif

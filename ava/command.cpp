#include "commands.h"
#include "statemachine.h"


MBotCommand::MBotCommand(MBotStateContext *machine)
:   _machine(machine)
{}


void ButtonPressedCommand::execute(void)
{
    _machine->buttonPressed();
}


void ButtonReleasedCommand::execute(void)
{
    _machine->buttonReleased();
}


void FrontPathBlockedCommand::execute(void)
{
    _machine->frontPathBlocked();
}


void FrontPathClearedCommand::execute(void)
{
    _machine->frontPathCleared();
}

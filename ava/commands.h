#ifndef COMMANDS_H
#define COMMANDS_H

#include "interfaces.h"
#include "commandqueue.h"


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


class MoveCommand : public Command
{
public:

    enum DIRECTION
    {
        STOP,
        FORWARD,
        REVERSE,
        ROTATE_LEFT,
        ROTATE_RIGHT
    };

    MoveCommand(DIRECTION dir, Moveable *move, CommandQueue *queue = NULL, int milli = 0);
    MoveCommand(DIRECTION dir, int milli = 0);

    void execute(void);


private:

    DIRECTION _direction;
    Moveable *_move;
    CommandQueue *_queue;
    int _milli;

};


#endif

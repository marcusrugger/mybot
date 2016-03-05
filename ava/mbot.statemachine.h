#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "interfaces.h"
#include "robot.h"
#include "commandqueue.h"

class MBotStateContext;


class MBotStateMachine
{
public:

    virtual void buttonPressed(MBotStateContext *context);
    virtual void buttonReleased(MBotStateContext *context);
    virtual void frontPathBlocked(MBotStateContext *context);
    virtual void frontPathCleared(MBotStateContext *context);

};


class MBotStateContext
{
public:

    static MBotStateContext *instance(void);

    MBotStateContext(void);

    void buttonPressed(void);
    void buttonReleased(void);
    void frontPathBlocked(void);
    void frontPathCleared(void);

    void changeState(MBotStateMachine *state);
    bool queueChangeState(MBotStateMachine *state);


public:

    Command *buttonPressedCommand(void);
    Command *buttonReleasedCommand(void);
    Command *frontPathBlockedCommand(void);
    Command *frontPathClearedCommand(void);


public:

    bool isButtonPressed(void);
    void setButtonPressed(bool flag);

    bool isPathBlocked(void);
    void setPathBlocked(bool flag);


private:

    static MBotStateContext *_instance;
    MBotStateMachine *_state;

    bool _isButtonPressed;    
    bool _isPathBlocked;


    class ChangeStateCommand : public Command
    {
    public:

        static bool queue(MBotStateContext *context, MBotStateMachine *state)
        {
            return Robot::instance()->commandQueue()->add(new ChangeStateCommand(context, state));
        }

        void execute(void)
        {
            _context->changeState(_state);
        }

    private:

        ChangeStateCommand(MBotStateContext *context, MBotStateMachine *state) : _context(context), _state(state) {}

        MBotStateContext *_context;
        MBotStateMachine *_state;

    };


    class MBotCommand : public Command
    {
    protected:

        MBotCommand(MBotStateContext *machine) : _machine(machine) {}

        MBotStateContext *_machine;

    };


    class ButtonPressedCommand : public MBotCommand
    {
    public:

        ButtonPressedCommand(MBotStateContext *machine) : MBotCommand(machine) {}

        void execute(void)
        { _machine->buttonPressed(); }

    };


    class ButtonReleasedCommand : public MBotCommand
    {
    public:

        ButtonReleasedCommand(MBotStateContext *machine) : MBotCommand(machine) {}

        void execute(void)
        { _machine->buttonReleased(); }

    };


    class FrontPathBlockedCommand : public MBotCommand
    {
    public:

        FrontPathBlockedCommand(MBotStateContext *machine) : MBotCommand(machine) {}

        void execute(void)
        { _machine->frontPathBlocked(); }

    };


    class FrontPathClearedCommand : public MBotCommand
    {
    public:

        FrontPathClearedCommand(MBotStateContext *machine) : MBotCommand(machine) {}

        void execute(void)
        { _machine->frontPathCleared(); }

    };

};


class MBotIdleState : public MBotStateMachine
{
public:

    static MBotStateMachine *instance(void);

    void buttonReleased(MBotStateContext *context);
    void frontPathCleared(MBotStateContext *context);

private:

    static MBotStateMachine *_instance;

};


class MBotMovingState : public MBotStateMachine
{
public:

    static MBotStateMachine *instance(void);

    void buttonPressed(MBotStateContext *context);
    void frontPathBlocked(MBotStateContext *context);

private:

    static MBotStateMachine *_instance;

};


class MBotBlockedPathState : public MBotStateMachine
{
public:

    static MBotStateMachine *instance(void);

private:

    static MBotStateMachine *_instance;

};


#endif

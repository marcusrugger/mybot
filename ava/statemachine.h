#ifndef STATEMACHINE_H
#define STATEMACHINE_H


class MBotStateContext;


class MBotStateMachine
{
public:

    virtual void buttonPressed(MBotStateContext *context) = 0;
    virtual void buttonReleased(MBotStateContext *context) = 0;
    virtual void frontPathBlocked(MBotStateContext *context) = 0;
    virtual void frontPathCleared(MBotStateContext *context) = 0;

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


public:

    bool isPathBlocked(void);
    void setPathBlocked(bool flag);


private:

    static MBotStateContext *_instance;
    MBotStateMachine *_state;
    bool _isPathBlocked;

};


class MBotIdleState : public MBotStateMachine
{
public:

    static MBotStateMachine *instance(void);

    void buttonPressed(MBotStateContext *context);
    void buttonReleased(MBotStateContext *context);
    void frontPathBlocked(MBotStateContext *context);
    void frontPathCleared(MBotStateContext *context);

private:

    static MBotStateMachine *_instance;

};


class MBotMovingState : public MBotStateMachine
{
public:

    static MBotStateMachine *instance(void);

    void buttonPressed(MBotStateContext *context);
    void buttonReleased(MBotStateContext *context);
    void frontPathBlocked(MBotStateContext *context);
    void frontPathCleared(MBotStateContext *context);

private:

    static MBotStateMachine *_instance;

};


class MBotBlockedPathState : public MBotStateMachine
{
public:

    static MBotStateMachine *instance(void);

    void buttonPressed(MBotStateContext *context);
    void buttonReleased(MBotStateContext *context);
    void frontPathBlocked(MBotStateContext *context);
    void frontPathCleared(MBotStateContext *context);

private:

    static MBotStateMachine *_instance;

};


#endif

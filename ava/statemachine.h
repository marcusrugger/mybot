#ifndef STATEMACHINE_H
#define STATEMACHINE_H


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

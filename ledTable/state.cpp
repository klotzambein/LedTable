#include "state.h"
#include "Arduin.h"

#define GOTO_STATE(id)   \
    do                   \
    {                    \
        changeState(id); \
        break;           \
    } while (0);
#define REPEAT_STATE \
    break;

#define S_INIT 0
#define S_LEDTEST 1

struct
{
    uint8_t id;
    union {
        struct
        {
            uint8_t t;
        } ledTest;
    } data;
} State;
uint8_t nxtStateID = 255;

void changeState(uint8_t nxt);


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//    - - - - - - - - - - - - - - - - - - - - - - - - - -

void stateMachine()
{
    switch (State.id)
    {
        case S_INIT:
        GOTO_STATE(S_LEDTEST)
        case S_LEDTEST:
    }
    
    if (nxtStateID != 255)
    {
        State.id = nxtStateID;
        nxtStateID = 255;
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//    - - - - - - - - - - - - - - - - - - - - - - - - - -

void settupStateMachine()
{
    State.id = STATE_INIT;
}

void changeState(uint8_t nxt)
{
    nxtStateID = nxt;
}
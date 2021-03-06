#include "state.h"
#include "leds.h"
#include "pixelText.h"

#define GOTO_STATE(id) \
    changeState(id);   \
    break;
#define GOTO_STATE_DATA(id, data) \
    changeState(id, data);   \
    break;
#define REPEAT_STATE(dur)           \
    nextStateTime = millis() + dur; \
    break;

#define S_INIT 0
#define S_LEDTEST 1

struct
{
    uint8_t id;
    union {
        struct
        {
            uint16_t scroll;
            uint8_t hue;
        } ledTest;
    } data;
} State;
uint32_t nextStateTime = 0;

void changeState(uint8_t next);
void changeState(uint8_t next, void *data);

//                      m   a  v   e  r   i  c  k   STOP
const uint8_t text[] = {13, 8, 2, 14, 36, 8, 17, 18, 19, 36, 6, 4, 8, 11, 18, 19, 4, 0xFF};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//  - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//    - - - - - - - - - - - - - - - - - - - - - - - - - -

void stateMachine(uint8_t stateID = 255)
{
    if (millis() < nextStateTime && stateID == 255)
        return;

    // Run State
    switch ((stateID == 255) ? State.id : stateID)
    {
    case S_INIT:
        leds_init();
        GOTO_STATE(S_LEDTEST)

    case S_LEDTEST:
        for (uint16_t i = 0; i < LEDS_NUM; i++)
            setHSV_Z(i, (i + State.data.ledTest.hue) % 256, 255, 50);

        //State.data.ledTest.scroll = drawPixelTextScrolling(&text[0], State.data.ledTest.scroll, 0);

        leds_show();

        State.data.ledTest.hue += 2;
        REPEAT_STATE(30)
    }
}

//    - - - - - - - - - - - - - - - - - - - - - - - - - -
//  - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void settupStateMachine()
{
    State.id = S_INIT;
    delay(1); // Ensures that millis never returns Zero (ignoring overflow)
}

void changeState(uint8_t next, void *data)
{
    State.id = next;
    //Data Reset Logic
    switch (State.id)
    {
    case S_LEDTEST:
        State.data.ledTest.scroll = 0;
        State.data.ledTest.hue = 0;
        break;
    }
}
void changeState(uint8_t next)
{
    changeState(next, (void *)0);
}
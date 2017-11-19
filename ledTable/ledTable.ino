#include "leds.h"
#include "pixelText.h"

void setup()
{
    leds_init();
    //leds_test();
}

//                      m   a  v   e  r   i  c  k   STOP
const uint8_t text[] = {13, 8, 2, 14, 36, 8, 17, 18, 19, 36, 6, 4, 8, 11, 18, 19, 4, 0xFF};

uint8_t h = 0;
uint8_t t = 0;
void loop()
{
    for (uint16_t i = 0; i < LEDS_NUM; i++)
        setHSV_Z(i, (i + h) % 256, 255, 100);

    t = drawPixelTextScrolling(&text[0], t, 0);

    leds_show();

    delay(50);
    h += 2;
}
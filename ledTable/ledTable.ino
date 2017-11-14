#include "leds.h"
#include "pixelText.h"

void setup()
{
    leds_init();
    //leds_test();
}

//                      m   a  v   e  r   i  c  k
const uint8_t text[] = {12, 0, 21, 4, 17, 8, 2, 10, 0xFF};

uint8_t h = 0;
void loop()
{
    for (uint16_t i = 0; i < LEDS_NUM; i++)
        setHSV_Z(i, (i + h) % 256, 255, 127);

    drawPixelText(&text[0], 1, 1);

    setRGB(3, 3, 0, 255, 0);
    setRGB(3, 4, 255, 0, 0);
    setRGB(4, 3, 0, 0, 255);
    setRGB(4, 4, 0, 255, 255);

    leds_show();

    delay(100);
    h += 2;
}
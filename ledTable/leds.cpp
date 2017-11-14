#include "leds.h"

CRGB leds[LEDS_NUM];

void leds_init()
{
    FastLED.addLeds<LEDS_TYPE, LEDS_DATA_PIN, LEDS_ORDER>(leds, LEDS_NUM);
    delay(10);
    FastLED.show();
}

void leds_test()
{
    for (int i = 0; i < LEDS_NUM; i++)
        leds[i].setRGB(random(0, 100), random(0, 100), random(100, 256));
    FastLED.show();
}

#include "leds.h"

CRGB leds[LEDS_NUM];

void leds_init()
{
    FastLED.addLeds<LEDS_TYPE, LEDS_DATA_PIN, LEDS_ORDER>(leds, LEDS_NUM);
    delay(10);
    FastLED.show();
}

void leds_show()
{
    FastLED.show();
}
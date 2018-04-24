#ifndef LEDS_h
#define LEDS_h

#include "Arduino.h"

#define FASTLED_ALLOW_INTERRUPTS 0
#define FASTLED_INTERRUPT_RETRY_COUNT 2
#include "FastLED.h"

#define LEDS_DATA_PIN 17
#define LEDS_WIDTH 16
#define LEDS_HEIGHT 22
#define LEDS_NUM LEDS_HEIGHT *LEDS_WIDTH
#define LEDS_TYPE WS2812B
#define LEDS_ORDER GRB

extern CRGB leds[LEDS_NUM];

inline void setRGB(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b)
{
    if (y & 0x01)
        leds[y * LEDS_WIDTH + x].setRGB(r, g, b);
    else
        leds[(y | 0x01) * LEDS_WIDTH - 1 - x].setRGB(r, g, b);
}
inline void setHSV(uint8_t x, uint8_t y, uint8_t h, uint8_t s, uint8_t v)
{
    if (y & 0x01)
        leds[y * LEDS_WIDTH + x].setHSV(h, s, v);
    else
        leds[(y | 0x01) * LEDS_WIDTH - 1 - x].setHSV(h, s, v);
}
//ZigZag
inline void setRGB_Z(uint8_t i, uint8_t r, uint8_t g, uint8_t b)
{
    leds[i].setRGB(r, g, b);
}
inline void setHSV_Z(uint16_t i, uint8_t h, uint8_t s, uint8_t v)
{
    leds[i].setHSV(h, s, v);
}

void leds_show();
void leds_init();

#endif
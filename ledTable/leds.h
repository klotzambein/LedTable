#ifndef LEDS_h
#define LEDS_h

#import "Arduino.h"

#define FASTLED_ALLOW_INTERRUPTS 1
#define FASTLED_INTERRUPT_RETRY_COUNT 2
#import "FastLED.h"

#define LEDS_DATA_PIN 17
/*#define LEDS_WIDTH 32
#define LEDS_HEIGHT 32
#define LEDS_NUM LEDS_HEIGHT * LEDS_WIDTH*/
#define LEDS_NUM 60
#define LEDS_TYPE WS2812B
#define LEDS_ORDER GRB

extern CRGB leds[LEDS_NUM];

void leds_test();
void leds_init();

#endif
#ifndef LEDS_h
#define LEDS_h

#import "Arduino.h"
#import "FastLED.h"

#define LEDS_DATA_PIN 17
//#define LEDS_WIDTH 32
//#define LEDS_HEIGHT 32
//#define LEDS_NUM LEDS_HEIGHT * LEDS_WIDTH
#define LEDS_NUM 10

extern CRGB leds[LEDS_NUM];

void leds_test();
void leds_init();

#endif
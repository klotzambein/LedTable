//#import "leds.h"

#import "FastLED.h"

#define LEDS_DATA_PIN 17
//#define LEDS_WIDTH 32
//#define LEDS_HEIGHT 32
//#define LEDS_NUM LEDS_HEIGHT * LEDS_WIDTH
#define LEDS_NUM 60 * 2

CRGB leds[LEDS_NUM];

void setup()
{
    FastLED.addLeds<WS2812B, LEDS_DATA_PIN>(leds, LEDS_NUM);
    FastLED.show();
}
uint8_t h = 0;
void loop()
{
    for (uint16_t i = 0; i < LEDS_NUM; i++)
        leds[i].setHSV((i + h) % 256, 255, 100);
    FastLED.show();

    h++;
    delay(50);
}
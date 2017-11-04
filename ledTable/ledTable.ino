#import "leds.h"

void setup()
{
    leds_init();
    leds_test();
}
uint8_t h = 0;
void loop()
{
    for (uint16_t i = 0; i < LEDS_NUM; i++)
        leds[i].setHSV((i + h) % 256, 255, 100);
    FastLED.show();

    h++;*/
    leds_test();
    delay(500);
} 
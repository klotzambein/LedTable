#import "leds.h"

void setup()
{
    leds_init();
    //leds_test();
}
uint8_t h = 0;
uint8_t k = 0;
void loop()
{
    for (uint16_t i = 0; i < LEDS_NUM; i++)
        leds[i].setHSV((i + h) % 256, 255, 127);

    for (uint16_t i = k; i < LEDS_NUM && i < k + 10; i++)
        leds[i].setRGB(255, 255, 255);

    FastLED.show();
    delay(50);

    if (--k > 197)
        k = 197;
    h++;
}
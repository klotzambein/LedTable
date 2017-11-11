#import "leds.h"

void setup()
{
    leds_init();
    //leds_test();
}
uint8_t h = 0;
void loop()
{
    for (uint16_t i = 0; i < LEDS_NUM; i++)
        leds[i].setHSV(h + i, 255, 50);
    leds[random(0, 99)].setRGB(255, 0, 0);
    leds[random(0, 99)].setRGB(0, 255, 0);
    leds[random(0, 99)].setRGB(0, 0, 255);
    FastLED.show();
    delay(50);

    h++;
}
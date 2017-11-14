#include "pixelText.h"
#include "leds.h"

void drawPixelText(const uint8_t *text, int xStart, int yStart)
{
    while (*text != 0xFF && xStart < LEDS_WIDTH)
    {
        if (xStart >= -3)
        {
            if (xStart >= LEDS_WIDTH)
                return;
            for (int x = 0, xReal = xStart;
                 x < letters[*text].width + 1; 
                 x++, xReal++)
            {
                for (int y = 0, yReal = yStart;
                     y < 5;
                     y++, yReal++)
                {
                    if (xReal < 0 || xReal >= LEDS_WIDTH ||
                        yReal < 0 || yReal >= LEDS_HEIGHT)
                        continue;
                    if (letters[*text].row[y >> 1] >> (((y & 0x1) ? 4 : 0) + x) & 0x1)
                        setRGB(xReal, yReal, 0xFF, 0xFF, 0xFF);
                }
            }
        }
        xStart += letters[*text].width + 2;
        text++;
    }
}
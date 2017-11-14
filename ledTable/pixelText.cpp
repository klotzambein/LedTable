#include "pixelText.h"
#include "leds.h"

void drawPixelText(uint8_t *text, int xStart, int yStart)
{
    while (*text != 0xFF)
    {
        if (xStart >= -3)
        {
            if (xStart >= LEDS_WIDTH)
                return;
            int xReal = xStart;
            int yReal = yStart;
            for (int x = 0; x < letters[*text].width + 1; x++)
            {
                for (int y = 0; y < 5; y++)
                {
                    if (xReal < 0 || xReal >= LEDS_WIDTH ||
                        yReal < 0 || yReal >= LEDS_HEIGHT)
                        continue;
                    if (letters[*text].row[y >> 1] >> (((y & 0x1) ? 0 : 4) + x) & 0x1)
                        setRGB(xReal, yReal, 0xFF, 0xFF, 0xFF);
                }
            }
        }
        xStart += letters[*text].width + 2;
        text++;
    }
}
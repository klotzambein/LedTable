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

uint16_t getPixelTextLength(const uint8_t *text)
{
    uint16_t length = 0;
    while (*text != 0xFF)
    {
        length += letters[*text++].width + 2;
    }
    if (length >= 1)
        length--;
    return length;
}

uint8_t drawPixelTextScrolling(const uint8_t *text, uint8_t t, int yStart)
{
    uint16_t length = getPixelTextLength(text);

    if (length <= LEDS_WIDTH)
    {
        drawPixelText(text, 0, yStart);
        return 0;
    }
    drawPixelText(text, -t, yStart);
    drawPixelText(text, length + 4 - t, yStart);
    return (t + 1) % (length + 4);
}
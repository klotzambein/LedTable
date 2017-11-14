#ifndef PIXELTEXT_H
#define PIXELTEXT_H

#include "Arduino.h"

//text ends with 0xFF
void drawPixelText(const uint8_t *text, int xStart, int yStart);

struct Letter
{
    union {
        struct
        {
            unsigned b00 : 1;
            unsigned b10 : 1;
            unsigned b20 : 1;
            unsigned b30 : 1;
            unsigned b01 : 1;
            unsigned b11 : 1;
            unsigned b21 : 1;
            unsigned b31 : 1;
            unsigned b02 : 1;
            unsigned b12 : 1;
            unsigned b22 : 1;
            unsigned b32 : 1;
            unsigned b03 : 1;
            unsigned b13 : 1;
            unsigned b23 : 1;
            unsigned b33 : 1;
            unsigned b04 : 1;
            unsigned b14 : 1;
            unsigned b24 : 1;
            unsigned b34 : 1;
            unsigned width : 2;
        };
        struct
        {
            uint8_t row[3];
        };
    };
} const letters[]{
    /*const Letter letter_A = */
    {0, 1, 1, 0,
     1, 0, 0, 1,
     1, 1, 1, 1,
     1, 0, 0, 1,
     1, 0, 0, 1,
     3},
    /*const Letter letter_B = */
    {1, 1, 1, 0,
     1, 0, 0, 1,
     1, 1, 1, 0,
     1, 0, 0, 1,
     1, 1, 1, 0,
     3},
    /*const Letter letter_C = */
    {0, 1, 1, 1,
     1, 0, 0, 0,
     1, 0, 0, 0,
     1, 0, 0, 0,
     0, 1, 1, 1,
     3},
    /*const Letter letter_D = */
    {1, 1, 1, 0,
     1, 0, 0, 1,
     1, 0, 0, 1,
     1, 0, 0, 1,
     1, 1, 1, 0,
     3},
    /*const Letter letter_E = */
    {1, 1, 1, 1,
     1, 0, 0, 0,
     1, 1, 1, 0,
     1, 0, 0, 0,
     1, 1, 1, 1,
     3},
    /*const Letter letter_F = */
    {1, 1, 1, 1,
     1, 0, 0, 0,
     1, 1, 1, 0,
     1, 0, 0, 0,
     1, 0, 0, 0,
     3},
    /*const Letter letter_G = */
    {0, 1, 1, 1,
     1, 0, 0, 0,
     1, 0, 1, 1,
     1, 0, 0, 1,
     0, 1, 1, 1,
     3},
    /*const Letter letter_H = */
    {1, 0, 0, 1,
     1, 0, 0, 1,
     1, 1, 1, 1,
     1, 0, 0, 1,
     1, 0, 0, 1,
     3},
    /*const Letter letter_I = */
    {1, 1, 1, 0,
     0, 1, 0, 0,
     0, 1, 0, 0,
     0, 1, 0, 0,
     1, 1, 1, 0,
     2},
    /*const Letter letter_J = */
    {0, 0, 0, 1,
     0, 0, 0, 1,
     0, 0, 0, 1,
     1, 0, 0, 1,
     0, 1, 1, 0,
     3},
    /*const Letter letter_K = */
    {1, 0, 0, 1,
     1, 0, 1, 0,
     1, 1, 0, 0,
     1, 0, 1, 0,
     1, 0, 0, 1,
     3},
    /*const Letter letter_L = */
    {1, 0, 0, 0,
     1, 0, 0, 0,
     1, 0, 0, 0,
     1, 0, 0, 0,
     1, 1, 1, 0,
     2},
    /*const Letter letter_M = */
    {1, 0, 0, 1,
     1, 1, 1, 1,
     1, 0, 0, 1,
     1, 0, 0, 1,
     1, 0, 0, 1,
     3},
    /*const Letter letter_N = */
    {1, 0, 0, 1,
     1, 0, 0, 1,
     1, 1, 0, 1,
     1, 0, 1, 1,
     1, 0, 0, 1,
     3},
    /*const Letter letter_O = */
    {0, 1, 1, 0,
     1, 0, 0, 1,
     1, 0, 0, 1,
     1, 0, 0, 1,
     0, 1, 1, 0,
     3},
    /*const Letter letter_P = */
    {1, 1, 1, 0,
     1, 0, 0, 1,
     1, 1, 1, 0,
     1, 0, 0, 0,
     1, 0, 0, 0,
     3},
    /*const Letter letter_Q = */
    {0, 1, 1, 0,
     1, 0, 0, 1,
     1, 0, 0, 1,
     1, 0, 1, 1,
     0, 1, 1, 1,
     3},
    /*const Letter letter_R = */
    {1, 1, 1, 0,
     1, 0, 0, 1,
     1, 1, 1, 0,
     1, 0, 1, 0,
     1, 0, 0, 1,
     3},
    /*const Letter letter_S = */
    {0, 1, 1, 1,
     1, 0, 0, 0,
     0, 1, 1, 0,
     0, 0, 0, 1,
     1, 1, 1, 0,
     3},
    /*const Letter letter_T = */
    {1, 1, 1, 0,
     0, 1, 0, 0,
     0, 1, 0, 0,
     0, 1, 0, 0,
     0, 1, 0, 0,
     2},
    /*const Letter letter_U = */
    {1, 0, 0, 1,
     1, 0, 0, 1,
     1, 0, 0, 1,
     1, 0, 0, 1,
     1, 1, 1, 1,
     3},
    /*const Letter letter_V = */
    {1, 0, 0, 1,
     1, 0, 0, 1,
     1, 0, 0, 1,
     1, 0, 0, 1,
     0, 1, 1, 0,
     3},
    /*const Letter letter_W = */
    {1, 0, 0, 1,
     1, 0, 0, 1,
     1, 0, 0, 1,
     1, 0, 0, 1,
     1, 1, 1, 1,
     3},
    /*const Letter letter_X = */
    {1, 0, 0, 1,
     1, 0, 0, 1,
     0, 1, 1, 0,
     0, 1, 1, 0,
     1, 0, 0, 1,
     3},
    /*const Letter letter_Y = */
    {1, 0, 1, 0,
     1, 0, 1, 0,
     1, 1, 1, 0,
     0, 1, 0, 0,
     0, 1, 0, 0,
     2},
    /*const Letter letter_Z = */
    {1, 1, 1, 1,
     0, 0, 0, 1,
     0, 0, 1, 0,
     0, 1, 0, 0,
     1, 1, 1, 1,
     3},
    /*const Letter letter_0 = */
    {0, 1, 1, 0,
     1, 0, 0, 1,
     1, 0, 0, 1,
     1, 0, 0, 1,
     0, 1, 1, 0,
     3},
    /*const Letter letter_1 = */
    {1, 1, 0, 0,
     0, 1, 0, 0,
     0, 1, 0, 0,
     0, 1, 0, 0,
     1, 1, 1, 0,
     2},
    /*const Letter letter_2 = */
    {0, 1, 1, 0,
     1, 0, 0, 1,
     0, 0, 1, 0,
     0, 1, 0, 0,
     1, 1, 1, 1,
     3},
    /*const Letter letter_3 = */
    {0, 1, 1, 0,
     1, 0, 0, 1,
     0, 0, 1, 0,
     1, 0, 0, 1,
     0, 1, 1, 0,
     3},
    /*const Letter letter_4 = */
    {1, 0, 0, 1,
     1, 0, 0, 1,
     1, 1, 1, 1,
     0, 0, 0, 1,
     0, 0, 0, 1,
     3},
    /*const Letter letter_5 = */
    {1, 1, 1, 1,
     1, 0, 0, 0,
     1, 1, 1, 0,
     0, 0, 0, 1,
     1, 1, 1, 0,
     3},
    /*const Letter letter_6 = */
    {0, 1, 1, 0,
     1, 0, 0, 0,
     1, 1, 1, 0,
     1, 0, 0, 1,
     0, 1, 1, 0,
     3},
    /*const Letter letter_7 = */
    {1, 1, 1, 1,
     0, 0, 0, 1,
     0, 0, 1, 0,
     0, 1, 0, 0,
     0, 1, 0, 0,
     3},
    /*const Letter letter_8 = */
    {0, 1, 1, 0,
     1, 0, 0, 1,
     0, 1, 1, 0,
     1, 0, 0, 1,
     0, 1, 1, 0,
     3},
    /*const Letter letter_9 = */
    {0, 1, 1, 0,
     1, 0, 0, 1,
     0, 1, 1, 1,
     0, 0, 0, 1,
     0, 1, 1, 0,
     3},
    /*const Letter letter_Space = */
    {0, 0, 0, 0,
     0, 0, 0, 0,
     0, 0, 0, 0,
     0, 0, 0, 0,
     0, 0, 0, 0,
     0},
};

#endif
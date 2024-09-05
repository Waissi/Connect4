#ifndef _GLOBALS_H
#define _GLOBALS_H

#include "raylib.h"

#define BOARD_COLOR DARKBLUE;
#define SLOT_WIDTH 40
#define SLOT_HEIGHT 40
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

extern struct Color currentPlayer;

static bool compare_color(struct Color color1, struct Color color2)
{
    return color1.r == color2.r && color1.g == color2.g && color1.b == color2.b && color1.a == color2.a;
}

#endif
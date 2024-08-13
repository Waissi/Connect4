#ifndef _GLOBALS_H
#define _GLOBALS_H

#include "raylib.h"

#define BOARD_COLOR DARKBLUE;
#define SLOT_WIDTH 40
#define SLOT_HEIGHT 40
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

extern struct Color currentPlayer;

bool compare_color(struct Color color1, struct Color color2);

#endif
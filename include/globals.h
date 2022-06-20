#ifndef _GLOBALS_H
#define _GLOBALS_H

#include "raylib.h"

#define BOARD_COLOR DARKBLUE; 
#define SLOT_WIDTH 40
#define SLOT_HEIGHT 40

extern struct Vector2 WINDOW;
extern struct Color player;

bool CompareColor(struct Color color1, struct Color color2);

#endif
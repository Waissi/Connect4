#ifndef _BOARD_H
#define _BOARD_H

#include "raylib.h"
#include "globals.h"
#include <stdio.h>

struct Slot
{
    struct Rectangle drawRec;
    struct Color slotColor;
    struct Color tokenColor;
};

struct Token
{
    int row;
    int column;
};

#define BOARD_ROWS 6
#define BOARD_COLUMNS 7

void init_board();
void draw_board();
bool last_move_wins();
void on_mouse_moved();
bool on_mouse_pressed();

#endif
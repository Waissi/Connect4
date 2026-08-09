#ifndef _BOARD_H
#define _BOARD_H

#include "raylib.h"
#include <stdio.h>

struct Slot {
  struct Rectangle drawRec;
  struct Color slotColor;
  struct Color tokenColor;
};

struct Token {
  int row;
  int column;
};

#define BOARD_ROWS 6
#define BOARD_COLUMNS 7

void init_board(void);
void draw_board(void);
bool last_move_wins(void);
void on_mouse_moved(void);
bool on_mouse_pressed(void);

#endif

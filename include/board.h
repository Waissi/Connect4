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

void InitBoard();
void DrawBoard();
bool CheckVictory();
void CheckMouseOnBoard();
bool CheckMousePressed();

#endif
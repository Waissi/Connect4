#ifndef _BOARD_H
#define _BOARD_H

#include "raylib.h"
#include "globals.h"
#include <stdio.h>
#include "slot.h"

struct Token
{
    int row;
    int column;
};

#define BOARD_ROWS 6
#define BOARD_COLUMNS 7

void InitBoard();
void DrawBoard();
void ReleaseBoard();
bool CheckVictory();
void CheckMouseOnBoard();
bool CheckMousePressed();

#endif
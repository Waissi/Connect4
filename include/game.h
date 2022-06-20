#ifndef GAME
#define GAME

#include <stdlib.h>
#include "raylib.h"
#include "globals.h"
#include "board.h"
#include "fmodManager.h"
#include "hud.h"

void UpdateGame();
void DrawGame();
void NextTurn();

void LoadGame();
void LoopGame();
void ReleaseGame();

#endif
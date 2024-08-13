#include "game.h"

bool gameOver = false;
struct Color currentPlayer = YELLOW;
const char *yellowPlays = "YELLOW IS PLAYING";
const char *redPlays = "RED IS PLAYING";
const char *yellowWins = "YELLOW WINS";
const char *redWins = "RED WINS";
const char *message = NULL;

static void UpdateGame()
{
    CheckMouseOnBoard();
    if (IsMouseButtonPressed(0) && CheckMousePressed())
    {
        gameOver = CheckVictory();
        if (gameOver)
        {
            message = CompareColor(currentPlayer, YELLOW) ? yellowWins : redWins;
            return;
        }
        currentPlayer = CompareColor(currentPlayer, YELLOW) ? RED : YELLOW;
        message = CompareColor(currentPlayer, YELLOW) ? yellowPlays : redPlays;
    }
}

static void DrawGame()
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText(message, 0, 0, 20, currentPlayer);
    DrawBoard();
    EndDrawing();
}

void LoadGame()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Connect 4");
    InitBoard();
    message = yellowPlays;
}

void LoopGame()
{
    while (!WindowShouldClose())
    {
        if (!gameOver)
            UpdateGame();
        DrawGame();
    }
}

void ReleaseGame()
{
    CloseWindow();
}
#include "../include/game.h"

struct Vector2 WINDOW;
struct Color player = YELLOW;
enum State{PLAY, VICTORY};
enum State gameState = PLAY;
struct Hud* hud = NULL;
const char* yellowPlayerMessage = "YELLOW PLAYER IS PLAYING";
const char* redPlayerMessage = "RED PLAYER IS PLAYING";
const char* yellowPlayerWins = "YELLOW PLAYER WINS";
const char* redPlayerWins = "RED PLAYER WINS";

void NextTurn()
{
    if (CompareColor(player, YELLOW))
    {
        player = RED;
        hud->message = redPlayerMessage;
        return;
    }
    player = YELLOW;
    hud->message = yellowPlayerMessage;
}

void LoadGame()
{
    WINDOW.x = 800;
    WINDOW.y = 600;
    InitWindow(WINDOW.x, WINDOW.y, "Connect 4");
    InitBoard();
    InitFmod();
    hud = Hud();
    hud->message = yellowPlayerMessage;
    //LoadBank("fmod/banks/Desktop/Master.bank");
	//LoadBank("fmod/banks/Desktop/Master.strings.bank");
    //PlayOneShotEvent("event:/Test");
}

void UpdateGame()
{   
    UpdateFmod();
    switch (gameState)
    {
    case PLAY:
        CheckMouseOnBoard();
        if (IsMouseButtonPressed(0))
        {
            if (CheckMousePressed())
            {
                if (CheckVictory())
                {
                    gameState = VICTORY;
                    if (CompareColor(player, YELLOW))
                    {
                        hud->message = yellowPlayerWins;
                        return;
                    }
                    hud->message = redPlayerWins;
                    return;
                }
                NextTurn();
            }
        }
        break;
        
    case VICTORY:
        break;
    }
}

void DrawGame()
{
    BeginDrawing();
    ClearBackground(BLACK);
    hud->draw(hud);
    DrawBoard();
    EndDrawing();
}

void LoopGame()
{
    while (!WindowShouldClose())
    {
        UpdateGame();
        DrawGame();
    }
}

void ReleaseGame()
{
    free(hud);
    ReleaseBoard();
    ReleaseFmod();
    CloseWindow();
}
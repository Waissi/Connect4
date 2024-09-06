#include "game.h"

bool gameOver = false;
struct Color currentPlayer = YELLOW;
const char *yellowPlays = "YELLOW IS PLAYING";
const char *redPlays = "RED IS PLAYING";
const char *yellowWins = "YELLOW WINS";
const char *redWins = "RED WINS";
const char *restart = "PRESS ENTER TO START NEW GAME";
const char *message = NULL;

static void update()
{
    if (gameOver)
    {
        if (IsKeyPressed(KEY_ENTER))
            load_game();
        return;
    }
    on_mouse_moved();
    if (IsMouseButtonPressed(0) && on_mouse_pressed())
    {
        if (last_move_wins())
        {
            gameOver = true;
            message = compare_color(currentPlayer, YELLOW) ? yellowWins : redWins;
            return;
        }
        currentPlayer = compare_color(currentPlayer, YELLOW) ? RED : YELLOW;
        message = compare_color(currentPlayer, YELLOW) ? yellowPlays : redPlays;
    }
}

static void draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText(message, WINDOW_WIDTH / 2 - MeasureText(message, 20) / 2, 0, 20, currentPlayer);
    if (gameOver)
    {
        DrawText(restart, WINDOW_WIDTH / 2 - MeasureText(restart, 20) / 2, 40, 20, RAYWHITE);
    }
    draw_board();
    EndDrawing();
}

void load_game()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Connect 4");
    init_board();
    message = yellowPlays;
    gameOver = false;
}

void run_game()
{
    while (!WindowShouldClose())
    {
        update();
        draw();
    }
}

void release_game()
{
    CloseWindow();
}
#include "game.h"

bool gameOver = false;
struct Color currentPlayer = YELLOW;
const char *yellowPlays = "YELLOW IS PLAYING";
const char *redPlays = "RED IS PLAYING";
const char *yellowWins = "YELLOW WINS";
const char *redWins = "RED WINS";
const char *message = NULL;

static void update()
{
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
    DrawText(message, 0, 0, 20, currentPlayer);
    draw_board();
    EndDrawing();
}

void load_game()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Connect 4");
    init_board();
    message = yellowPlays;
}

void loop_game()
{
    while (!WindowShouldClose())
    {
        if (!gameOver)
            update();
        draw();
    }
}

void release_game()
{
    CloseWindow();
}
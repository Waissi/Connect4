#include "board.h"

struct Slot board[BOARD_ROWS][BOARD_COLUMNS];
struct Token lastMove;

static bool diagonal_sw_ne_wins()
{
    int total = 0;
    int rowOrigin = lastMove.row;
    int columnOrigin = lastMove.column;
    while (rowOrigin < BOARD_ROWS - 1 && columnOrigin > 0)
    {
        rowOrigin++;
        columnOrigin--;
    }
    while (rowOrigin > -1 && columnOrigin < BOARD_COLUMNS)
    {
        struct Color currentColor = board[rowOrigin][columnOrigin].tokenColor;
        if (compare_color(currentColor, currentPlayer))
        {
            total++;
            if (total == 4)
            {
                board[0][lastMove.column].slotColor = DARKBLUE;
                return true;
            }
        }
        else
        {
            total = 0;
        }
        rowOrigin--;
        columnOrigin++;
    }
    return false;
}

static bool diagonal_se_nw_wins()
{
    int total = 0;
    int rowOrigin = lastMove.row;
    int columnOrigin = lastMove.column;
    while (rowOrigin < BOARD_ROWS - 1 && columnOrigin < BOARD_COLUMNS - 1)
    {
        rowOrigin++;
        columnOrigin++;
    }
    while (rowOrigin > -1 && columnOrigin > -1)
    {
        struct Color currentColor = board[rowOrigin][columnOrigin].tokenColor;
        if (compare_color(currentColor, currentPlayer))
        {
            total++;
            if (total == 4)
            {
                board[0][lastMove.column].slotColor = DARKBLUE;
                return true;
            }
        }
        else
        {
            total = 0;
        }
        rowOrigin--;
        columnOrigin--;
    }
    return false;
}

static bool horizontal_wins()
{
    int total = 0;
    struct Color currentColor;
    for (int column = 0; column < BOARD_COLUMNS; column++)
    {
        currentColor = board[lastMove.row][column].tokenColor;
        if (compare_color(currentColor, currentPlayer))
        {
            total++;
            if (total == 4)
            {
                board[0][lastMove.column].slotColor = DARKBLUE;
                return true;
            }
        }
        else
        {
            total = 0;
        }
    }
    return false;
}

static bool vertical_wins()
{
    int total = 0;
    struct Color currentColor;
    for (int row = 0; row < BOARD_ROWS; row++)
    {
        currentColor = board[row][lastMove.column].tokenColor;
        if (compare_color(currentColor, currentPlayer))
        {
            total++;
            if (total == 4)
            {
                board[0][lastMove.column].slotColor = DARKBLUE;
                return true;
            }
        }
        else
        {
            total = 0;
        }
    }
    return false;
}

static bool is_column_full(int column)
{
    return (!compare_color(board[0][column].tokenColor, BLACK));
}

static void fill_column(int column)
{
    for (int row = BOARD_ROWS - 1; row > -1; row--)
    {
        if (compare_color(board[row][column].tokenColor, BLACK))
        {
            board[row][column].tokenColor = currentPlayer;
            lastMove.row = row;
            lastMove.column = column;
            if (is_column_full(column))
            {
                board[row][column].slotColor = DARKBLUE;
            }
            return;
        }
    }
}

bool last_move_wins()
{
    return horizontal_wins() || vertical_wins() || diagonal_sw_ne_wins() || diagonal_se_nw_wins();
}

bool on_mouse_pressed()
{
    for (int column = 0; column < BOARD_COLUMNS; column++)
    {
        if (compare_color(board[0][column].slotColor, currentPlayer))
        {
            fill_column(column);
            return true;
        }
    }
    return false;
}

void on_mouse_moved()
{
    for (int column = 0; column < BOARD_COLUMNS; column++)
    {
        if (CheckCollisionPointRec(GetMousePosition(), board[0][column].drawRec))
        {
            if (is_column_full(column))
            {
                return;
            }
            board[0][column].slotColor = currentPlayer;
        }
        else
        {
            board[0][column].slotColor = DARKBLUE;
        }
    }
}

void init_board()
{
    int posX = WINDOW_WIDTH / 2 - SLOT_WIDTH * BOARD_COLUMNS / 2;
    int posY = WINDOW_HEIGHT / 2 - SLOT_HEIGHT * BOARD_ROWS / 2;
    for (int row = 0; row < BOARD_ROWS; row++)
    {
        for (int column = 0; column < BOARD_COLUMNS; column++)
        {
            int x = posX + SLOT_WIDTH * column;
            int y = posY + SLOT_HEIGHT * row;
            board[row][column] = (struct Slot){
                .drawRec = {
                    .x = x,
                    .y = y,
                    .height = SLOT_HEIGHT - 2,
                    .width = SLOT_WIDTH - 2},
                .tokenColor = BLACK,
                .slotColor = DARKBLUE,
            };
            ;
        }
    }
}

void draw_board()
{
    for (int row = 0; row < BOARD_ROWS; row++)
    {
        for (int column = 0; column < BOARD_COLUMNS; column++)
        {
            struct Slot slot = board[row][column];
            DrawRectangleRec(slot.drawRec, slot.slotColor);
            DrawCircle(slot.drawRec.x + SLOT_WIDTH / 2 - 1, slot.drawRec.y + SLOT_HEIGHT / 2 - 1, 16, slot.tokenColor);
        }
    }
}
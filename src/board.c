#include "board.h"

struct Slot board[BOARD_ROWS][BOARD_COLUMNS];
struct Token lastMove;

static bool _CheckDiagonalBottomLeftToUpRight()
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
        if (CompareColor(currentColor, currentPlayer))
        {
            total++;
            if (total == 4)
            {
                board[0][lastMove.column].slotColor = BOARD_COLOR;
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

static bool _CheckDiagonalBottomRightToUpLeft()
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
        if (CompareColor(currentColor, currentPlayer))
        {
            total++;
            if (total == 4)
            {
                board[0][lastMove.column].slotColor = BOARD_COLOR;
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

static bool _CheckHorizontal()
{
    int total = 0;
    struct Color currentColor;
    for (int column = 0; column < BOARD_COLUMNS; column++)
    {
        currentColor = board[lastMove.row][column].tokenColor;
        if (CompareColor(currentColor, currentPlayer))
        {
            total++;
            if (total == 4)
            {
                board[0][lastMove.column].slotColor = BOARD_COLOR;
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

static bool _CheckVertical()
{
    int total = 0;
    struct Color currentColor;
    for (int row = 0; row < BOARD_ROWS; row++)
    {
        currentColor = board[row][lastMove.column].tokenColor;
        if (CompareColor(currentColor, currentPlayer))
        {
            total++;
            if (total == 4)
            {
                board[0][lastMove.column].slotColor = BOARD_COLOR;
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

static bool _IsColumnFull(int column)
{
    return (!CompareColor(board[0][column].tokenColor, BLACK));
}

static void _FillColumn(int column)
{
    for (int row = BOARD_ROWS - 1; row > -1; row--)
    {
        if (CompareColor(board[row][column].tokenColor, BLACK))
        {
            board[row][column].tokenColor = currentPlayer;
            lastMove.row = row;
            lastMove.column = column;
            if (_IsColumnFull(column))
            {
                board[row][column].slotColor = BOARD_COLOR;
            }
            return;
        }
    }
}

bool CheckVictory()
{
    if (_CheckHorizontal())
    {
        return true;
    }
    if (_CheckVertical())
    {
        return true;
    }
    if (_CheckDiagonalBottomLeftToUpRight())
    {
        return true;
    }
    if (_CheckDiagonalBottomRightToUpLeft())
    {
        return true;
    }
    return false;
}

bool CheckMousePressed()
{
    for (int column = 0; column < BOARD_COLUMNS; column++)
    {
        if (CompareColor(board[0][column].slotColor, currentPlayer))
        {
            _FillColumn(column);
            return true;
        }
    }
    return false;
}

void CheckMouseOnBoard()
{
    for (int column = 0; column < BOARD_COLUMNS; column++)
    {
        if (CheckCollisionPointRec(GetMousePosition(), board[0][column].drawRec))
        {
            if (_IsColumnFull(column))
            {
                return;
            }
            board[0][column].slotColor = currentPlayer;
        }
        else
        {
            board[0][column].slotColor = BOARD_COLOR;
        }
    }
}

void InitBoard()
{
    int posX = WINDOW_WIDTH / 2 - SLOT_WIDTH * BOARD_COLUMNS / 2;
    int posY = WINDOW_HEIGHT / 2 - SLOT_HEIGHT * BOARD_ROWS / 2;
    for (int row = 0; row < BOARD_ROWS; row++)
    {
        for (int column = 0; column < BOARD_COLUMNS; column++)
        {
            int x = posX + SLOT_WIDTH * column;
            int y = posY + SLOT_HEIGHT * row;
            struct Slot newSlot;
            newSlot.drawRec.x = x;
            newSlot.drawRec.y = y;
            newSlot.drawRec.height = SLOT_HEIGHT - 2;
            newSlot.drawRec.width = SLOT_WIDTH - 2;
            newSlot.slotColor = BOARD_COLOR;
            newSlot.tokenColor = BLACK;
            board[row][column] = newSlot;
        }
    }
}

void DrawBoard()
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
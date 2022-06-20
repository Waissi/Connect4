#include "../include/slot.h"

static void _DrawSlot(struct Slot* _slot)
{
    DrawRectangleRec(_slot->drawRec, _slot->slotColor);
    DrawCircle(_slot->drawRec.x + SLOT_WIDTH/2 - 1, _slot->drawRec.y + SLOT_HEIGHT/2 - 1, 16, _slot->tokenColor);
}

struct Slot* Slot(int _x, int _y)
{
    struct Slot* newSlot = (struct Slot*) malloc(sizeof(struct Slot));
    newSlot->drawRec.x = _x;
    newSlot->drawRec.y = _y;
    newSlot->drawRec.height = SLOT_HEIGHT - 2;
    newSlot->drawRec.width = SLOT_WIDTH - 2;
    newSlot->slotColor = BOARD_COLOR;
    newSlot->tokenColor = BLACK;
    newSlot->draw = _DrawSlot;
    return newSlot;
}
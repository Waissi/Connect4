#ifndef _SLOT_H
#define _SLOT_H

#include <stdlib.h>
#include "raylib.h"
#include "globals.h"

struct Slot
{
    struct Rectangle drawRec;
    struct Color slotColor;
    struct Color tokenColor;
    void(*draw)(struct Slot*);
};

struct Slot* Slot(int _x, int _y);

#endif
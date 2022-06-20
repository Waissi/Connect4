#ifndef _HUD_H
#define _HUD_H

#include <stdlib.h>
#include "raylib.h"
#include "globals.h"

struct Hud
{
    const char* message;
    void(*draw)(struct Hud*);
};

struct Hud* Hud();

#endif
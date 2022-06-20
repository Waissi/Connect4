#include "../include/hud.h"

static void _DrawHud(struct Hud* _hud)
{
    DrawText(_hud->message, 0, 0, 20, player);
}

struct Hud* Hud()
{
    struct Hud* newHud = (struct Hud*) malloc(sizeof(struct Hud));
    newHud->draw = _DrawHud;
    return newHud;
}
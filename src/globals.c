#include "globals.h"

bool CompareColor(struct Color color1, struct Color color2)
{
    return color1.r == color2.r && color1.g == color2.g && color1.b == color2.b && color1.a == color2.a;
}
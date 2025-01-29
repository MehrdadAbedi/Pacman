#ifndef INITIAL_FUNCTIONS_H
#define INITIAL_FUNCTIONS_H

#include "structures.h"

int rounds(int numerator, int denominator, float border);
Rectangle ghost_rec(Ghost *ghost);
int collison_check(GameElements *game_elements);
int scroll_wheel();

#endif
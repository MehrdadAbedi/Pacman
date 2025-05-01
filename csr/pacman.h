#ifndef PACMAN_H
#define PACMAN_H

#include "initial_functions.h"

void teleport(GameElements *game_elements);
void pacman_location(GameElements *game_elements);
int pacman_move(GameElements *game_elements);
int count_health(GameElements *game_elements);

#endif
#ifndef GHOSTS_H
#define GHOSTS_H

#include "initial_functions.h"

int good_place(int row, int col, GameElements *game_elements, int rows, int cols, int visited[rows][cols]);
int rounds(int numerator, int denominator, float border);
Point find_next_step(Ghost *ghost, GameElements *game_elements);
void random_position(Ghost *ghost, GameElements *game_elements);
void init_direction(Ghost *ghost, GameElements *game_elements);
void init_ghosts_map(Ghosts *ghosts, GameElements *game_elements);
int random_direction(Ghost *ghost, GameElements *game_elements, int *current_row, int *current_col, Timer *time);
int ghost_move(GameElements *game_elements, Ghost *ghost);
void chase_pacman(Ghost *ghost, GameElements *game_elements);

#endif
#ifndef FRUITS_H
#define FRUITS_H

#include "structures.h"

void random_position_fruits(Ghost *ghost, GameElements *game_elements);
void init_direction_fruits(Ghost *ghost, GameElements *game_elements);
void init_fruit(Fruit *fruit, GameElements *game_elements);
int fruit_collison(GameElements *game_elements, Fruit *fruit);
void apple(GameElements *game_elements);
void mushroom(GameElements *game_elements);
int pepper(GameElements *game_elements);
void pepper_handling(GameElements *game_elements);
Rectangle ghost_rec_fruit(Ghost *ghost);
void eating_ghost(GameElements *game_elements);
void cherry_handling(GameElements *game_elements);

#endif
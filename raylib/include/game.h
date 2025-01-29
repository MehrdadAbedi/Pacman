#ifndef GAME_H
#define GAME_H

#include "ghosts.h"
#include "window.h"
#include "fruits.h"
#include "menu.h"
#include "pacman.h"

void star(GameElements *game_elements, int number);
int count_star(GameElements *game_elements, int number);
int clean_stars(GameElements *game_elements);
void vis_health(GameElements *game_elements);
void draw_screen(GameElements *game_elements);
void update(GameElements *game_elements);
int clean_stars(GameElements *game_elements);
void init_game(GameElements *game_elements);
int start_game(GameElements *game_elements);
void choose_map(GameElements *game_elements, Texture classic_mode, Texture fantasy_mode, Texture rotated_mode);
void game();

#endif
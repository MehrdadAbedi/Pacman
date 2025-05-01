#ifndef WINDOW_H
#define WINDOW_H

#include "structures.h"

void initializeBoard(GameElements *game_elements);
void freeBoard(GameElements *game_elements);
void load_game(GameElements *game_elements);
void load_sounds(GameElements *game_elements);
void load_records(GameElements *game_elements);
void load_setting(GameElements *game_elements);
void init_menu(GameElements *game_elements);
void unload_sounds(GameElements *game_elements);
void unload_setting(GameElements *game_elements);
void unload_game1(GameElements *game_elements);
void unload_records(GameElements *game_elements);
void create_window(Window *window);
void get_map(const char *filename, GameElements *game_elements);
void show_map1(GameElements *game_elements);
void show_map2(GameElements *game_elements);
void show_map3(GameElements *game_elements);

#endif
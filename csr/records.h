#ifndef RECORDS_H
#define RECORDS_H

#include "initial_functions.h"

void swap(GameInfo **info_array, int i, int j);
int sort_array(GameInfo **info_array, int end, int sort_code);
void save_data(const char *filename, GameInfo *game_info);
int read_data(const char *filename, GameInfo **info_array);
void sort_system(GameElements *GameElements, GameInfo **info_array);
void date_sort(GameInfo **info_array, int end);
void time_sort(GameInfo **info_array, int end);
int vis_records(const char *filename, GameElements *game_elements);

#endif
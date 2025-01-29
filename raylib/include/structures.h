#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define stars 10
#define HEALTH 3

extern int scores;

typedef struct {
    int row;
    int col;
} Point;
typedef struct {
    Texture window;
    Texture sounds;
    Texture music;
    Texture hard;
    Texture medium;
    Texture easy;
    Color background[3];
    int i;
} Setting;
typedef struct {
    int rows;
    int cols;
} BoardSize;
typedef struct {
    int i;
    int j;
    Texture2D fruit_texture;
    Texture2D fruit_texture80;
    float time;
    bool ability_flag;
    bool exist_flag;
} Fruit;
typedef struct {
    Fruit *Apple;
    Fruit *Mushroom;
    Fruit *Pepper;
    Fruit *Cherry;
} Fruits;
typedef struct {
    float time_mouth;
    bool time_flag_mouth;
    float time_direction;
} Timer;
typedef struct {
    Texture2D ghost_up;
    Texture2D ghost_down;
    Texture2D ghost_right;
    Texture2D ghost_left;
    int i;
    int j;
    float time;
    char direction;
    bool exist_flag;
    bool blink_flag;
} Ghost;
typedef struct {
    Ghost *red_ghost;
    Ghost *blue_ghost;
    Ghost *green_ghost;
    Ghost *pink_ghost;
    Ghost *yellow_ghost;
    Ghost *brown_ghost;
    Ghost *fire_red_ghost;    
    Ghost *fire_blue_ghost;
    int ghost_speed;
    int random;
} Ghosts;
typedef struct {
    Texture2D pacman_te;
    Texture2D pacman_up;
    Texture2D pacman_down;
    Texture2D pacman_right;
    Texture2D pacman_left;
    Texture2D heart;
    Texture flash;
    Vector2 flash_position;
    float i;
    float j;
    float time;
    bool flash_flag;
    bool exist_flag;
    bool blink_flag;
    char direction;
    char last_direction;
    int health;
    int speed;
    int flash_move;
} Pacman;
typedef struct {
    Texture2D row_border;
    Texture2D column_border;
    Texture2D down_left_border;
    Texture2D up_left_border;
    Texture2D up_right_border;
    Texture2D down_right_border;
    RenderTexture2D tranparent_layer;
    Texture cyclone[12];
    int I;
    Texture score_board;
    Texture hole;
    float time;
} Border;
typedef struct {
    Image icon;
    int width;
    int height;
    unsigned int flags;
    const char *window_name;
} Window;
typedef struct {
    bool start_flag;
    bool setting_flag;
    bool records_flag;
    bool last_games_flag;
    bool exit_flag;
    bool load_game_flag;
    bool load_records_flag;
    bool classic_map_flag;
    bool fantasy_map_flag;
    bool rotated_map_flag;
    bool game_over_flag;
    bool sounds_flag;
    bool music_flag;
    bool hard_flag;
    bool medium_flag;
    bool easy_flag;
    bool name_flag;
    bool window_name_flag;
    bool pause_flag;
} GameFlags;
typedef struct {
    Sound game_over;
    Sound eat_star;
    Sound eat_fruit;
    Sound eat_ghost;
    Sound ghost_colli;
    Sound click;
    Music game_music;
} Sounds;
typedef struct {
    Texture pacman_right;
    Texture pacman;
    Texture ghost;
    Texture back;
    Vector2 position;
    Vector2 star_position;
    Font font;
    int i;
    float star_time;
    char direction;
    float time;
    bool mouth_flag;
} Menu;
typedef struct {
    int minutes;
    int seconds;
    int game_scores;
    int pepper_num;
    int cherry_num;
    int apple_num;
    int mushroom_num;
    int ghost_eat;
    int mode_code;
    float time;
    int year;
    int month;
    int day;
    int hour;
    int min;
    int hardness;
    char *text;
} GameInfo;
typedef struct {
    Texture record_bar;
    Texture clock_off;
    Texture clock_on;
    Texture star_on;
    Texture star_off;
    Texture cherry_off;
    Texture cherry_on;
    Texture apple_off;
    Texture apple_on;
    Texture mushroom_off;
    Texture mushroom_on;
    Texture pepper_off;
    Texture pepper_on;    
    Texture ghost_eat_on;
    Texture ghost_eat_off;
    Texture date_on;
    Texture date_off;
    Texture time_on;
    Texture time_off;
    Texture medium;
    Texture hard;
    int up_down;
    int sort_code;
} Records;
typedef struct {
    Fruits *fruits;
    Timer *timer;
    Ghosts *ghosts;
    Pacman *pacman;
    Border *border;
    Window *window;
    Vector2 *zero_point;
    GameFlags *game_flags;
    Sounds *game_sounds;
    GameInfo *game_info;
    Records *records;
    Setting *setting;
    Menu *menu;
    BoardSize *board_size;
    char *player;
    int **Board;
    int i;
} GameElements;

#endif
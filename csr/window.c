#ifndef WINDOW_H
#define WINDOW_H

#include "structures.h"


void initializeBoard(GameElements *game_elements) 
{
    int rows = game_elements->board_size->rows;
    int cols = game_elements->board_size->cols;

    game_elements->Board = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        game_elements->Board[i] = malloc(cols * sizeof(int));
    }
}
void freeBoard(GameElements *game_elements) {
    int rows = game_elements->board_size->rows;

    for (int i = 0; i < rows; i++) {
        free(game_elements->Board[i]);
    }
    free(game_elements->Board);
}
void load_game(GameElements *game_elements)
{
    //pacman
    game_elements->pacman->pacman_te = LoadTexture("./images/pacman-close-mouth.png");
    game_elements->pacman->pacman_up = LoadTexture("./images/pacman-up.png");
    game_elements->pacman->pacman_down = LoadTexture("./images/pacman-down.png");
    game_elements->pacman->pacman_right = LoadTexture("./images/pacman-right.png");
    game_elements->pacman->pacman_left = LoadTexture("./images/pacman-left.png");
    game_elements->pacman->heart = LoadTexture("./images/heart.png");
    game_elements->pacman->flash = LoadTexture("./images/flash.png");
    //borders
    game_elements->border->column_border = LoadTexture("./images/column_border.png");
    game_elements->border->row_border = LoadTexture("./images/row_border.png");
    game_elements->border->down_left_border = LoadTexture("./images/down-left_border.png");
    game_elements->border->down_right_border = LoadTexture("./images/down-right_border.png");
    game_elements->border->up_right_border = LoadTexture("./images/up-right_border.png");
    game_elements->border->up_left_border = LoadTexture("./images/up-left_border.png");
    game_elements->border->hole = LoadTexture("./images/hole.png");
    //blue
    game_elements->ghosts->blue_ghost->ghost_up = LoadTexture("./images/blue-up.png");
    game_elements->ghosts->blue_ghost->ghost_down = LoadTexture("./images/blue-down.png");    
    game_elements->ghosts->blue_ghost->ghost_right = LoadTexture("./images/blue-right.png");    
    game_elements->ghosts->blue_ghost->ghost_left = LoadTexture("./images/blue-left.png");
    //red
    game_elements->ghosts->red_ghost->ghost_up = LoadTexture("./images/red-up.png");
    game_elements->ghosts->red_ghost->ghost_down = LoadTexture("./images/red-down.png");
    game_elements->ghosts->red_ghost->ghost_right = LoadTexture("./images/red-right.png");
    game_elements->ghosts->red_ghost->ghost_left = LoadTexture("./images/red-left.png");
    //brown
    game_elements->ghosts->brown_ghost->ghost_up = LoadTexture("./images/brown-up.png");  
    game_elements->ghosts->brown_ghost->ghost_down = LoadTexture("./images/brown-down.png");  
    game_elements->ghosts->brown_ghost->ghost_right = LoadTexture("./images/brown-right.png");  
    game_elements->ghosts->brown_ghost->ghost_left = LoadTexture("./images/brown-left.png");  
    //green
    game_elements->ghosts->green_ghost->ghost_up = LoadTexture("./images/green-up.png");
    game_elements->ghosts->green_ghost->ghost_down = LoadTexture("./images/green-down.png");
    game_elements->ghosts->green_ghost->ghost_right = LoadTexture("./images/green-right.png");
    game_elements->ghosts->green_ghost->ghost_left = LoadTexture("./images/green-left.png");
    //pink
    game_elements->ghosts->pink_ghost->ghost_up = LoadTexture("./images/pink-up.png");
    game_elements->ghosts->pink_ghost->ghost_down = LoadTexture("./images/pink-down.png");
    game_elements->ghosts->pink_ghost->ghost_right = LoadTexture("./images/pink-right.png");
    game_elements->ghosts->pink_ghost->ghost_left = LoadTexture("./images/pink-left.png");
    //yellow
    game_elements->ghosts->yellow_ghost->ghost_up = LoadTexture("./images/yellow-up.png");
    game_elements->ghosts->yellow_ghost->ghost_down = LoadTexture("./images/yellow-down.png");
    game_elements->ghosts->yellow_ghost->ghost_right = LoadTexture("./images/yellow-right.png");
    game_elements->ghosts->yellow_ghost->ghost_left = LoadTexture("./images/yellow-left.png");
    //fire red ghost
    game_elements->ghosts->fire_red_ghost->ghost_up = LoadTexture("./images/fire-up.png");
    game_elements->ghosts->fire_red_ghost->ghost_down = LoadTexture("./images/fire-down.png");
    game_elements->ghosts->fire_red_ghost->ghost_left = LoadTexture("./images/fire-left.png");
    game_elements->ghosts->fire_red_ghost->ghost_right = LoadTexture("./images/fire-right.png");
    //fire blue ghost
    game_elements->ghosts->fire_blue_ghost->ghost_up = LoadTexture("./images/fire1-up.png");
    game_elements->ghosts->fire_blue_ghost->ghost_down = LoadTexture("./images/fire1-down.png");
    game_elements->ghosts->fire_blue_ghost->ghost_right = LoadTexture("./images/fire1-right.png");
    game_elements->ghosts->fire_blue_ghost->ghost_left = LoadTexture("./images/fire1-left.png");    
    //fruits
    game_elements->fruits->Apple->fruit_texture = LoadTexture("./images/apple.png");
    game_elements->fruits->Mushroom->fruit_texture = LoadTexture("./images/mushroom.png");
    game_elements->fruits->Pepper->fruit_texture = LoadTexture("./images/pepper.png");
    game_elements->fruits->Pepper->fruit_texture80 = LoadTexture("./images/pepper-80.png");
    game_elements->fruits->Cherry->fruit_texture = LoadTexture("./images/cherry.png");
    game_elements->fruits->Cherry->fruit_texture80 = LoadTexture("./images/cherry-80.png");
    //cyclone
    game_elements->border->cyclone[0] = LoadTexture("./images/cyclone-1.png");
    game_elements->border->cyclone[1] = LoadTexture("./images/cyclone-2.png");
    game_elements->border->cyclone[2] = LoadTexture("./images/cyclone-3.png");
    game_elements->border->cyclone[3] = LoadTexture("./images/cyclone-4.png");
    game_elements->border->cyclone[4] = LoadTexture("./images/cyclone-5.png");
    game_elements->border->cyclone[5] = LoadTexture("./images/cyclone-6.png");
    game_elements->border->cyclone[6] = LoadTexture("./images/cyclone-7.png");
    game_elements->border->cyclone[7] = LoadTexture("./images/cyclone-8.png");
    game_elements->border->cyclone[8] = LoadTexture("./images/cyclone-9.png");
    game_elements->border->cyclone[9] = LoadTexture("./images/cyclone-10.png");
    game_elements->border->cyclone[10] = LoadTexture("./images/cyclone-11.png");    
    game_elements->border->cyclone[11] = LoadTexture("./images/cyclone-12.png");
    //back
    game_elements->border->score_board = LoadTexture("./images/end_game.png");
    game_elements->pacman->flash_move = 0;
}
void load_sounds(GameElements *game_elements)
{
    //sounds
    game_elements->game_sounds->game_over = LoadSound("./sounds/game_over.wav");
    game_elements->game_sounds->eat_star = LoadSound("./sounds/eat_star.wav");
    game_elements->game_sounds->eat_fruit = LoadSound("./sounds/eat_fruit.wav");
    game_elements->game_sounds->eat_ghost = LoadSound("./sounds/ghost_eat.wav");
    game_elements->game_sounds->ghost_colli = LoadSound("./sounds/go_to_ghost.wav");
    game_elements->game_sounds->click = LoadSound("./sounds/click.wav");
    game_elements->game_sounds->game_music = LoadMusicStream("./sounds/pacman-background-music.ogg");
}
void load_records(GameElements *game_elements)
{
    //records
    game_elements->records->record_bar = LoadTexture("./images/records_bar.png");
    game_elements->records->mushroom_off = LoadTexture("./images/mushroom_off.png");
    game_elements->records->cherry_off = LoadTexture("./images/cherry_off.png");
    game_elements->records->pepper_off = LoadTexture("./images/pepper_off.png");
    game_elements->records->star_off = LoadTexture("./images/star_off.png");
    game_elements->records->apple_off = LoadTexture("./images/apple_off.png");
    game_elements->records->ghost_eat_off = LoadTexture("./images/ghost_eat_off.png");
    game_elements->records->hard = LoadTexture("./images/hard.png");
    game_elements->records->medium = LoadTexture("./images/medium.png");
    game_elements->records->date_off = LoadTexture("./images/date_off.png");
    game_elements->records->time_off = LoadTexture("./images/time_off.png");

    //initialize
    game_elements->records->sort_code = 2;
    game_elements->records->up_down = 0;
}
void load_setting(GameElements *game_elements)
{
    game_elements->setting->window = LoadTexture("./images/setting.png");
    game_elements->setting->sounds_off = LoadTexture("./images/setting_sound.png");
    game_elements->setting->sounds_on = LoadTexture("./images/sound_on.png");
    game_elements->setting->music_off = LoadTexture("./images/setting-music.png");
    game_elements->setting->music_on = LoadTexture("./images/music_on.png");
    game_elements->setting->easy = LoadTexture("./images/setting-easy.png");
    game_elements->setting->medium = LoadTexture("./images/setting-medium.png");
    game_elements->setting->hard = LoadTexture("./images/setting-hard.png");
}
void init_menu(GameElements *game_elements) //becareful you should call this after creating window
{
    //records on
    game_elements->records->mushroom_on = LoadTexture("./images/mushroom_on.png");
    game_elements->records->cherry_on = LoadTexture("./images/cherry_on.png");
    game_elements->records->pepper_on = LoadTexture("./images/pepper_on.png");
    game_elements->records->star_on = LoadTexture("./images/star_on.png");
    game_elements->records->apple_on = LoadTexture("./images/apple_on.png");
    game_elements->records->ghost_eat_on = LoadTexture("./images/ghost_eat_on.png");
    game_elements->records->date_on = LoadTexture("./images/date_on.png");
    game_elements->records->time_on = LoadTexture("./images/time_on.png");
    game_elements->records->pacman_on = LoadTexture("./images/pacman_on.png");
    
    //loading textures
    game_elements->menu->pacman = LoadTexture("./images/big_pacman.png");
    game_elements->menu->pacman_right = LoadTexture("./images/big_pacman_right.png");
    game_elements->menu->ghost = LoadTexture("./images/big_red_ghost.png");
    game_elements->menu->back = LoadTexture("./images/back_to_menu.png");

    //initialize
    game_elements->menu->star_position.x = rand() % GetScreenWidth();
    game_elements->menu->star_position.y = rand() % GetScreenHeight();
    game_elements->menu->time = 0;
    game_elements->menu->mouth_flag = false;
    game_elements->menu->direction = 'r';
    game_elements->menu->star_time = 0;
    game_elements->menu->i = 0;
    game_elements->menu->position.x = game_elements->menu->star_position.x - 600;
    game_elements->menu->position.y = game_elements->menu->star_position.y;

    //initialize - setting
    game_elements->setting->background[0] = (Color){0, 0, 0, 255};
    game_elements->setting->background[1] = (Color){255, 255, 255, 255};
    game_elements->setting->background[2] = (Color){220, 175, 10, 255};
    game_elements->setting->i = 0;

}
void unload_menu(GameElements *game_elements)
{
    UnloadTexture(game_elements->menu->pacman); 
    UnloadTexture(game_elements->menu->pacman_right);
    UnloadTexture(game_elements->menu->ghost);
}
void unload_sounds(GameElements *game_elements)
{
    //sounds
    UnloadSound(game_elements->game_sounds->game_over); UnloadSound(game_elements->game_sounds->eat_star);
    UnloadSound(game_elements->game_sounds->eat_fruit); UnloadSound(game_elements->game_sounds->eat_ghost);
    UnloadSound(game_elements->game_sounds->ghost_colli); UnloadSound(game_elements->game_sounds->click);
}
void unload_setting(GameElements *game_elements)
{
    UnloadTexture(game_elements->setting->easy);
    UnloadTexture(game_elements->setting->hard);
    UnloadTexture(game_elements->setting->medium);
    UnloadTexture(game_elements->setting->music_off);
    UnloadTexture(game_elements->setting->sounds_off);
    UnloadTexture(game_elements->setting->music_on);
    UnloadTexture(game_elements->setting->sounds_on);
    UnloadTexture(game_elements->setting->window);
}
void unload_game1(GameElements *game_elements)
{
    //pacman
    UnloadTexture(game_elements->pacman->pacman_te); UnloadTexture(game_elements->pacman->pacman_up);
    UnloadTexture(game_elements->pacman->pacman_down); UnloadTexture(game_elements->pacman->pacman_left);
    UnloadTexture(game_elements->pacman->pacman_right); UnloadTexture(game_elements->pacman->heart);
    UnloadTexture(game_elements->pacman->flash);
    //border
    UnloadTexture(game_elements->border->column_border); UnloadTexture(game_elements->border->down_left_border); 
    UnloadTexture(game_elements->border->down_right_border); UnloadTexture(game_elements->border->row_border); 
    UnloadTexture(game_elements->border->up_left_border); UnloadTexture(game_elements->border->up_right_border);
    UnloadTexture(game_elements->border->score_board);
    //blue
    UnloadTexture(game_elements->ghosts->blue_ghost->ghost_up); UnloadTexture(game_elements->ghosts->blue_ghost->ghost_down);
    UnloadTexture(game_elements->ghosts->blue_ghost->ghost_right); UnloadTexture(game_elements->ghosts->blue_ghost->ghost_left);
    //red
    UnloadTexture(game_elements->ghosts->red_ghost->ghost_up); UnloadTexture(game_elements->ghosts->red_ghost->ghost_down);
    UnloadTexture(game_elements->ghosts->red_ghost->ghost_right); UnloadTexture(game_elements->ghosts->red_ghost->ghost_left);
    //brown
    UnloadTexture(game_elements->ghosts->brown_ghost->ghost_up); UnloadTexture(game_elements->ghosts->brown_ghost->ghost_down);
    UnloadTexture(game_elements->ghosts->brown_ghost->ghost_left); UnloadTexture(game_elements->ghosts->brown_ghost->ghost_right);
    //green
    UnloadTexture(game_elements->ghosts->green_ghost->ghost_up); UnloadTexture(game_elements->ghosts->green_ghost->ghost_down);
    UnloadTexture(game_elements->ghosts->green_ghost->ghost_right); UnloadTexture(game_elements->ghosts->green_ghost->ghost_left);
    //pink
    UnloadTexture(game_elements->ghosts->pink_ghost->ghost_up); UnloadTexture(game_elements->ghosts->pink_ghost->ghost_down);
    UnloadTexture(game_elements->ghosts->pink_ghost->ghost_right); UnloadTexture(game_elements->ghosts->pink_ghost->ghost_left);
    //yellow
    UnloadTexture(game_elements->ghosts->yellow_ghost->ghost_up); UnloadTexture(game_elements->ghosts->yellow_ghost->ghost_down);
    UnloadTexture(game_elements->ghosts->yellow_ghost->ghost_left); UnloadTexture(game_elements->ghosts->yellow_ghost->ghost_right); 
    //fire red ghost
    UnloadTexture(game_elements->ghosts->fire_red_ghost->ghost_up); UnloadTexture(game_elements->ghosts->fire_red_ghost->ghost_down);
    UnloadTexture(game_elements->ghosts->fire_red_ghost->ghost_right); UnloadTexture(game_elements->ghosts->fire_red_ghost->ghost_left);
    //fire blue ghost
    UnloadTexture(game_elements->ghosts->fire_blue_ghost->ghost_up); UnloadTexture(game_elements->ghosts->fire_blue_ghost->ghost_down);
    UnloadTexture(game_elements->ghosts->fire_blue_ghost->ghost_right); UnloadTexture(game_elements->ghosts->fire_blue_ghost->ghost_left);   
    //fruits
    UnloadTexture(game_elements->fruits->Apple->fruit_texture); UnloadTexture(game_elements->fruits->Mushroom->fruit_texture);
    UnloadTexture(game_elements->fruits->Pepper->fruit_texture); UnloadTexture(game_elements->fruits->Pepper->fruit_texture80);
    UnloadTexture(game_elements->fruits->Cherry->fruit_texture); UnloadTexture(game_elements->fruits->Cherry->fruit_texture80);
    //cyclone
    UnloadTexture(game_elements->border->cyclone[0]); UnloadTexture(game_elements->border->cyclone[6]);
    UnloadTexture(game_elements->border->cyclone[1]); UnloadTexture(game_elements->border->cyclone[7]);
    UnloadTexture(game_elements->border->cyclone[2]); UnloadTexture(game_elements->border->cyclone[8]);
    UnloadTexture(game_elements->border->cyclone[3]); UnloadTexture(game_elements->border->cyclone[9]);
    UnloadTexture(game_elements->border->cyclone[4]); UnloadTexture(game_elements->border->cyclone[10]);
    UnloadTexture(game_elements->border->cyclone[5]); UnloadTexture(game_elements->border->cyclone[11]);
}
void unload_records(GameElements *game_elements)
{
    //records
    UnloadTexture(game_elements->records->record_bar);
    UnloadTexture(game_elements->records->pepper_on); UnloadTexture(game_elements->records->pepper_off);
    UnloadTexture(game_elements->records->cherry_on); UnloadTexture(game_elements->records->cherry_off);
    UnloadTexture(game_elements->records->mushroom_off); UnloadTexture(game_elements->records->mushroom_on);
    UnloadTexture(game_elements->records->star_on); UnloadTexture(game_elements->records->star_off);
    UnloadTexture(game_elements->records->apple_on); UnloadTexture(game_elements->records->apple_off);
    UnloadTexture(game_elements->records->ghost_eat_on); UnloadTexture(game_elements->records->ghost_eat_off);
    UnloadTexture(game_elements->records->hard); UnloadTexture(game_elements->records->medium);
    UnloadTexture(game_elements->records->date_off); UnloadTexture(game_elements->records->date_on);
    UnloadTexture(game_elements->records->time_off); UnloadTexture(game_elements->records->time_on);
}
void create_window(Window *window)
{
    SetConfigFlags(window->flags);    
    InitWindow(window->width, window->height, window->window_name);
    SetWindowIcon(window->icon);       
}
void get_map(const char *filename, GameElements *game_elements)
{
    FILE *file = fopen(filename, "r");

    char line[1024];
    int row = 0;

    while (fgets(line, sizeof(line), file) && row < game_elements->board_size->rows) {
        int col = 0;
        char *token = strtok(line, ",");
        while (token && col < game_elements->board_size->cols) {
            game_elements->Board[row][col] = atoi(token);
            token = strtok(NULL, ",");
            col++;
        }
        row++;
    }

    fclose(file);
}
void show_map1(GameElements *game_elements)
{
    DrawTexture(game_elements->border->up_left_border, -1 * game_elements->BlockSize + game_elements->zero_point->x, -1 * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
    DrawTexture(game_elements->border->down_right_border, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->x, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
    DrawTexture(game_elements->border->down_left_border, -1 * game_elements->BlockSize + game_elements->zero_point->x, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
    DrawTexture(game_elements->border->up_right_border, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->x, -1 * game_elements->BlockSize + game_elements->zero_point->y, WHITE);

    for (int i = 0; i < game_elements->board_size->cols; i++) {
        DrawTexture(game_elements->border->row_border, i * game_elements->BlockSize + game_elements->zero_point->x, -1 * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
        DrawTexture(game_elements->border->row_border, i * game_elements->BlockSize + game_elements->zero_point->x, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
    }

    for (int j = 0; j < game_elements->board_size->rows; j++) {
        DrawTexture(game_elements->border->column_border, -game_elements->BlockSize + game_elements->zero_point->x, j * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
        DrawTexture(game_elements->border->column_border, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->x, j * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
    }

    for (int j = 0; j < game_elements->board_size->rows; j++) {
        for (int i = 0; i < game_elements->board_size->cols; i++) {
            if (game_elements->Board[j][i] == 1) {
                DrawRectangle(i * game_elements->BlockSize + game_elements->zero_point->x, j * game_elements->BlockSize + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize, BLUE);
            } else if (game_elements->Board[j][i] == 2) {
                DrawCircle(i * game_elements->BlockSize + game_elements->BlockSize / 2 + game_elements->zero_point->x, j * game_elements->BlockSize + game_elements->BlockSize / 2 + game_elements->zero_point->y, 15, RED);
            }
        }
    }
}
void show_map2(GameElements *game_elements)
{
    DrawTexture(game_elements->border->cyclone[(game_elements->border->I / 12) % 12], 8 * game_elements->BlockSize + game_elements->zero_point->x, 14 * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
    DrawTexture(game_elements->border->cyclone[(game_elements->border->I / 12) % 12], 18 * game_elements->BlockSize + game_elements->zero_point->x, 14 * game_elements->BlockSize + game_elements->zero_point->y, WHITE);    
    
    DrawTexture(game_elements->border->up_left_border, -game_elements->BlockSize + game_elements->zero_point->x, -game_elements->BlockSize + game_elements->zero_point->y, WHITE);
    DrawTexture(game_elements->border->down_right_border, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->x, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
    DrawTexture(game_elements->border->down_left_border, -game_elements->BlockSize + game_elements->zero_point->x, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
    DrawTexture(game_elements->border->up_right_border, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->x, -game_elements->BlockSize + game_elements->zero_point->y, WHITE);

    for (int i = 0; i < game_elements->board_size->cols; i++) {
        DrawTexture(game_elements->border->row_border, i * game_elements->BlockSize + game_elements->zero_point->x, -game_elements->BlockSize + game_elements->zero_point->y, WHITE);
        DrawTexture(game_elements->border->row_border, i * game_elements->BlockSize + game_elements->zero_point->x, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
    }

    for (int j = 0; j < game_elements->board_size->rows; j++) {
        DrawTexture(game_elements->border->column_border, -game_elements->BlockSize + game_elements->zero_point->x, j * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
        DrawTexture(game_elements->border->column_border, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->x, j * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
    }

    Color CREAM = { 255, 253, 208, 255 };
    for (int j = 0; j < game_elements->board_size->rows; j++) {
        for (int i = 0; i < game_elements->board_size->cols; i++) {
            if (game_elements->Board[j][i] == 1 && j > 8) {
                DrawRectangle(i * game_elements->BlockSize + game_elements->zero_point->x, j * game_elements->BlockSize + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize, CREAM);
            } 
            else if (game_elements->Board[j][i] == 1 && j <= 8) {
                DrawRectangle(i * game_elements->BlockSize + game_elements->zero_point->x, j * game_elements->BlockSize + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize, BROWN);
            } 
            else if (game_elements->Board[j][i] == 2) {
                DrawCircle(i * game_elements->BlockSize + game_elements->BlockSize / 2 + game_elements->zero_point->x, j * game_elements->BlockSize + game_elements->BlockSize / 2 + game_elements->zero_point->y, 15, RED);
            }
        }
    }

    for(int i = 8; i < 22; i++)
    {
        for(int j = 22; j < 28; j++)
        {
            if(game_elements->Board[j][i] == 1)
                DrawRectangle(i * game_elements->BlockSize + game_elements->zero_point->x, j * game_elements->BlockSize + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize, BROWN);
        }
    }

    for(int i = 8; i < 22; i++)
    {
        if(game_elements->Board[20][i] == 1)
            DrawRectangle(i * game_elements->BlockSize + game_elements->zero_point->x, 20 * game_elements->BlockSize + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize, BROWN);
    }

    for(int i = 8; i < 22; i++)
    {
        for(int j = 14; j < 18; j++)
        {
            if(game_elements->Board[j][i] == 1 && (i < 12 || i > 17))
                DrawRectangle(i * game_elements->BlockSize + game_elements->zero_point->x, j * game_elements->BlockSize + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize, BLUE);            
        }
    }

    for(int i = 13; i < 17; i++)
    {
        DrawRectangle(i * game_elements->BlockSize + game_elements->zero_point->x, 18 * game_elements->BlockSize + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize, ORANGE);
        DrawRectangle(i * game_elements->BlockSize + game_elements->zero_point->x, 19 * game_elements->BlockSize + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize, ORANGE);
    }

    for(int i = 0; i < 30; i++)
    {
        for(int j = 9; j < 13; j++)
        {
            if(game_elements->Board[j][i] == 1 && (i < 5 || i > 24))   
                DrawRectangle(i * game_elements->BlockSize + game_elements->zero_point->x, j * game_elements->BlockSize + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize, BROWN);
        }
    }
    game_elements->border->I++;
}
void show_map3(GameElements *game_elements)
{
    DrawTexture(game_elements->border->up_left_border, -game_elements->BlockSize + game_elements->zero_point->x, -game_elements->BlockSize + game_elements->zero_point->y, WHITE);
    DrawTexture(game_elements->border->down_right_border, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->x, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
    DrawTexture(game_elements->border->down_left_border, -game_elements->BlockSize + game_elements->zero_point->x, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
    DrawTexture(game_elements->border->up_right_border, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->x, -game_elements->BlockSize + game_elements->zero_point->y, WHITE);

    for (int i = 0; i < game_elements->board_size->cols; i++) {
        DrawTexture(game_elements->border->row_border, i * game_elements->BlockSize + game_elements->zero_point->x, -game_elements->BlockSize + game_elements->zero_point->y, WHITE);
        DrawTexture(game_elements->border->row_border, i * game_elements->BlockSize + game_elements->zero_point->x, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
    }

    for (int j = 0; j < game_elements->board_size->rows; j++) {
        DrawTexture(game_elements->border->column_border, -game_elements->BlockSize + game_elements->zero_point->x, j * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
        DrawTexture(game_elements->border->column_border, game_elements->board_size->rows * game_elements->BlockSize + game_elements->zero_point->x, j * game_elements->BlockSize + game_elements->zero_point->y, WHITE);
    }

    for (int j = 0; j < game_elements->board_size->rows; j++) {
        for (int i = 0; i < game_elements->board_size->cols; i++) {
            if (game_elements->Board[j][i] == 1) {
                DrawRectangle(i * game_elements->BlockSize + game_elements->zero_point->x, j * game_elements->BlockSize + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize, (Color) {50, 140, 22, 255});
            } else if (game_elements->Board[j][i] == 2) {
                DrawCircle(i * game_elements->BlockSize + game_elements->BlockSize / 2 + game_elements->zero_point->x, j * game_elements->BlockSize + game_elements->BlockSize / 2 + game_elements->zero_point->y, 15, YELLOW);
            }
        }
    }
}

#endif
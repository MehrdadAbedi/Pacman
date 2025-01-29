#ifndef FRUITS_H
#define FRUITS_H

#include "structures.h"

void random_position_fruits(Ghost *ghost, GameElements *game_elements)
{
    do {
        ghost->i = GetRandomValue(0, game_elements->board_size->cols - 1);
        ghost->j = GetRandomValue(0, game_elements->board_size->rows - 1);
    } while(game_elements->Board[ghost->j][ghost->i] == 1);
    ghost->i *= 40;
    ghost->j *= 40;
}
void init_direction_fruits(Ghost *ghost, GameElements *game_elements)
{
    if(game_elements->Board[ghost->j / 40 + 1][ghost->i / 40] == 0)
    {
        ghost->direction = 'd';
    }
    else if(game_elements->Board[ghost->j / 40 - 1][ghost->i / 40] == 0)
    {
        ghost->direction = 'u';
    }    
    else if(game_elements->Board[ghost->j / 40][ghost->i / 40 + 1] == 0)
    {
        ghost->direction = 'r';
    }    
    else if(game_elements->Board[ghost->j / 40][ghost->i / 40 - 1] == 0)
    {
        ghost->direction = 'l';
    }
}
void init_fruit(Fruit *fruit, GameElements *game_elements)
{
    do {
        fruit->i = rand() % game_elements->board_size->cols;
        fruit->j = rand() % game_elements->board_size->rows;
    } while(game_elements->Board[fruit->j][fruit->i] != 0);
    
    fruit->i *= 40;
    fruit->j *= 40;
}
int fruit_collison(GameElements *game_elements, Fruit *fruit)
{
    Rectangle pacman_rec = {game_elements->pacman->i, game_elements->pacman->j, 40, 40};
    Rectangle fruit_rec = {fruit->i, fruit->j, 40, 40};

    if(CheckCollisionRecs(pacman_rec, fruit_rec))
    {
        return 1;
    }
    return 0;
}
void apple(GameElements *game_elements)
{
    if(game_elements->fruits->Apple->exist_flag)
        DrawTexture(game_elements->fruits->Apple->fruit_texture, game_elements->fruits->Apple->i + game_elements->zero_point->x, game_elements->fruits->Apple->j + game_elements->zero_point->y, WHITE);
    if(fruit_collison(game_elements, game_elements->fruits->Apple) && game_elements->fruits->Apple->exist_flag)
    {
        PlaySound(game_elements->game_sounds->eat_fruit);
        game_elements->game_info->apple_num++;
        if(game_elements->pacman->health < 5)
            game_elements->pacman->health++;
        init_fruit(game_elements->fruits->Apple, game_elements);
        game_elements->fruits->Apple->exist_flag = false;
        game_elements->fruits->Apple->time = 0;
    }
    else if(!game_elements->fruits->Apple->exist_flag && game_elements->fruits->Apple->time >= 30)
    {
        game_elements->fruits->Apple->exist_flag = true;
    }
}
void mushroom(GameElements *game_elements)
{
    if(game_elements->fruits->Mushroom->exist_flag)  
        DrawTexture(game_elements->fruits->Mushroom->fruit_texture, game_elements->fruits->Mushroom->i + game_elements->zero_point->x, game_elements->fruits->Mushroom->j + game_elements->zero_point->y, WHITE);
    if(fruit_collison(game_elements, game_elements->fruits->Mushroom) && game_elements->fruits->Mushroom->exist_flag)
    {
        PlaySound(game_elements->game_sounds->eat_fruit);
        game_elements->game_info->mushroom_num++;
        game_elements->pacman->health--;
        init_fruit(game_elements->fruits->Mushroom, game_elements);
        game_elements->fruits->Mushroom->exist_flag = false;
        game_elements->fruits->Mushroom->time = 0;
    }
    else if(!game_elements->fruits->Mushroom->exist_flag && game_elements->fruits->Mushroom->time >= 5)
    {
        game_elements->fruits->Mushroom->exist_flag = true;
    }
}
int pepper(GameElements *game_elements)
{
    if(fruit_collison(game_elements, game_elements->fruits->Pepper))
    {
        game_elements->pacman->speed = 400;
        init_fruit(game_elements->fruits->Pepper, game_elements);
    }
}
void pepper_handling(GameElements *game_elements)
{
    if(!game_elements->fruits->Pepper->exist_flag && game_elements->fruits->Pepper->ability_flag && game_elements->fruits->Pepper->time >= 20)
    {
        game_elements->fruits->Pepper->time = 0;
        game_elements->pacman->speed = 250;
        game_elements->fruits->Pepper->ability_flag = false;
        game_elements->fruits->Pepper->exist_flag = false;
    }
    else if(!game_elements->fruits->Pepper->exist_flag && !game_elements->fruits->Pepper->ability_flag && game_elements->fruits->Pepper->time >= 30)
    {
        game_elements->fruits->Pepper->time = 0;
        game_elements->fruits->Pepper->ability_flag = false;
        game_elements->fruits->Pepper->exist_flag = true;
    }
    else if(game_elements->fruits->Pepper->exist_flag && !game_elements->fruits->Pepper->ability_flag && fruit_collison(game_elements, game_elements->fruits->Pepper))
    {
        PlaySound(game_elements->game_sounds->eat_fruit);
        game_elements->game_info->pepper_num++;
        game_elements->fruits->Pepper->time = 0;
        pepper(game_elements);
        game_elements->fruits->Pepper->ability_flag = true;
        game_elements->fruits->Pepper->exist_flag = false;
    }
    if(game_elements->fruits->Pepper->exist_flag && !game_elements->fruits->Pepper->ability_flag)
    {
        DrawTexture(game_elements->fruits->Pepper->fruit_texture, game_elements->fruits->Pepper->i + game_elements->zero_point->x, game_elements->fruits->Pepper->j + game_elements->zero_point->y, WHITE);
    }
    else if(!game_elements->fruits->Pepper->exist_flag && game_elements->fruits->Pepper->ability_flag)
    {
        const char *text = TextFormat("%.2f", 20 - game_elements->fruits->Pepper->time);
        const char *cherrytext = TextFormat("%.2f", 20 - game_elements->fruits->Cherry->time);
        Vector2 textsize = MeasureTextEx(game_elements->menu->font, text, 50, 1);
        Vector2 cherrytextsize = MeasureTextEx(game_elements->menu->font, cherrytext, 50, 1);
        if(game_elements->fruits->Cherry->ability_flag)
        {
            DrawTextEx(game_elements->menu->font, text, (Vector2) {(game_elements->board_size->cols) * 40 + game_elements->zero_point->x - 160 - textsize.x - cherrytextsize.x, -3 * 40 + game_elements->zero_point->y + 15},
            50, 1, YELLOW);
            DrawTexture(game_elements->fruits->Pepper->fruit_texture80, (game_elements->board_size->cols) * 40 + game_elements->zero_point->x - 260 - textsize.x - cherrytextsize.x, -3 * 40 + game_elements->zero_point->y, WHITE);
        }
        else
        {
            DrawTextEx(game_elements->menu->font, text, (Vector2) {(game_elements->board_size->cols) * 40 + game_elements->zero_point->x - 20 - textsize.x, -3 * 40 + game_elements->zero_point->y + 15}, 50, 1, YELLOW);        
            DrawTexture(game_elements->fruits->Pepper->fruit_texture80, (game_elements->board_size->cols) * 40 + game_elements->zero_point->x - 120 - textsize.x, -3 * 40 + game_elements->zero_point->y, WHITE);
        }
    }
}
Rectangle ghost_rec_fruit(Ghost *ghost)
{
    Rectangle ghostrec = { ghost->i, ghost->j, 40, 40};
    return ghostrec;
}
void eating_ghost(GameElements *game_elements)
{
    Rectangle red_rec = ghost_rec_fruit(game_elements->ghosts->red_ghost);
    Rectangle green_rec = ghost_rec_fruit(game_elements->ghosts->green_ghost);
    Rectangle blue_rec = ghost_rec_fruit(game_elements->ghosts->blue_ghost);
    Rectangle pink_rec = ghost_rec_fruit(game_elements->ghosts->pink_ghost);
    Rectangle pacman_rec = { game_elements->pacman->i, game_elements->pacman->j, 40, 40};

    if(CheckCollisionRecs(red_rec, pacman_rec) && game_elements->ghosts->red_ghost->exist_flag && game_elements->pacman->exist_flag)
    {
        PlaySound(game_elements->game_sounds->eat_ghost);
        game_elements->game_info->ghost_eat++;
        random_position_fruits(game_elements->ghosts->red_ghost, game_elements);
        game_elements->ghosts->red_ghost->direction = 'u';
        game_elements->ghosts->red_ghost->time = 0;
        game_elements->ghosts->red_ghost->exist_flag = false;
        game_elements->ghosts->red_ghost->blink_flag = false;
    }
    else if(CheckCollisionRecs(green_rec, pacman_rec) && game_elements->ghosts->green_ghost->exist_flag && game_elements->pacman->exist_flag)
    {
        PlaySound(game_elements->game_sounds->eat_ghost);
        game_elements->game_info->ghost_eat++;
        random_position_fruits(game_elements->ghosts->green_ghost, game_elements);
        game_elements->ghosts->green_ghost->direction = 'r';
        game_elements->ghosts->green_ghost->time = 0;
        game_elements->ghosts->green_ghost->exist_flag = false;
        game_elements->ghosts->green_ghost->blink_flag = false;
    }
    else if(CheckCollisionRecs(pink_rec, pacman_rec) && game_elements->ghosts->pink_ghost->exist_flag && game_elements->pacman->exist_flag)
    {
        PlaySound(game_elements->game_sounds->eat_ghost);
        game_elements->game_info->ghost_eat++;
        random_position_fruits(game_elements->ghosts->pink_ghost, game_elements);
        game_elements->ghosts->pink_ghost->direction = 'u';
        game_elements->ghosts->pink_ghost->time = 0;
        game_elements->ghosts->pink_ghost->exist_flag = false;
        game_elements->ghosts->pink_ghost->blink_flag = false;
    }
    else if(CheckCollisionRecs(blue_rec, pacman_rec) && game_elements->ghosts->blue_ghost->exist_flag && game_elements->pacman->exist_flag)
    {
        PlaySound(game_elements->game_sounds->eat_ghost);
        game_elements->game_info->ghost_eat++;
        random_position_fruits(game_elements->ghosts->blue_ghost, game_elements);
        game_elements->ghosts->blue_ghost->direction = 'l';
        game_elements->ghosts->blue_ghost->time = 0;
        game_elements->ghosts->blue_ghost->exist_flag = false;
        game_elements->ghosts->blue_ghost->blink_flag = false;
    }
    if(game_elements->game_flags->medium_flag || game_elements->game_flags->hard_flag)
    {
        Rectangle yellow_rec = ghost_rec_fruit(game_elements->ghosts->yellow_ghost);
        Rectangle fire_red_rec = ghost_rec_fruit(game_elements->ghosts->fire_red_ghost);

        if(CheckCollisionRecs(yellow_rec, pacman_rec) && game_elements->ghosts->yellow_ghost->exist_flag && game_elements->pacman->exist_flag)
        {
            PlaySound(game_elements->game_sounds->eat_ghost);
            game_elements->game_info->ghost_eat++;
            random_position_fruits(game_elements->ghosts->yellow_ghost, game_elements);
            game_elements->ghosts->yellow_ghost->direction = 'd';
            game_elements->ghosts->yellow_ghost->time = 0;
            game_elements->ghosts->yellow_ghost->exist_flag = false;
            game_elements->ghosts->yellow_ghost->blink_flag = false;
        }
        else if(CheckCollisionRecs(fire_red_rec, pacman_rec) && game_elements->ghosts->fire_red_ghost->exist_flag && game_elements->pacman->exist_flag)
        {
            PlaySound(game_elements->game_sounds->eat_ghost);
            game_elements->game_info->ghost_eat++;
            random_position_fruits(game_elements->ghosts->fire_red_ghost, game_elements);
            game_elements->ghosts->fire_red_ghost->direction = 'l';
            game_elements->ghosts->fire_red_ghost->time = 0;
            game_elements->ghosts->fire_red_ghost->exist_flag = false;
            game_elements->ghosts->fire_red_ghost->blink_flag = false;
        }
        if(game_elements->game_flags->hard_flag)
        {
            Rectangle brown_rec = ghost_rec_fruit(game_elements->ghosts->brown_ghost);
            Rectangle fire_blue_rec = ghost_rec_fruit(game_elements->ghosts->fire_blue_ghost);

            if(CheckCollisionRecs(brown_rec, pacman_rec) && game_elements->ghosts->brown_ghost->exist_flag && game_elements->pacman->exist_flag)
            {
                PlaySound(game_elements->game_sounds->eat_ghost);
                game_elements->game_info->ghost_eat++;
                random_position_fruits(game_elements->ghosts->brown_ghost, game_elements);
                game_elements->ghosts->brown_ghost->direction = 'd';
                game_elements->ghosts->brown_ghost->time = 0;
                game_elements->ghosts->brown_ghost->exist_flag = false;
                game_elements->ghosts->brown_ghost->blink_flag = false;
            }
            else if(CheckCollisionRecs(fire_blue_rec, pacman_rec) && game_elements->ghosts->fire_blue_ghost->exist_flag && game_elements->pacman->exist_flag)
            {
                PlaySound(game_elements->game_sounds->eat_ghost);
                game_elements->game_info->ghost_eat++;
                random_position_fruits(game_elements->ghosts->fire_blue_ghost, game_elements);
                game_elements->ghosts->fire_blue_ghost->direction = 'd';
                game_elements->ghosts->fire_blue_ghost->time = 0;
                game_elements->ghosts->fire_blue_ghost->exist_flag = false;
                game_elements->ghosts->fire_blue_ghost->blink_flag = false;
            }
        }
    }
}
void cherry_handling(GameElements *game_elements)
{
    if(!game_elements->fruits->Cherry->exist_flag && game_elements->fruits->Cherry->ability_flag && game_elements->fruits->Cherry->time >= 20)
    {
        game_elements->fruits->Cherry->time = 0;
        game_elements->fruits->Cherry->ability_flag = false;
        game_elements->fruits->Cherry->exist_flag = false;
    }
    else if(!game_elements->fruits->Cherry->exist_flag && !game_elements->fruits->Cherry->ability_flag && game_elements->fruits->Cherry->time >= 30)
    {
        game_elements->fruits->Cherry->time = 0;
        game_elements->fruits->Cherry->ability_flag = false;
        game_elements->fruits->Cherry->exist_flag = true;
    }
    else if(game_elements->fruits->Cherry->exist_flag && !game_elements->fruits->Cherry->ability_flag && fruit_collison(game_elements, game_elements->fruits->Cherry))
    {
        PlaySound(game_elements->game_sounds->eat_fruit);
        game_elements->game_info->cherry_num++;
        game_elements->fruits->Cherry->time = 0;
        init_fruit(game_elements->fruits->Cherry, game_elements);
        game_elements->fruits->Cherry->ability_flag = true;
        game_elements->fruits->Cherry->exist_flag = false;
    }
    if(game_elements->fruits->Cherry->exist_flag && !game_elements->fruits->Cherry->ability_flag)
    {
        DrawTexture(game_elements->fruits->Cherry->fruit_texture, game_elements->fruits->Cherry->i + game_elements->zero_point->x, game_elements->fruits->Cherry->j + game_elements->zero_point->y, WHITE);
    }
    else if(!game_elements->fruits->Cherry->exist_flag && game_elements->fruits->Cherry->ability_flag)
    {
        const char *text = TextFormat("%.2f", 20 - game_elements->fruits->Cherry->time);
        Vector2 textsize = MeasureTextEx(game_elements->menu->font, text, 50, 1);
        DrawTextEx(game_elements->menu->font, text, (Vector2) {(game_elements->board_size->cols) * 40 + game_elements->zero_point->x - 20 - textsize.x, -3 * 40 + game_elements->zero_point->y + 15}, 50, 1, YELLOW);         
        DrawTexture(game_elements->fruits->Cherry->fruit_texture80, (game_elements->board_size->cols) * 40 + game_elements->zero_point->x - 120 - textsize.x, -3 * 40 + game_elements->zero_point->y, WHITE);
        eating_ghost(game_elements);
    } 
}

#endif
#ifndef INITIAL_FUNCTIONS_H
#define INITIAL_FUNCTIONS_H

#include "structures.h"

int rounds(int numerator, int denominator, float border)
{
    float result = (float)numerator / denominator;
    return (result - (int)result > border) ? (numerator / denominator + 1) : (numerator / denominator);
}
Rectangle ghost_rec(Ghost *ghost, GameElements *game_elements)
{
    Rectangle ghostrec = { ghost->i, ghost->j, game_elements->BlockSize, game_elements->BlockSize};
    return ghostrec;
}
int collison_check(GameElements *game_elements)
{
    Rectangle red_rec = ghost_rec(game_elements->ghosts->red_ghost, game_elements);
    Rectangle green_rec = ghost_rec(game_elements->ghosts->green_ghost, game_elements);
    Rectangle blue_rec = ghost_rec(game_elements->ghosts->blue_ghost, game_elements);
    Rectangle pink_rec = ghost_rec(game_elements->ghosts->pink_ghost, game_elements);
    Rectangle pacman_rec = { game_elements->pacman->i, game_elements->pacman->j, game_elements->BlockSize, game_elements->BlockSize};

    if(CheckCollisionRecs(red_rec, pacman_rec) && !game_elements->fruits->Cherry->ability_flag
    && game_elements->ghosts->red_ghost->exist_flag && game_elements->pacman->exist_flag)
    {
        game_elements->pacman->exist_flag = false;
        game_elements->pacman->blink_flag = false;
        game_elements->pacman->time = 0;
        PlaySound(game_elements->game_sounds->ghost_colli);
        return 1;
    }
    else if(CheckCollisionRecs(pink_rec, pacman_rec) && !game_elements->fruits->Cherry->ability_flag
    && game_elements->ghosts->pink_ghost->exist_flag && game_elements->pacman->exist_flag)
    {
        game_elements->pacman->exist_flag = false;
        game_elements->pacman->blink_flag = false;
        game_elements->pacman->time = 0;        
        PlaySound(game_elements->game_sounds->ghost_colli);
        return 1;
    }
    else if(CheckCollisionRecs(green_rec, pacman_rec) && !game_elements->fruits->Cherry->ability_flag
    && game_elements->ghosts->green_ghost->exist_flag && game_elements->pacman->exist_flag)
    {
        game_elements->pacman->exist_flag = false;
        game_elements->pacman->blink_flag = false;
        game_elements->pacman->time = 0;
        PlaySound(game_elements->game_sounds->ghost_colli);
        return 1;
    }
    else if(CheckCollisionRecs(blue_rec, pacman_rec) && !game_elements->fruits->Cherry->ability_flag
    && game_elements->ghosts->blue_ghost->exist_flag && game_elements->pacman->exist_flag)
    {
        game_elements->pacman->exist_flag = false;
        game_elements->pacman->blink_flag = false;
        game_elements->pacman->time = 0;
        PlaySound(game_elements->game_sounds->ghost_colli);
        return 1;
    }
    if(game_elements->game_flags->medium_flag || game_elements->game_flags->hard_flag)
    {
        Rectangle fire_red_rec = ghost_rec(game_elements->ghosts->fire_red_ghost, game_elements);
        Rectangle yellow_rec = ghost_rec(game_elements->ghosts->yellow_ghost, game_elements);

        if(CheckCollisionRecs(yellow_rec, pacman_rec) && !game_elements->fruits->Cherry->ability_flag
        && game_elements->ghosts->yellow_ghost->exist_flag && game_elements->pacman->exist_flag)
        {
            game_elements->pacman->exist_flag = false;
            game_elements->pacman->blink_flag = false;
            game_elements->pacman->time = 0;
            PlaySound(game_elements->game_sounds->ghost_colli);
            return 1;
        }
        else if(CheckCollisionRecs(fire_red_rec, pacman_rec) && !game_elements->fruits->Cherry->ability_flag
        && game_elements->ghosts->fire_red_ghost->exist_flag && game_elements->pacman->exist_flag)
        {
            game_elements->pacman->exist_flag = false;
            game_elements->pacman->blink_flag = false;
            game_elements->pacman->time = 0;           
            PlaySound(game_elements->game_sounds->ghost_colli);
            return 1;
        }
        if(game_elements->game_flags->hard_flag)
        {
            Rectangle fire_blue_rec = ghost_rec(game_elements->ghosts->fire_blue_ghost, game_elements);
            Rectangle brown_rec = ghost_rec(game_elements->ghosts->brown_ghost, game_elements);

            if(CheckCollisionRecs(brown_rec, pacman_rec) && !game_elements->fruits->Cherry->ability_flag
            && game_elements->ghosts->brown_ghost->exist_flag && game_elements->pacman->exist_flag)
            {
                game_elements->pacman->exist_flag = false;
                game_elements->pacman->blink_flag = false;
                game_elements->pacman->time = 0;                
                PlaySound(game_elements->game_sounds->ghost_colli);
                return 1;
            }
            else if(CheckCollisionRecs(fire_blue_rec, pacman_rec) && !game_elements->fruits->Cherry->ability_flag
            && game_elements->ghosts->brown_ghost->exist_flag && game_elements->pacman->exist_flag)
            {
                game_elements->pacman->exist_flag = false;
                game_elements->pacman->blink_flag = false;
                game_elements->pacman->time = 0;                  
                PlaySound(game_elements->game_sounds->ghost_colli);
                return 1;
            }
        }
    }

    return 0;
}
int scroll_wheel()
{
    float move = GetMouseWheelMove();
    if(move < 0)
        return 1;
    else if(move == 0)
        return 0;
    else if(move > 0)
        return -1;
}

#endif
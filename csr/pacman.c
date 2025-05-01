#ifndef PACMAN_H
#define PACMAN_H

#include "initial_functions.h"

void teleport(GameElements *game_elements)
{
    float static i = 0;
    float static r = 0;
    if(game_elements->border->time == 10)
    {
        i = 0;
    }
    if(game_elements->border->time == 12)
    {
        r = 0;
    }
    if(game_elements->border->time <= 1)    
    {
        game_elements->pacman->flash_position.x = game_elements->pacman->i + game_elements->zero_point->x - 20;

        if(game_elements->pacman->flash_flag)
        {
            game_elements->pacman->flash_position.y = game_elements->pacman->j + game_elements->zero_point->y - 200 + game_elements->pacman->flash_move; 
            game_elements->pacman->flash_move--;
            if(game_elements->pacman->flash_move <= -game_elements->BlockSize)
            {
                game_elements->pacman->flash_flag = false;
            }
        }
        else
        {
            game_elements->pacman->flash_position.y = game_elements->pacman->j + game_elements->zero_point->y - 200 + game_elements->pacman->flash_move; 
            game_elements->pacman->flash_move++;
            if(game_elements->pacman->flash_move >= 0)
            {
                game_elements->pacman->flash_flag = true;
            }
        }
        DrawTexture(game_elements->pacman->flash, game_elements->pacman->flash_position.x, game_elements->pacman->flash_position.y, WHITE);
    }
    int number = GetRandomValue(0, 3);
    int gates[4][3] = {{3, 2, 0}, {27, 3, 3}, {26, 27, 1}, {2, 26, 2}};
    char directions[4] = {'u', 'd', 'r', 'l'};
    if(CheckCollisionRecs((Rectangle){game_elements->pacman->i + game_elements->zero_point->x, game_elements->pacman->j + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize},
    (Rectangle) {gates[0][1] * game_elements->BlockSize + game_elements->zero_point->x, gates[0][0] * game_elements->BlockSize + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize}) && game_elements->border->time >= 10)
    {
        while(number == 0)
        {
            number = GetRandomValue(0, 3);
        }
        game_elements->pacman->i = gates[number][1] * game_elements->BlockSize;
        game_elements->pacman->j = gates[number][0] * game_elements->BlockSize;
        game_elements->pacman->direction = directions[gates[number][2]];
        game_elements->border->time = 0;
    }
    if(CheckCollisionRecs((Rectangle){game_elements->pacman->i + game_elements->zero_point->x, game_elements->pacman->j + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize},
    (Rectangle) {gates[1][1] * game_elements->BlockSize + game_elements->zero_point->x, gates[1][0] * game_elements->BlockSize + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize}) && game_elements->border->time >= 10)
    {
        while(number == 1)
        {
            number = GetRandomValue(0, 3);
        }        
        game_elements->pacman->i = gates[number][1] * game_elements->BlockSize;
        game_elements->pacman->j = gates[number][0] * game_elements->BlockSize ;
        game_elements->pacman->direction = directions[gates[number][2]];
        game_elements->border->time = 0;
    }
    if(CheckCollisionRecs((Rectangle){game_elements->pacman->i + game_elements->zero_point->x, game_elements->pacman->j + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize},
    (Rectangle) {gates[2][1] * game_elements->BlockSize + game_elements->zero_point->x, gates[2][0] * game_elements->BlockSize + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize}) && game_elements->border->time >= 10)
    {
        while(number == 2)
        {
            number = GetRandomValue(0, 3);
        }        
        game_elements->pacman->i = gates[number][1] * game_elements->BlockSize;
        game_elements->pacman->j = gates[number][0] * game_elements->BlockSize;
        game_elements->pacman->direction = directions[gates[number][2]];
        game_elements->border->time = 0;
    }
    if(CheckCollisionRecs((Rectangle){game_elements->pacman->i + game_elements->zero_point->x, game_elements->pacman->j + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize},
    (Rectangle) {gates[3][1] * game_elements->BlockSize + game_elements->zero_point->x, gates[3][0] * game_elements->BlockSize + game_elements->zero_point->y, game_elements->BlockSize, game_elements->BlockSize}) && game_elements->border->time >= 10)
    {
        while(number == 3)
        {
            number = GetRandomValue(0, 3);
        }        
        game_elements->pacman->i = gates[number][1] * game_elements->BlockSize;
        game_elements->pacman->j = gates[number][0] * game_elements->BlockSize;
        game_elements->pacman->direction = directions[gates[number][2]];
        game_elements->border->time = 0;
    }
    if(game_elements->border->time > 10)
    {
        DrawTexture(game_elements->border->hole, 2 * game_elements->BlockSize + game_elements->zero_point->x, 3 * game_elements->BlockSize + game_elements->zero_point->y, (Color) {255, 255, 255, i < 255 ? i += GetFrameTime() * 127.5 : 255});
        DrawTexture(game_elements->border->hole, 3 * game_elements->BlockSize + game_elements->zero_point->x, 27 * game_elements->BlockSize + game_elements->zero_point->y, (Color) {255, 255, 255, i < 255 ? i += GetFrameTime() * 127.5 : 255});
        DrawTexture(game_elements->border->hole, 27 * game_elements->BlockSize + game_elements->zero_point->x, 26 * game_elements->BlockSize + game_elements->zero_point->y, (Color) {255, 255, 255, i < 255 ? i += GetFrameTime() * 127.5 : 255});
        DrawTexture(game_elements->border->hole, 26 * game_elements->BlockSize + game_elements->zero_point->x, 2 * game_elements->BlockSize + game_elements->zero_point->y, (Color) {255, 255, 255, i < 255 ? i += GetFrameTime() * 127.5 : 255});
    }
}
void pacman_location(GameElements *game_elements)
{
    do {
        game_elements->pacman->i = rand() % game_elements->board_size->rows;
        game_elements->pacman->j = rand() % game_elements->board_size->cols;
    } while(game_elements->Board[(int) game_elements->pacman->j][(int) game_elements->pacman->i] != 0);
    
    game_elements->pacman->i *= game_elements->BlockSize;
    game_elements->pacman->j *= game_elements->BlockSize;
    game_elements->pacman->direction = '\0';
}
int pacman_move(GameElements *game_elements)
{
    if(!game_elements->pacman->blink_flag && !game_elements->pacman->exist_flag && game_elements->pacman->time >= 1)
    {
        game_elements->pacman->time = 0;
        game_elements->pacman->blink_flag = true;
        game_elements->pacman->exist_flag = false;
    }
    if(game_elements->pacman->blink_flag && !game_elements->pacman->exist_flag)
    {
        game_elements->pacman->flash_position.x = game_elements->pacman->i + game_elements->zero_point->x - 20;

        if(game_elements->pacman->flash_flag)
        {
            game_elements->pacman->flash_position.y = game_elements->pacman->j + game_elements->zero_point->y - 200 + game_elements->pacman->flash_move; 
            game_elements->pacman->flash_move--;
            if(game_elements->pacman->flash_move <= -game_elements->BlockSize)
            {
                game_elements->pacman->flash_flag = false;
            }
        }
        else
        {
            game_elements->pacman->flash_position.y = game_elements->pacman->j + game_elements->zero_point->y - 200 + game_elements->pacman->flash_move; 
            game_elements->pacman->flash_move++;
            if(game_elements->pacman->flash_move >= 0)
            {
                game_elements->pacman->flash_flag = true;
            }
        }

        int current_row;
        int current_col;

        if(game_elements->pacman->direction == 'u')
        {
            current_col = rounds(game_elements->pacman->i, game_elements->BlockSize, 0.5);
            current_row = rounds(game_elements->pacman->j, game_elements->BlockSize, 0.1);        
        }
        else if(game_elements->pacman->direction == 'd')
        {
            current_col = rounds(game_elements->pacman->i, game_elements->BlockSize, 0.5);
            current_row = rounds(game_elements->pacman->j, game_elements->BlockSize, 0.9);        
        }
        else if(game_elements->pacman->direction == 'r')
        {
            current_col = rounds(game_elements->pacman->i, game_elements->BlockSize, 0.9);
            current_row = rounds(game_elements->pacman->j, game_elements->BlockSize, 0.5);
        }
        else if(game_elements->pacman->direction == 'l')
        {
            current_col = rounds(game_elements->pacman->i, game_elements->BlockSize, 0.1);
            current_row = rounds(game_elements->pacman->j, game_elements->BlockSize, 0.5);        
        }
        else
        {
            current_col = game_elements->pacman->i / game_elements->BlockSize;
            current_row = game_elements->pacman->j / game_elements->BlockSize; 
        }

        if(IsKeyPressed(KEY_UP))
            game_elements->pacman->last_direction = 'u';
        else if(IsKeyPressed(KEY_DOWN))
            game_elements->pacman->last_direction = 'd';
        else if(IsKeyPressed(KEY_LEFT))
            game_elements->pacman->last_direction = 'l';
        else if(IsKeyPressed(KEY_RIGHT))
            game_elements->pacman->last_direction = 'r';
            
        if (game_elements->pacman->last_direction == 'u' && current_row != 0 && game_elements->Board[current_row - 1][current_col] != 1)
        {
            if(game_elements->Board[current_row - 1][current_col] == 2)
            {
                game_elements->Board[current_row - 1][current_col] = 0;
                PlaySound(game_elements->game_sounds->eat_star);
            }
            game_elements->pacman->direction = 'u';
            game_elements->pacman->last_direction = '\0';
            game_elements->pacman->i = current_col * game_elements->BlockSize;
            game_elements->pacman->j = current_row * game_elements->BlockSize;
        }
        else if (game_elements->pacman->last_direction == 'd' && current_row != game_elements->board_size->rows - 1 && game_elements->Board[current_row + 1][current_col] != 1)
        {
            if(game_elements->Board[current_row + 1][current_col] == 2)
            {
                game_elements->Board[current_row + 1][current_col] = 0;
                PlaySound(game_elements->game_sounds->eat_star);
            }
            game_elements->pacman->direction = 'd';
            game_elements->pacman->last_direction = '\0';
            game_elements->pacman->i = current_col * game_elements->BlockSize;
            game_elements->pacman->j = current_row * game_elements->BlockSize;
        }
        else if(game_elements->pacman->last_direction == 'r' && current_col != game_elements->board_size->cols - 1 && game_elements->Board[current_row][current_col + 1] != 1)
        {
            
            if(game_elements->Board[current_row][current_col + 1] == 2)
            {
                game_elements->Board[current_row][current_col + 1] = 0;
                PlaySound(game_elements->game_sounds->eat_star);
            }
            game_elements->pacman->direction = 'r';
            game_elements->pacman->last_direction = '\0';
            game_elements->pacman->i = current_col * game_elements->BlockSize;
            game_elements->pacman->j = current_row * game_elements->BlockSize;
        }
        else if(game_elements->pacman->last_direction == 'l' && current_col != 0 && game_elements->Board[current_row][current_col - 1] != 1)
        {
            if(game_elements->Board[current_row][current_col - 1] == 2)
            {
                game_elements->Board[current_row][current_col - 1] = 0;
                PlaySound(game_elements->game_sounds->eat_star);
            }
            game_elements->pacman->direction = 'l';
            game_elements->pacman->last_direction = '\0';
            game_elements->pacman->i = current_col * game_elements->BlockSize;
            game_elements->pacman->j = current_row * game_elements->BlockSize;
        }
        
        if(current_row != 0 && game_elements->pacman->direction == 'u' && game_elements->Board[current_row - 1][current_col] != 1)
        {
            if(game_elements->Board[current_row - 1][current_col] == 2)
            {
                game_elements->Board[current_row - 1][current_col] = 0;
                PlaySound(game_elements->game_sounds->eat_star);
            }
            game_elements->pacman->j -= GetFrameTime() * game_elements->pacman->speed;
        }
        else if(current_row != game_elements->board_size->rows - 1 && game_elements->pacman->direction == 'd' && game_elements->Board[current_row + 1][current_col] != 1)
        {
            if(game_elements->Board[current_row + 1][current_col] == 2)
            {
                game_elements->Board[current_row + 1][current_col] = 0; 
                PlaySound(game_elements->game_sounds->eat_star);
            }       
            game_elements->pacman->j += GetFrameTime() * game_elements->pacman->speed;
        }
        else if(current_col != game_elements->board_size->cols - 1 && game_elements->pacman->direction == 'r' && game_elements->Board[current_row][current_col + 1] != 1)
        {
            if(game_elements->Board[current_row][current_col + 1] == 2)
            {
                game_elements->Board[current_row][current_col + 1] = 0; 
                PlaySound(game_elements->game_sounds->eat_star);
            }       
            game_elements->pacman->i += GetFrameTime() * game_elements->pacman->speed;
        }
        else if(current_col != 0 && game_elements->pacman->direction == 'l' && game_elements->Board[current_row][current_col - 1] != 1)
        {
            if(game_elements->Board[current_row][current_col - 1] == 2)
            {
                game_elements->Board[current_row][current_col - 1] = 0; 
                PlaySound(game_elements->game_sounds->eat_star);
            }       
            game_elements->pacman->i -= GetFrameTime() * game_elements->pacman->speed;
        }
       
        if(game_elements->pacman->time >= 3)
        {
            game_elements->pacman->exist_flag = true;
            game_elements->pacman->blink_flag = false;
        }

        DrawTexture(game_elements->pacman->flash, game_elements->pacman->flash_position.x, game_elements->pacman->flash_position.y, WHITE);
        if((int) (game_elements->pacman->time * 10 / 2) % 2)
        {
            if(game_elements->pacman->direction == 'u')
            {            
                DrawTexture(game_elements->timer->time_flag_mouth ? game_elements->pacman->pacman_te : game_elements->pacman->pacman_up, game_elements->pacman->i + game_elements->zero_point->x, game_elements->pacman->j + game_elements->zero_point->y, YELLOW);
            }
            else if(game_elements->pacman->direction == 'd')
            {
                DrawTexture(game_elements->timer->time_flag_mouth ? game_elements->pacman->pacman_te : game_elements->pacman->pacman_down, game_elements->pacman->i + game_elements->zero_point->x, game_elements->pacman->j + game_elements->zero_point->y, YELLOW);            
            }
            else if(game_elements->pacman->direction == 'r')
            {
                DrawTexture(game_elements->timer->time_flag_mouth ? game_elements->pacman->pacman_te : game_elements->pacman->pacman_right, game_elements->pacman->i + game_elements->zero_point->x, game_elements->pacman->j + game_elements->zero_point->y, YELLOW);
            }
            else if(game_elements->pacman->direction == 'l')
            {
                DrawTexture(game_elements->timer->time_flag_mouth ? game_elements->pacman->pacman_te : game_elements->pacman->pacman_left, game_elements->pacman->i + game_elements->zero_point->x, game_elements->pacman->j + game_elements->zero_point->y, YELLOW);
            }
            else 
            {
                DrawTexture(game_elements->timer->time_flag_mouth ? game_elements->pacman->pacman_te : game_elements->pacman->pacman_left, game_elements->pacman->i + game_elements->zero_point->x, game_elements->pacman->j + game_elements->zero_point->y, YELLOW);
            }
        }
    }
    if(!game_elements->pacman->blink_flag && game_elements->pacman->exist_flag)
    {
        int current_row;
        int current_col;

        if(game_elements->pacman->direction == 'u')
        {
            current_col = rounds(game_elements->pacman->i, game_elements->BlockSize, 0.5);
            current_row = rounds(game_elements->pacman->j, game_elements->BlockSize, 0.1);        
        }
        else if(game_elements->pacman->direction == 'd')
        {
            current_col = rounds(game_elements->pacman->i, game_elements->BlockSize, 0.5);
            current_row = rounds(game_elements->pacman->j, game_elements->BlockSize, 0.9);        
        }
        else if(game_elements->pacman->direction == 'r')
        {
            current_col = rounds(game_elements->pacman->i, game_elements->BlockSize, 0.9);
            current_row = rounds(game_elements->pacman->j, game_elements->BlockSize, 0.5);
        }
        else if(game_elements->pacman->direction == 'l')
        {
            current_col = rounds(game_elements->pacman->i, game_elements->BlockSize, 0.1);
            current_row = rounds(game_elements->pacman->j, game_elements->BlockSize, 0.5);        
        }
        else
        {
            current_col = rounds(game_elements->pacman->i, game_elements->BlockSize, 0.5);
            current_row = rounds(game_elements->pacman->j, game_elements->BlockSize, 0.1);   
        }

        if(IsKeyPressed(KEY_UP))
            game_elements->pacman->last_direction = 'u';
        else if(IsKeyPressed(KEY_DOWN))
            game_elements->pacman->last_direction = 'd';
        else if(IsKeyPressed(KEY_LEFT))
            game_elements->pacman->last_direction = 'l';
        else if(IsKeyPressed(KEY_RIGHT))
            game_elements->pacman->last_direction = 'r';
            
        if (game_elements->pacman->last_direction == 'u' && game_elements->pacman->direction != 'u' && current_row != 0 && game_elements->Board[current_row - 1][current_col] != 1)
        {
            if(game_elements->Board[current_row - 1][current_col] == 2)
            {
                game_elements->Board[current_row - 1][current_col] = 0;
                PlaySound(game_elements->game_sounds->eat_star);
            }
            game_elements->pacman->direction = 'u';
            game_elements->pacman->last_direction = '\0';
            game_elements->pacman->i = current_col * game_elements->BlockSize;
            game_elements->pacman->j = current_row * game_elements->BlockSize;
        }
        else if (game_elements->pacman->last_direction == 'd' && game_elements->pacman->direction != 'd' && current_row != game_elements->board_size->rows - 1 && game_elements->Board[current_row + 1][current_col] != 1)
        {
            if(game_elements->Board[current_row + 1][current_col] == 2)
            {
                game_elements->Board[current_row + 1][current_col] = 0;
                PlaySound(game_elements->game_sounds->eat_star);
            }
            game_elements->pacman->direction = 'd';
            game_elements->pacman->last_direction = '\0';
            game_elements->pacman->i = current_col * game_elements->BlockSize;
            game_elements->pacman->j = current_row * game_elements->BlockSize;
        }
        else if(game_elements->pacman->last_direction == 'r' && game_elements->pacman->direction != 'r' && current_col != game_elements->board_size->cols - 1 && game_elements->Board[current_row][current_col + 1] != 1)
        {
            
            if(game_elements->Board[current_row][current_col + 1] == 2)
            {
                game_elements->Board[current_row][current_col + 1] = 0;
                PlaySound(game_elements->game_sounds->eat_star);
            }
            game_elements->pacman->direction = 'r';
            game_elements->pacman->last_direction = '\0';
            game_elements->pacman->i = current_col * game_elements->BlockSize;
            game_elements->pacman->j = current_row * game_elements->BlockSize;
        }
        else if(game_elements->pacman->last_direction == 'l'  && game_elements->pacman->direction != 'l' && current_col != 0 && game_elements->Board[current_row][current_col - 1] != 1)
        {
            if(game_elements->Board[current_row][current_col - 1] == 2)
            {
                game_elements->Board[current_row][current_col - 1] = 0;
                PlaySound(game_elements->game_sounds->eat_star);
            }
            game_elements->pacman->direction = 'l';
            game_elements->pacman->last_direction = '\0';
            game_elements->pacman->i = current_col * game_elements->BlockSize;
            game_elements->pacman->j = current_row * game_elements->BlockSize;
        }
        
        if(current_row != 0 && game_elements->pacman->direction == 'u' && game_elements->Board[current_row - 1][current_col] != 1)
        {
            if(game_elements->Board[current_row - 1][current_col] == 2)
            {
                game_elements->Board[current_row - 1][current_col] = 0;
                PlaySound(game_elements->game_sounds->eat_star);
            }
            game_elements->pacman->j -= GetFrameTime() * game_elements->pacman->speed;
        }
        else if(current_row != game_elements->board_size->rows - 1 && game_elements->pacman->direction == 'd' && game_elements->Board[current_row + 1][current_col] != 1)
        {
            if(game_elements->Board[current_row + 1][current_col] == 2)
            {
                game_elements->Board[current_row + 1][current_col] = 0; 
                PlaySound(game_elements->game_sounds->eat_star);
            }       
            game_elements->pacman->j += GetFrameTime() * game_elements->pacman->speed;
        }
        else if(current_col != game_elements->board_size->cols - 1 && game_elements->pacman->direction == 'r' && game_elements->Board[current_row][current_col + 1] != 1)
        {
            if(game_elements->Board[current_row][current_col + 1] == 2)
            {
                game_elements->Board[current_row][current_col + 1] = 0; 
                PlaySound(game_elements->game_sounds->eat_star);
            }       
            game_elements->pacman->i += GetFrameTime() * game_elements->pacman->speed;
        }
        else if(current_col != 0 && game_elements->pacman->direction == 'l' && game_elements->Board[current_row][current_col - 1] != 1)
        {
            if(game_elements->Board[current_row][current_col - 1] == 2)
            {
                game_elements->Board[current_row][current_col - 1] = 0; 
                PlaySound(game_elements->game_sounds->eat_star);
            }       
            game_elements->pacman->i -= GetFrameTime() * game_elements->pacman->speed;
        }

        if(game_elements->pacman->direction == 'u')
        {
            DrawTexture(game_elements->timer->time_flag_mouth ? game_elements->pacman->pacman_te : game_elements->pacman->pacman_up, game_elements->pacman->i + game_elements->zero_point->x, game_elements->pacman->j + game_elements->zero_point->y, YELLOW);
        }
        else if(game_elements->pacman->direction == 'd')
        {
            DrawTexture(game_elements->timer->time_flag_mouth ? game_elements->pacman->pacman_te : game_elements->pacman->pacman_down, game_elements->pacman->i + game_elements->zero_point->x, game_elements->pacman->j + game_elements->zero_point->y, YELLOW);            
        }
        else if(game_elements->pacman->direction == 'r')
        {
            DrawTexture(game_elements->timer->time_flag_mouth ? game_elements->pacman->pacman_te : game_elements->pacman->pacman_right, game_elements->pacman->i + game_elements->zero_point->x, game_elements->pacman->j + game_elements->zero_point->y, YELLOW);
        }
        else if(game_elements->pacman->direction == 'l')
        {
            DrawTexture(game_elements->timer->time_flag_mouth ? game_elements->pacman->pacman_te : game_elements->pacman->pacman_left, game_elements->pacman->i + game_elements->zero_point->x, game_elements->pacman->j + game_elements->zero_point->y, YELLOW);
        }
        else
        {
            DrawTexture(game_elements->timer->time_flag_mouth ? game_elements->pacman->pacman_te : game_elements->pacman->pacman_left, game_elements->pacman->i + game_elements->zero_point->x, game_elements->pacman->j + game_elements->zero_point->y, YELLOW);  
        }
    }
}
int count_health(GameElements *game_elements)
{
    if(game_elements->pacman->health == 0)
    {
        return 0;
    }
    if(collison_check(game_elements))
    {
        game_elements->pacman->health--;
        pacman_location(game_elements);
        game_elements->pacman->direction = game_elements->board_size->cols / 2 <= game_elements->pacman->i ? 'l' : 'r';
    }
    return 1;
}

#endif
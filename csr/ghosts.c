#ifndef GHOSTS_H
#define GHOSTS_H

#include "initial_functions.h"



int good_place(int row, int col, GameElements *game_elements, int rows, int cols, int visited[rows][cols]) {
    return row >= 0 && row < game_elements->board_size->rows && col >= 0 && col < game_elements->board_size->cols && 
           game_elements->Board[row][col] == 0 && 
           !visited[row][col];
}
Point find_next_step(Ghost *ghost, GameElements *game_elements) {
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int visited[game_elements->board_size->rows][game_elements->board_size->cols];
    for(int i = 0; i < game_elements->board_size->rows; i++)
    {
        for(int j = 0; j < game_elements->board_size->cols; j++)
        {
            visited[i][j] = 0;
        }
    }
    Point save[game_elements->board_size->rows][game_elements->board_size->cols];

    Point array[1000];
    int f = 0;
    int b = 0;

    Point start = {ghost->j / game_elements->BlockSize, ghost->i / game_elements->BlockSize};
    Point end = {game_elements->pacman->j / game_elements->BlockSize, game_elements->pacman->i / game_elements->BlockSize};

    if(ghost->direction == 'u')
    {
        start.col = rounds(ghost->i, game_elements->BlockSize, 0.99);
        start.row = rounds(ghost->j, game_elements->BlockSize, 0.01);        
    }
    else if(ghost->direction == 'd')
    {
        start.col = rounds(ghost->i, game_elements->BlockSize, 0.01);
        start.row = rounds(ghost->j, game_elements->BlockSize, 0.99);        
    }
    else if(ghost->direction == 'r')
    {
        start.col = rounds(ghost->i, game_elements->BlockSize, 0.99);
        start.row = rounds(ghost->j, game_elements->BlockSize, 0.01);
    }
    else
    {
        start.col = rounds(ghost->i, game_elements->BlockSize, 0.01);
        start.row = rounds(ghost->j, game_elements->BlockSize, 0.99);        
    }

    if (b < 1000) {
        array[b++] = start;
    }
    visited[start.row][start.col] = 1;

    while (f != b) {
        Point current = array[f++];

        if (current.row == end.row && current.col == end.col) {
            while (save[current.row][current.col].row != start.row ||
                   save[current.row][current.col].col != start.col) {
                current = save[current.row][current.col];
            }
            return current;
        }

        for (int i = 0; i < 4; i++) {
            int new_row = current.row + directions[i][0];
            int new_col = current.col + directions[i][1];

            if (good_place(new_row, new_col, game_elements, game_elements->board_size->rows, game_elements->board_size->cols, visited)) {
                visited[new_row][new_col] = 1;
                save[new_row][new_col] = current;
                Point next = {new_row, new_col};
                if (b < 1000) {
                    array[b++] = next;
                }
            }
        }
    }
    return start;
}
int random(int min, int max)
{
    int number = rand() % (max - min);
    return min + number;
}
void random_position(Ghost *ghost, GameElements *game_elements)
{
    do {
        ghost->i = GetRandomValue(0, game_elements->board_size->cols - 1);
        ghost->j = GetRandomValue(0, game_elements->board_size->rows - 1);
    } while(game_elements->Board[ghost->j][ghost->i] != 0);
    ghost->i *= game_elements->BlockSize;
    ghost->j *= game_elements->BlockSize;
}
void init_direction(Ghost *ghost, GameElements *game_elements)
{
    if(ghost->i <= game_elements->board_size->cols / 2)
    {
        ghost->direction = 'r';
    }
    else
    {
        ghost->direction = 'l';
    }
}
void init_ghosts_map(Ghosts *ghosts, GameElements *game_elements)
{
    //pink region 
    ghosts->pink_ghost->direction = 'u';
    ghosts->pink_ghost->time = 0;
    ghosts->pink_ghost->exist_flag = false;
    ghosts->pink_ghost->blink_flag = true;
    random_position(ghosts->pink_ghost, game_elements);
    init_direction(ghosts->pink_ghost, game_elements);
    //red ghost
    ghosts->red_ghost->direction = 'u';
    ghosts->red_ghost->time = 0;
    ghosts->red_ghost->exist_flag = false;
    ghosts->red_ghost->blink_flag = true;
    random_position(ghosts->red_ghost, game_elements);
    init_direction(ghosts->pink_ghost, game_elements);
    //blue ghost
    ghosts->blue_ghost->direction = 'l';
    ghosts->blue_ghost->time = 0;
    ghosts->blue_ghost->exist_flag = false;
    ghosts->blue_ghost->blink_flag = true; 
    random_position(ghosts->blue_ghost, game_elements);
    init_direction(ghosts->pink_ghost, game_elements);
    //green ghost
    ghosts->green_ghost->direction = 'r';
    ghosts->green_ghost->time = 0;
    ghosts->green_ghost->exist_flag = false;
    ghosts->green_ghost->blink_flag = true;
    random_position(ghosts->green_ghost, game_elements);
    init_direction(ghosts->pink_ghost, game_elements);

    if(game_elements->game_flags->medium_flag || game_elements->game_flags->hard_flag)
    {
        //fire red ghost
        ghosts->fire_red_ghost->direction = 'l';
        ghosts->fire_red_ghost->time = 0;
        ghosts->fire_red_ghost->exist_flag = false;
        ghosts->fire_red_ghost->blink_flag = true; 
        random_position(ghosts->fire_red_ghost, game_elements);
        init_direction(ghosts->pink_ghost, game_elements);

        //yellow ghost
        ghosts->yellow_ghost->direction = 'd';
        ghosts->yellow_ghost->time = 0;
        ghosts->yellow_ghost->exist_flag = false;
        ghosts->yellow_ghost->blink_flag = true;
        random_position(ghosts->yellow_ghost, game_elements);
        init_direction(ghosts->pink_ghost, game_elements);


        if(game_elements->game_flags->hard_flag)
        {
            //fire blue ghost
            ghosts->fire_blue_ghost->direction = 'l';  
            ghosts->fire_blue_ghost->time = 0;
            ghosts->fire_blue_ghost->exist_flag = false;
            ghosts->fire_blue_ghost->blink_flag = true;  
            random_position(ghosts->fire_blue_ghost, game_elements);
            init_direction(ghosts->pink_ghost, game_elements);
            //brown ghost
            ghosts->brown_ghost->direction = 'd';
            ghosts->brown_ghost->time = 0;
            ghosts->brown_ghost->exist_flag = false;
            ghosts->brown_ghost->blink_flag = true;
            random_position(ghosts->brown_ghost, game_elements);
            init_direction(ghosts->pink_ghost, game_elements);
        }
    }
}
int random_direction(Ghost *ghost, GameElements *game_elements, int *current_row, int *current_col, Timer *time)
{
    
    int number = 0;
    if(time->time_direction >= 0.4)
        number = GetRandomValue(1, 2);


    if((ghost->direction == 'u' || ghost->direction == 'd'))
    {
        if(number == 1 && (*current_col != game_elements->board_size->cols - 1) && game_elements->Board[*current_row][*current_col + 1] != 1)
        {
            ghost->direction = 'r';
            ghost->j = *current_row * game_elements->BlockSize;
            ghost->i = *current_col * game_elements->BlockSize;
        }
        else if(number == 2 && (*current_col != 0) && game_elements->Board[*current_row][*current_col - 1] != 1)
        {    
            ghost->direction = 'l';
            ghost->j = *current_row * game_elements->BlockSize;
            ghost->i = *current_col * game_elements->BlockSize;
        }
    }
    else if((ghost->direction == 'r' || ghost->direction == 'l'))
    {
        if(number == 1 && (*current_row != 0) && game_elements->Board[*current_row - 1][*current_col] != 1)
        {    
            ghost->direction = 'u';
            ghost->j = *current_row * game_elements->BlockSize;
            ghost->i = *current_col * game_elements->BlockSize;
        }
        else if(number == 2 && (*current_row != game_elements->board_size->rows - 1) && game_elements->Board[*current_row + 1][*current_col] != 1)
        {    
            ghost->direction = 'd';
            ghost->j = *current_row * game_elements->BlockSize;
            ghost->i = *current_col * game_elements->BlockSize;
        }
    }
}
int ghost_move(GameElements *game_elements, Ghost *ghost)
{
    if(!ghost->blink_flag && !ghost->exist_flag && ghost->time >= 5)
    {
        ghost->time = 0;
        ghost->blink_flag = true;
    }
    else if(ghost->blink_flag && !ghost->exist_flag)
    {
        if(ghost->time >= 3)
        {
            ghost->exist_flag = true;
            ghost->blink_flag = false;
        }
        if((int) (ghost->time * 10 / 2) % 2)
        {
            DrawTexture(ghost->direction == 'u' ? ghost->ghost_up :
            (ghost->direction == 'd' ? ghost->ghost_down : 
            (ghost->direction == 'l' ? ghost->ghost_left : ghost->ghost_right)),
            ghost->i + game_elements->zero_point->x,
            ghost->j + game_elements->zero_point->y, WHITE);
        }
    }
    else if(ghost->exist_flag && !ghost->blink_flag)
    {
        int current_col = rounds(ghost->i, game_elements->BlockSize, 0.5);
        int current_row = rounds(ghost->j, game_elements->BlockSize, 0.5);
        
        DrawTexture(ghost->ghost_up, ghost->i + game_elements->zero_point->x, ghost->j + game_elements->zero_point->y, WHITE);
        
        if(ghost->direction == 'u')
        {
            DrawTexture(ghost->ghost_up, ghost->i + game_elements->zero_point->x, ghost->j + game_elements->zero_point->y, WHITE);
            current_col = rounds(ghost->i, game_elements->BlockSize, 0.9);
            current_row = rounds(ghost->j, game_elements->BlockSize, 0.1);        
        }
        else if(ghost->direction == 'd')
        {
            DrawTexture(ghost->ghost_down, ghost->i + game_elements->zero_point->x, ghost->j + game_elements->zero_point->y, WHITE);
            current_col = rounds(ghost->i, game_elements->BlockSize, 0.1);
            current_row = rounds(ghost->j, game_elements->BlockSize, 0.9);        
        }
        else if(ghost->direction == 'r')
        {
            DrawTexture(ghost->ghost_right, ghost->i + game_elements->zero_point->x, ghost->j + game_elements->zero_point->y, WHITE);
            current_col = rounds(ghost->i, game_elements->BlockSize, 0.9);
            current_row = rounds(ghost->j, game_elements->BlockSize, 0.1);
        }
        else if(ghost->direction == 'l')
        {
            DrawTexture(ghost->ghost_left, ghost->i + game_elements->zero_point->x, ghost->j + game_elements->zero_point->y, WHITE);
            current_col = rounds(ghost->i, game_elements->BlockSize, 0.1);
            current_row = rounds(ghost->j, game_elements->BlockSize, 0.9);        
        }

        random_direction(ghost, game_elements, &current_row, &current_col, game_elements->timer);

        if(ghost->direction == 'u' && current_row > 0 && game_elements->Board[current_row - 1][current_col] != 1)
            ghost->j -= GetFrameTime() * game_elements->ghosts->ghost_speed;
        else if(ghost->direction == 'd' && (current_row < game_elements->board_size->rows - 1) && game_elements->Board[current_row + 1][current_col] != 1)    
            ghost->j += GetFrameTime() * game_elements->ghosts->ghost_speed;
        else if(ghost->direction == 'r' && (current_col < game_elements->board_size->cols - 1) && game_elements->Board[current_row][current_col + 1] != 1)     
            ghost->i += GetFrameTime() * game_elements->ghosts->ghost_speed;
        else if(ghost->direction == 'l' && current_col > 0 && game_elements->Board[current_row][current_col - 1] != 1)     
            ghost->i -= GetFrameTime() * game_elements->ghosts->ghost_speed;
    }
}
void chase_pacman(Ghost *ghost, GameElements *game_elements) {
    
    if(!ghost->blink_flag && !ghost->exist_flag && ghost->time >= 5)
    {
        ghost->time = 0;
        ghost->blink_flag = true;
    }
    else if(!ghost->exist_flag && ghost->blink_flag)
    {
        if(ghost->time >= 3)
        {
            ghost->exist_flag = true;
            ghost->blink_flag = false;
        }
        if((int) (ghost->time * 10 / 2) % 2)
        {
            DrawTexture(ghost->direction == 'u' ? ghost->ghost_up :
            (ghost->direction == 'd' ? ghost->ghost_down : 
            (ghost->direction == 'l' ? ghost->ghost_left : ghost->ghost_right)),
            ghost->i + game_elements->zero_point->x,
            ghost->j + game_elements->zero_point->y, WHITE);
        }
    }
    else if(ghost->exist_flag && !ghost->blink_flag && game_elements->pacman->exist_flag && !game_elements->fruits->Cherry->ability_flag)
    {
        Point next_step = find_next_step(ghost, game_elements);
        int current_row = ghost->j / game_elements->BlockSize;
        int current_col = ghost->i / game_elements->BlockSize;

        if(ghost->direction == 'u')
        {
            current_col = rounds(ghost->i, game_elements->BlockSize, 0.99);
            current_row = rounds(ghost->j, game_elements->BlockSize, 0.01);        
        }
        else if(ghost->direction == 'd')
        {
            current_col = rounds(ghost->i, game_elements->BlockSize, 0.01);
            current_row = rounds(ghost->j, game_elements->BlockSize, 0.99);        
        }
        else if(ghost->direction == 'r')
        {
            current_col = rounds(ghost->i, game_elements->BlockSize, 0.99);
            current_row = rounds(ghost->j, game_elements->BlockSize, 0.01);
        }
        else if(ghost->direction == 'l')
        {
            current_col = rounds(ghost->i, game_elements->BlockSize, 0.01);
            current_row = rounds(ghost->j, game_elements->BlockSize, 0.99);        
        }


        if (next_step.row < current_row && game_elements->Board[current_row - 1][current_col] != 1) {
            if(ghost->direction != 'u')
            {
                ghost->i = current_col * game_elements->BlockSize;
                ghost->j = current_row * game_elements->BlockSize;
            }
            ghost->direction = 'u';
        } else if (next_step.row > current_row && game_elements->Board[current_row + 1][current_col] != 1) {
            if(ghost->direction != 'd')
            {
                ghost->i = current_col * game_elements->BlockSize;
                ghost->j = current_row * game_elements->BlockSize;
            }
            ghost->direction = 'd';
        } else if (next_step.col < current_col && game_elements->Board[current_row][current_col - 1] != 1) {
            if(ghost->direction != 'l')
            {
                ghost->i = current_col * game_elements->BlockSize;
                ghost->j = current_row * game_elements->BlockSize;
            }            
            ghost->direction = 'l';
        } else if (next_step.col > current_col && game_elements->Board[current_row][current_col + 1] != 1) {           
            if(ghost->direction != 'r')
            {
                ghost->i = current_col * game_elements->BlockSize;
                ghost->j = current_row * game_elements->BlockSize;
            }            
            ghost->direction = 'r';
        }

        if (ghost->direction == 'u') {
            ghost->j -= GetFrameTime() * game_elements->ghosts->ghost_speed;
            DrawTexture(ghost->ghost_up, ghost->i + game_elements->zero_point->x, ghost->j + game_elements->zero_point->y, WHITE);
        } else if (ghost->direction == 'd') {
            ghost->j += GetFrameTime() * game_elements->ghosts->ghost_speed;
            DrawTexture(ghost->ghost_down, ghost->i + game_elements->zero_point->x, ghost->j + game_elements->zero_point->y, WHITE);
        } else if (ghost->direction == 'l') {
            ghost->i -= GetFrameTime() * game_elements->ghosts->ghost_speed;
            DrawTexture(ghost->ghost_left, ghost->i + game_elements->zero_point->x, ghost->j + game_elements->zero_point->y, WHITE);
        } else if (ghost->direction == 'r') {
            ghost->i += GetFrameTime() * game_elements->ghosts->ghost_speed;
            DrawTexture(ghost->ghost_right, ghost->i + game_elements->zero_point->x, ghost->j + game_elements->zero_point->y, WHITE);
        }
    }
    else if(ghost->exist_flag && !ghost->blink_flag && !game_elements->pacman->exist_flag)
    {
        if (ghost->direction == 'u') {
            DrawTexture(ghost->ghost_up, ghost->i + game_elements->zero_point->x, ghost->j + game_elements->zero_point->y, WHITE);
        } else if (ghost->direction == 'd') {
            DrawTexture(ghost->ghost_down, ghost->i + game_elements->zero_point->x, ghost->j + game_elements->zero_point->y, WHITE);
        } else if (ghost->direction == 'l') {
            DrawTexture(ghost->ghost_left, ghost->i + game_elements->zero_point->x, ghost->j + game_elements->zero_point->y, WHITE);
        } else if (ghost->direction == 'r') {
            DrawTexture(ghost->ghost_right, ghost->i + game_elements->zero_point->x, ghost->j + game_elements->zero_point->y, WHITE);
        }
    }
    else if(ghost->exist_flag && !ghost->blink_flag && game_elements->pacman->exist_flag && game_elements->fruits->Cherry->ability_flag)
    {
        ghost_move(game_elements, ghost);
    }
}



#endif
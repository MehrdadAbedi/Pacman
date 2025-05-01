#ifndef RECORDS_H
#define RECORDS_H

#include "initial_functions.h"

void swap(GameInfo **info_array, int i, int j)
{
    GameInfo temp = (*info_array)[i];
    (*info_array)[i] = (*info_array)[j];
    (*info_array)[j] = temp;
}
int sort_array(GameInfo **info_array, int end, int sort_code)
{
    int start = 0;
    while(start < end)
    {
        for(int i = end; i > start; i--)
        {
            if(*((int*) (*info_array + i) + sort_code) > *((int*) (*info_array + i - 1) + sort_code))
            {
                swap(info_array, i, i - 1);
            }
        }
        start++;
    }
}
void save_data(const char *filename, GameInfo *game_info)
{
    FILE *records = fopen(filename, "a");
    if(records == NULL)
        exit(1);
    fprintf(records, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", game_info->text, game_info->minutes, game_info->seconds,
    game_info->game_scores, game_info->pepper_num, game_info->cherry_num, game_info->apple_num,
    game_info->mushroom_num, game_info->ghost_eat, game_info->mode_code, game_info->year, game_info->month,
    game_info->day, game_info->hour, game_info->min, game_info->hardness);
    fclose(records);
}
int read_data(const char *filename, GameInfo **info_array)
{
    FILE *file = fopen(filename, "r");
    if(file == NULL)
        return 0;
    
    *info_array = (GameInfo *)malloc(sizeof(GameInfo));
    (*info_array)[0].text = (char *)malloc(20 * sizeof(char));

    int i = 0;

    while(fscanf(file, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
    (*info_array)[i].text,
    &(*info_array)[i].minutes,
    &(*info_array)[i].seconds,
    &(*info_array)[i].game_scores,
    &(*info_array)[i].pepper_num,
    &(*info_array)[i].cherry_num,
    &(*info_array)[i].apple_num,
    &(*info_array)[i].mushroom_num,
    &(*info_array)[i].ghost_eat,
    &(*info_array)[i].mode_code,
    &(*info_array)[i].year,
    &(*info_array)[i].month,
    &(*info_array)[i].day,
    &(*info_array)[i].hour,
    &(*info_array)[i].min,
    &(*info_array)[i].hardness) != EOF)
    {
        i++;
        *info_array = (GameInfo*) realloc(*info_array, (i + 1) * sizeof(GameInfo));
        (*info_array)[i].text = (char *)malloc(20 * sizeof(char));
    }
    fclose(file);
    return i;
}
void sort_system(GameElements *game_elements, GameInfo **info_array)
{
    Vector2 mouse = GetMousePosition();
    int blockSize = 120;
    Rectangle rects[8]; 
    for(int counter = 0; counter < 8; counter++) {
        rects[counter] = (Rectangle) {blockSize, blockSize * (counter + 1) + 20 * counter, blockSize, blockSize};
    }

    DrawTexture(game_elements->records->sort_code == 2 ? game_elements->records->star_on : game_elements->records->star_off, 
    rects[0].x, rects[0].y, WHITE);
    DrawTexture(game_elements->records->sort_code == 3 ? game_elements->records->pepper_on : game_elements->records->pepper_off, 
    rects[1].x, rects[1].y, WHITE);
    DrawTexture(game_elements->records->sort_code == 4 ? game_elements->records->cherry_on : game_elements->records->cherry_off, 
    rects[2].x, rects[2].y, WHITE);
    DrawTexture(game_elements->records->sort_code == 5 ? game_elements->records->apple_on : game_elements->records->apple_off, 
    rects[3].x, rects[3].y, WHITE);
    DrawTexture(game_elements->records->sort_code == 6 ? game_elements->records->mushroom_on : game_elements->records->mushroom_off, 
    rects[4].x, rects[4].y, WHITE);
    DrawTexture(game_elements->records->sort_code == 7 ? game_elements->records->ghost_eat_on : game_elements->records->ghost_eat_off, 
    rects[5].x, rects[5].y, WHITE);
    DrawTexture(game_elements->records->sort_code == 8 ? game_elements->records->date_on : game_elements->records->date_off, 
    rects[6].x, rects[6].y, WHITE);
    DrawTexture(game_elements->records->sort_code == 9 ? game_elements->records->time_on : game_elements->records->time_off, 
    rects[7].x, rects[7].y, WHITE);
    if(CheckCollisionPointRec(mouse, rects[0]) && (IsKeyDown(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        game_elements->records->sort_code = 2;
        if(game_elements->game_flags->sounds_flag)
            PlaySound(game_elements->game_sounds->click);
    }
    else if(CheckCollisionPointRec(mouse, rects[1]) && (IsKeyDown(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        game_elements->records->sort_code = 3;
        if(game_elements->game_flags->sounds_flag)
            PlaySound(game_elements->game_sounds->click);
    }
    else if(CheckCollisionPointRec(mouse, rects[2]) && (IsKeyDown(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        game_elements->records->sort_code = 4;
        if(game_elements->game_flags->sounds_flag)
            PlaySound(game_elements->game_sounds->click);
    }
    else if(CheckCollisionPointRec(mouse, rects[3]) && (IsKeyDown(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        game_elements->records->sort_code = 5;
        if(game_elements->game_flags->sounds_flag)
            PlaySound(game_elements->game_sounds->click);
    }
    else if(CheckCollisionPointRec(mouse, rects[4]) && (IsKeyDown(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        game_elements->records->sort_code = 6;
        if(game_elements->game_flags->sounds_flag)
            PlaySound(game_elements->game_sounds->click);
    }
    else if(CheckCollisionPointRec(mouse, rects[5]) && (IsKeyDown(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        game_elements->records->sort_code = 7;
        if(game_elements->game_flags->sounds_flag)
            PlaySound(game_elements->game_sounds->click);
    }
    else if(CheckCollisionPointRec(mouse, rects[6]) && (IsKeyDown(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        game_elements->records->sort_code = 8;
        if(game_elements->game_flags->sounds_flag)
            PlaySound(game_elements->game_sounds->click);
    }
    else if(CheckCollisionPointRec(mouse, rects[7]) && (IsKeyDown(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        game_elements->records->sort_code = 9;
        if(game_elements->game_flags->sounds_flag)
            PlaySound(game_elements->game_sounds->click);
    }
}
void date_sort(GameInfo **info_array, int end)
{
    int start = 0;
    while(start < end)
    {
        for(int i = start; i < end; i++)
        {
            if((*info_array)[i].year < (*info_array)[i + 1].year)
            {
                swap(info_array, i, i + 1);
            }
            else if((*info_array)[i].year == (*info_array)[i + 1].year)
            {
                if((*info_array)[i].month < (*info_array)[i + 1].month)
                {
                    swap(info_array, i, i + 1);
                }
                else if((*info_array)[i].month == (*info_array)[i + 1].month)
                {
                    if((*info_array)[i].day < (*info_array)[i + 1].day)
                    {
                        swap(info_array, i, i + 1);
                    }
                    else if((*info_array)[i].day == (*info_array)[i + 1].day)
                    {
                        if((*info_array)[i].hour < (*info_array)[i + 1].hour)
                        {
                            swap(info_array, i, i + 1);
                        }
                        else if((*info_array)[i].hour == (*info_array)[i + 1].hour)
                        {
                            if((*info_array)[i].min < (*info_array)[i + 1].min)
                            {
                                swap(info_array, i, i + 1);
                            }
                        }
                    }
                }

            }
        }
        end--;
    }
}
void time_sort(GameInfo **info_array, int end)
{
    int start = 0;
    while(start < end)
    {
        for(int i = end; i > start; i--)
        {
            if((*info_array)[i].minutes > (*info_array)[i - 1].minutes)
            {
                swap(info_array, i, i - 1);
            }
            else if((*info_array)[i].minutes == (*info_array)[i - 1].minutes)
            {
                if((*info_array)[i].seconds > (*info_array)[i - 1].seconds)
                {
                    swap(info_array, i, i - 1);
                }
            }
        }
        start++;
    }  
}
int vis_records(const char *filename, GameElements *game_elements)
{
    GameInfo *info_array = NULL;

    int number = read_data(filename, &info_array);

    if((game_elements->records->up_down > GetScreenHeight() - 4000) && (IsKeyPressedRepeat(KEY_DOWN) || IsKeyPressed(KEY_DOWN)))
        game_elements->records->up_down -= 25;
    else if((game_elements->records->up_down < 0) && (IsKeyPressedRepeat(KEY_UP) || IsKeyPressed(KEY_UP)))
        game_elements->records->up_down += 25;
    if(scroll_wheel() < 0 && (game_elements->records->up_down > GetScreenHeight() - 4000))   
    {
        game_elements->records->up_down -= 25;
    } 
    else if(scroll_wheel() > 0 && (game_elements->records->up_down < 0))
    {
        game_elements->records->up_down += 25;
    }
    BeginDrawing();
    ClearBackground(game_elements->setting->background[game_elements->setting->i % 3]);
    sort_system(game_elements, &info_array);
    if(game_elements->records->sort_code == 8)
        date_sort(&info_array, number - 1); 
    else if(game_elements->records->sort_code == 9)
        time_sort(&info_array, number - 1);
    else
        sort_array(&info_array, number - 1, game_elements->records->sort_code);
    DrawTexture(game_elements->menu->back, 100, GetScreenHeight() - 200, WHITE);
    for(int i = 0; i < (number < 10 ? number : 10); i++)
    {
        DrawTexture(game_elements->records->record_bar, GetScreenWidth() / 2 - game_elements->records->record_bar.width / 2, 100 + i * 380 + game_elements->records->up_down, WHITE);
        
        DrawTextEx(game_elements->menu->font, TextFormat("%s", (info_array + i)->text), (Vector2){
        GetScreenWidth() / 2 - game_elements->records->record_bar.width / 2 + 241, 155 + i * 380 + game_elements->records->up_down},
        50, 1, YELLOW);
        DrawTextEx(game_elements->menu->font, TextFormat("%d", (info_array + i)->game_scores), (Vector2){
        GetScreenWidth() / 2 - game_elements->records->record_bar.width / 2 + 1186 + 73, 155 + i * 380 + game_elements->records->up_down},
        50, 1, YELLOW);
        DrawTextEx(game_elements->menu->font, TextFormat("%d:%d", (info_array + i)->minutes, (info_array + i)->seconds), (Vector2){
        GetScreenWidth() / 2 - game_elements->records->record_bar.width / 2 + 1505 + 73, 155 + i * 380 + game_elements->records->up_down},
        50, 1, YELLOW);
        DrawTextEx(game_elements->menu->font, TextFormat("%d", (info_array + i)->pepper_num), (Vector2){
        GetScreenWidth() / 2 - game_elements->records->record_bar.width / 2 + 1905 + 73, 155 + i * 380 + game_elements->records->up_down},
        50, 1, YELLOW);
        DrawTextEx(game_elements->menu->font, TextFormat("%d", (info_array + i)->cherry_num), (Vector2){
        GetScreenWidth() / 2 - game_elements->records->record_bar.width / 2 + 2245 + 73, 155 + i * 380 + game_elements->records->up_down},
        50, 1, YELLOW);
        DrawTextEx(game_elements->menu->font, TextFormat("%d", (info_array + i)->apple_num), (Vector2){
        GetScreenWidth() / 2 - game_elements->records->record_bar.width / 2 + 163 + 73, 315 + i * 380 + game_elements->records->up_down},
        50, 1, YELLOW);
        DrawTextEx(game_elements->menu->font, TextFormat("%d", (info_array + i)->mushroom_num), (Vector2){
        GetScreenWidth() / 2 - game_elements->records->record_bar.width / 2 + 500 + 73, 315 + i * 380 + game_elements->records->up_down},
        50, 1, YELLOW);
        DrawTextEx(game_elements->menu->font, TextFormat("%d", (info_array + i)->ghost_eat), (Vector2){
        GetScreenWidth() / 2 - game_elements->records->record_bar.width / 2 + 825 + 73, 315 + i * 380 + game_elements->records->up_down},
        50, 1, YELLOW);
        DrawTextEx(game_elements->menu->font, TextFormat("%s", (info_array + i)->mode_code == 1 ? "CLASSIC" : ((info_array + i)->mode_code == 2 ? "FANTASY" : "GREEN")), (Vector2){
        GetScreenWidth() / 2 - game_elements->records->record_bar.width / 2 + 1170 + 73, 315 + i * 380 + game_elements->records->up_down},
        50, 1, YELLOW);
        DrawTextEx(game_elements->menu->font, TextFormat("%d/%d/%d %d:%d", (info_array + i)->year, (info_array + i)->month, 
        (info_array + i)->day, (info_array + i)->hour, (info_array + i)->min), (Vector2){
        GetScreenWidth() / 2 - game_elements->records->record_bar.width / 2 + 1630 + 73, 315 + i * 380 + game_elements->records->up_down},
        50, 1, YELLOW);
        DrawTextEx(game_elements->menu->font, TextFormat("%d.", i + 1), (Vector2) {GetScreenWidth() / 2 - game_elements->records->record_bar.width / 2 + 10, 110 + i * 380 + game_elements->records->up_down}, 50, 0, YELLOW);
        if((info_array + i)->hardness == 2)
            DrawTexture(game_elements->records->medium, GetScreenWidth() / 2 + game_elements->records->record_bar.width / 2 - game_elements->records->medium.width,
            100 + i * 380 + game_elements->records->up_down, WHITE);
        else if((info_array + i)->hardness == 3)
            DrawTexture(game_elements->records->hard, GetScreenWidth() / 2 + game_elements->records->record_bar.width / 2 - game_elements->records->hard.width,
            100 + i * 380 + game_elements->records->up_down, WHITE);            
    }
    EndDrawing();
    free(info_array);
    return 0;
}

#endif
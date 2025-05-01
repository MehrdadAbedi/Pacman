#ifndef MENU_H
#define MENU_H

#include "records.h"


Color YellowTheme = (Color) {255, 196, 49, 255};
Color BoxColor = (Color) {21, 209, 207, 255};

void name_window(GameElements *game_elements)
{
    BeginDrawing();
    ClearBackground(game_elements->setting->background[game_elements->setting->i % 3]);

    const char *prompt = "Please enter your name:";
    Vector2 prompt_size = MeasureTextEx(game_elements->menu->font, prompt, 50, 1);
    DrawTextEx(game_elements->menu->font, prompt, (Vector2){GetScreenWidth() / 2 - prompt_size.x / 2, GetScreenHeight() / 2 - 100}, 
               50, 1, (Color){0, 242, 218, 255});


    int assci;
    while ((assci = GetCharPressed()) > 0)
    {
        if ((assci >= 32) && (assci <= 125) && (game_elements->i < 20))
        {
            game_elements->player[game_elements->i] = (char) (assci == 32 ? 45 : assci);
            game_elements->i++;
            game_elements->player[game_elements->i] = '\0';
        }
    }

    if (IsKeyPressed(KEY_BACKSPACE) && game_elements->i > 0)
    {
        game_elements->i--;
        game_elements->player[game_elements->i] = '\0';
    }
    
    DrawTextEx(game_elements->menu->font, game_elements->player, (Vector2) {GetScreenWidth() / 2 - prompt_size.x / 2 + 10, GetScreenHeight() / 2}, 50, 1, (Color){0, 242, 218, 255});

    if(IsKeyPressed(KEY_ENTER))
    {
        game_elements->game_flags->window_name_flag = false;
    }

    EndDrawing();
}
void setting_window(GameElements *game_elements)
{
    Vector2 mouse = GetMousePosition();
    BeginDrawing();
    ClearBackground(game_elements->setting->background[game_elements->setting->i % 3]);
    Rectangle rect = (Rectangle) {GetScreenWidth() / 2 - 1500 / 2, GetScreenHeight() / 2 - 1000 / 2, 1500, 1000}; 
    DrawRectangle(rect.x, rect.y, rect.width, rect.height, YellowTheme);
    Rectangle container1 = (Rectangle) {rect.x + 50, rect.y + 50, 675, 750};
    DrawRectangle(container1.x, container1.y, container1.width, container1.height, BoxColor);
    Rectangle container2 = (Rectangle) {rect.x + 775, rect.y + 50, 675, 750};
    DrawRectangle(container2.x, container2.y, container2.width, container2.height, BoxColor);
    Rectangle container3 = (Rectangle) {rect.x + 50, rect.y + 850, 1400, 100};
    DrawRectangle(container3.x, container3.y, container3.width, container3.height, BoxColor);
    if(game_elements->game_flags->easy_flag)
    {
        DrawRectangle(container1.x + 47.5 - 5, container1.y + 71.25 - 5, 589, 165, RED);
    }
    if(CheckCollisionPointRec(mouse, (Rectangle){container1.x + 47.5 - 5, container1.y + 71.25 - 5, 589, 165}) &&
    (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        if(game_elements->game_flags->sounds_flag)
        {
            PlaySound(game_elements->game_sounds->click);
        }        
        game_elements->game_flags->easy_flag = true;
        game_elements->game_flags->medium_flag = false;
        game_elements->game_flags->hard_flag = false;
        game_elements->ghosts->ghost_speed = 125;
    }
    DrawTexture(game_elements->setting->easy, container1.x + 47.5, container1.y + 71.25, WHITE);
    if(game_elements->game_flags->medium_flag)
    {
        DrawRectangle(container1.x + 47.5 - 5, container1.y + 71.25 * 2 + 155 - 5, 589, 165, RED);
    }
    if(CheckCollisionPointRec(mouse, (Rectangle){container1.x + 47.5 - 5, container1.y + 71.25 * 2 + 155 - 5, 589, 165}) &&
    (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        if(game_elements->game_flags->sounds_flag)
        {
            PlaySound(game_elements->game_sounds->click);
        }         
        game_elements->game_flags->easy_flag = false;
        game_elements->game_flags->medium_flag = true;
        game_elements->game_flags->hard_flag = false;
        game_elements->ghosts->ghost_speed = 150;
    }
    DrawTexture(game_elements->setting->medium, container1.x + 47.5, container1.y + 71.25 * 2 + 155, WHITE);
    if(game_elements->game_flags->hard_flag)
    {
        DrawRectangle(container1.x + 47.5 - 5, container1.y + 71.25 * 3 + 155 * 2 - 5, 589, 165, RED);
    }
    if(CheckCollisionPointRec(mouse, (Rectangle){container1.x + 47.5 - 5, container1.y + 71.25 * 3 + 155 * 2 - 5, 589, 165}) &&
    (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        if(game_elements->game_flags->sounds_flag)
        {
            PlaySound(game_elements->game_sounds->click);
        }  
        game_elements->game_flags->easy_flag = false;
        game_elements->game_flags->medium_flag = false;
        game_elements->game_flags->hard_flag = true;
        game_elements->ghosts->ghost_speed = 175;
    }
    DrawTexture(game_elements->setting->hard, container1.x + 47.5, container1.y + 71.25 * 3 + 155 * 2, WHITE);
    const char* txt = "Music";
    Vector2 text_size = MeasureTextEx(game_elements->menu->font, txt, 80, 1);
    DrawTextEx(game_elements->menu->font, txt, (Vector2) {container2.x + 80, container2.y + 130}, 80, 1, YELLOW);
    txt = "Sound";
    Vector2 txtsize0 = MeasureTextEx(game_elements->menu->font, txt, 80, 1);
    DrawTextEx(game_elements->menu->font, txt, (Vector2) {container2.x + 80, container2.y + 130 * 2 + text_size.y}, 80, 1, YELLOW);
    DrawTexture(game_elements->game_flags->sounds_flag ? game_elements->setting->sounds_on : game_elements->setting->sounds_off, container2.x + container2.width - 200, container2.y + 130 * 2 + text_size.y + txtsize0.y / 2 - 60, WHITE);
    if(CheckCollisionPointRec(mouse, (Rectangle) {container2.x + container2.width - 200, container2.y + 130 * 2 + text_size.y + txtsize0.y / 2 - 60, 
    game_elements->setting->sounds_on.width, game_elements->setting->sounds_on.height}) &&
    (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        if(game_elements->game_flags->sounds_flag)
        {
            PlaySound(game_elements->game_sounds->click);
        }
        game_elements->game_flags->sounds_flag = !game_elements->game_flags->sounds_flag;
    }   
    DrawTexture(game_elements->game_flags->music_flag ? game_elements->setting->music_on : game_elements->setting->music_off, container2.x + container2.width - 200, container2.y + 130 + text_size.y / 2 - 60, WHITE); 
    if(CheckCollisionPointRec(mouse, (Rectangle) {container2.x + container2.width - 200, container2.y + 130 + text_size.y / 2 - 60, game_elements->setting->music_on.width,
    game_elements->setting->music_on.height}) &&
    (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        if(game_elements->game_flags->sounds_flag)
        {
            PlaySound(game_elements->game_sounds->click);
        }
        game_elements->game_flags->music_flag = !game_elements->game_flags->music_flag;
    }
    /*if(CheckCollisionPointRec(mouse, (Rectangle) {GetScreenWidth() / 2 - game_elements->setting->window.width / 2 + 1233, GetScreenHeight() / 2 - game_elements->setting->window.height / 2 + 728, game_elements->setting->music.width, game_elements->setting->music.height}) &&
    (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        if(game_elements->game_flags->sounds_flag)
        {
            PlaySound(game_elements->game_sounds->click);
        }        
        game_elements->setting->i++;
    }*/
    //DrawRectangle(GetScreenWidth() / 2 - game_elements->setting->window.width / 2 + 1233, GetScreenHeight() / 2 - game_elements->setting->window.height / 2 + 728, game_elements->setting->music.width, game_elements->setting->music.height, game_elements->setting->background[game_elements->setting->i % 3]);
    DrawTexture(game_elements->menu->back, 100, GetScreenHeight() - 200, WHITE);
    if(CheckCollisionPointRec(mouse, (Rectangle) {100, GetScreenHeight() - 200, game_elements->menu->back.width, game_elements->menu->back.height}) && (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_ENTER)))
        game_elements->game_flags->setting_flag = false;
    DrawRectangle(container3.x, container3.y, container3.width, container3.height, game_elements->game_flags->name_flag ? (Color){230, 69, 96, 255} : BoxColor);
    char *text = "player's name:";
    text_size = MeasureTextEx(game_elements->menu->font, text, 50, 0);
    DrawTextEx(game_elements->menu->font, text, (Vector2) {container3.x + 50, container3.y + container3.height / 2 - text_size.y / 2}, 50, 0, (Color){3, 56, 244, 255});
    if(CheckCollisionPointRec(mouse, container3) && (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        if(!game_elements->game_flags->name_flag)
        {
            game_elements->game_flags->name_flag = true;
        }
    }
    if(game_elements->game_flags->name_flag)
    {
        int assci = GetCharPressed();
        if(IsKeyPressed(KEY_BACKSPACE) && game_elements->i > 0)
        {
            game_elements->player[game_elements->i - 1] = '\0';
            game_elements->i--; 
        }
        while(assci > 0)
        {
            if((assci >= 32) && (assci <= 125) && (game_elements->i < 20))
            {
                game_elements->player[game_elements->i] = (char) (assci == 32 ? 45 : assci);
                game_elements->i++;
                game_elements->player[game_elements->i] = '\0';
            }
            assci = GetCharPressed();
        }
        if(IsKeyPressed(KEY_ENTER))
        {
            game_elements->game_flags->name_flag = false;
        }
    }
    DrawTextEx(game_elements->menu->font, game_elements->player, (Vector2){container3.x + 50 + text_size.x + 20, container3.y + container3.height / 2 - text_size.y / 2}, 50, 0, (Color){3, 56, 244, 255});
    EndDrawing();
}
void game_over_screen(GameElements *game_elements) 
{
    if(game_elements->game_flags->classic_map_flag)
        game_elements->game_info->mode_code = 1;
    else if(game_elements->game_flags->fantasy_map_flag)
        game_elements->game_info->mode_code = 2;
    else if(game_elements->game_flags->rotated_map_flag)
        game_elements->game_info->mode_code = 3;
    time_t current_time = time(NULL);
    struct tm *localTime = localtime(&current_time);
    game_elements->game_info->year = localTime->tm_year + 1900;
    game_elements->game_info->month = localTime->tm_mon + 1;
    game_elements->game_info->day = localTime->tm_mday;
    game_elements->game_info->hour = localTime->tm_hour;
    game_elements->game_info->min = localTime->tm_min;
    game_elements->game_info->text = game_elements->player;
    if(game_elements->game_flags->easy_flag)
        game_elements->game_info->hardness = 1;
    else if(game_elements->game_flags->medium_flag)
        game_elements->game_info->hardness = 2;
    else if(game_elements->game_flags->hard_flag)
        game_elements->game_info->hardness = 3;

    BeginTextureMode(game_elements->border->tranparent_layer);
    ClearBackground((Color){0, 0, 0, 0});

    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), (Color){155, 0, 0, 128});

    EndTextureMode(); 

    BeginDrawing();
    ClearBackground(game_elements->setting->background[game_elements->setting->i % 3]);

    DrawTextureRec(game_elements->border->tranparent_layer.texture, 
                   (Rectangle){0, 0, (float)GetScreenWidth(), -(float)GetScreenHeight()}, 
                   (Vector2){0, 0}, 
                   WHITE);

    const char *text = "GAME OVER!!!";
    Vector2 textsize = MeasureTextEx(game_elements->menu->font, text, 100, 1);
    DrawTextEx(game_elements->menu->font, text, (Vector2){(GetScreenWidth() - textsize.x) / 2, (GetScreenHeight() - textsize.y) / 2 - 500},
    100, 1, WHITE);
    DrawTexture(game_elements->menu->back, 100, GetScreenHeight() - 200, WHITE);
    Vector2 mouse = GetMousePosition();
    if(CheckCollisionPointRec(mouse, (Rectangle){100, GetScreenHeight() - 200, 100, 100}) && (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        game_elements->game_flags->classic_map_flag = false;
        game_elements->game_flags->fantasy_map_flag = false;
        game_elements->game_flags->rotated_map_flag = false;
        game_elements->game_flags->start_flag = false;
    }


    Rectangle rects[10];
    for(int i = 0; i < 5; i++) {
        rects[2 * i] = (Rectangle) {(GetScreenWidth() - 1200) / 2 + 50, (GetScreenHeight() - 800) / 2 + 50 + i * (120 + 25), 525, 120};
        rects[2 * i + 1] = (Rectangle) {(GetScreenWidth() - 1200) / 2 + 50 + 525 + 50, (GetScreenHeight() - 800) / 2 + 50 + i * (120 + 25), 525, 120};
    }

    DrawTexture(game_elements->border->score_board, (GetScreenWidth() - game_elements->border->score_board.width) / 2, (GetScreenHeight() - game_elements->border->score_board.height) / 2, WHITE);
    DrawRectangle((GetScreenWidth() - 1200) / 2, (GetScreenHeight() - 800) / 2, 1200, 800, YellowTheme);
    for(int i = 0; i < 10; i++) {
        DrawRectangle(rects[i].x, rects[i].y, rects[i].width, rects[i].height, BoxColor);
    }

    DrawTexture(game_elements->records->star_on, rects[0].x, rects[0].y, WHITE);
    DrawTexture(game_elements->records->time_on, rects[1].x, rects[1].y, WHITE);
    DrawTexture(game_elements->records->pepper_on, rects[2].x, rects[2].y, WHITE);
    DrawTexture(game_elements->records->cherry_on, rects[3].x, rects[3].y, WHITE);
    DrawTexture(game_elements->records->apple_on, rects[4].x, rects[4].y, WHITE);
    DrawTexture(game_elements->records->mushroom_on, rects[5].x, rects[5].y, WHITE);
    DrawTexture(game_elements->records->date_on, rects[6].x, rects[6].y, WHITE);
    DrawTexture(game_elements->records->ghost_eat_on, rects[7].x, rects[7].y, WHITE);

    text = TextFormat("%d", game_elements->game_info->game_scores);
    textsize = MeasureTextEx(game_elements->menu->font, text, 80, 1);
    DrawTextEx(game_elements->menu->font, text, (Vector2)
    {rects[0].x + rects[0].width / 2 - textsize.x / 2, rects[0].y + rects[0].height / 2 - textsize.y / 2}, 80, 1, YELLOW);
    text = TextFormat("%d:%d", game_elements->game_info->minutes, game_elements->game_info->seconds);
    textsize = MeasureTextEx(game_elements->menu->font, text, 80, 1);
    DrawTextEx(game_elements->menu->font, text, (Vector2)
    {rects[1].x + rects[1].width / 2 - textsize.x / 2, rects[1].y + rects[1].height / 2 - textsize.y / 2}, 80, 1, YELLOW);
    text = TextFormat("%d", game_elements->game_info->pepper_num);
    textsize = MeasureTextEx(game_elements->menu->font, text, 80, 1);
    DrawTextEx(game_elements->menu->font, text, (Vector2)
    {rects[2].x + rects[2].width / 2 - textsize.x / 2, rects[2].y + rects[2].height / 2 - textsize.y / 2}, 80, 1, YELLOW);
    text = TextFormat("%d", game_elements->game_info->cherry_num);
    textsize = MeasureTextEx(game_elements->menu->font, text, 80, 1);
    DrawTextEx(game_elements->menu->font, text, (Vector2)
    {rects[3].x + rects[3].width / 2 - textsize.x / 2, rects[3].y + rects[3].height / 2 - textsize.y / 2}, 80, 1, YELLOW);   
    text = TextFormat("%d", game_elements->game_info->apple_num);
    textsize = MeasureTextEx(game_elements->menu->font, text, 80, 1);
    DrawTextEx(game_elements->menu->font, text, (Vector2)
    {rects[4].x + rects[4].width / 2 - textsize.x / 2, rects[4].y + rects[4].height / 2 - textsize.y / 2}, 80, 1, YELLOW);   
    text = TextFormat("%d", game_elements->game_info->mushroom_num);
    textsize = MeasureTextEx(game_elements->menu->font, text, 80, 1);
    DrawTextEx(game_elements->menu->font, text, (Vector2)
    {rects[5].x + rects[5].width / 2 - textsize.x / 2, rects[5].y + rects[5].height / 2 - textsize.y / 2}, 80, 1, YELLOW);   
    text = TextFormat("%d/%d/%d\n%d:%d", game_elements->game_info->year, game_elements->game_info->month, game_elements->game_info->day,
    game_elements->game_info->hour, game_elements->game_info->min);
    textsize = MeasureTextEx(game_elements->menu->font, text, 50, -1);
    DrawTextEx(game_elements->menu->font, text, (Vector2)
    {rects[6].x + rects[6].width / 2 - textsize.x / 2, rects[6].y + rects[6].height / 2 - textsize.y / 2}, 50, -1, YELLOW);
    text = TextFormat("%d", game_elements->game_info->ghost_eat);
    textsize = MeasureTextEx(game_elements->menu->font, text, 80, 1);
    DrawTextEx(game_elements->menu->font, text, (Vector2)
    {rects[7].x + rects[7].width / 2 - textsize.x / 2, rects[7].y + rects[7].height / 2 - textsize.y / 2}, 80, 1, YELLOW);
    text = "MENU";
    textsize = MeasureTextEx(game_elements->menu->font, text, 80, 1);   
    if(CheckCollisionPointRec(mouse, rects[8]))
    {
        DrawRectangle(rects[8].x, rects[8].y, rects[8].width, rects[8].height, GREEN);
        if(IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            game_elements->game_flags->classic_map_flag = false;
            game_elements->game_flags->fantasy_map_flag = false;
            game_elements->game_flags->rotated_map_flag = false;
            game_elements->game_flags->start_flag = false;
            game_elements->game_flags->game_over_flag = false;
            save_data("./txt-files/records.txt", game_elements->game_info);
        }
    }
    DrawTextEx(game_elements->menu->font, text, (Vector2)
    {rects[8].x + rects[8].width / 2 - textsize.x / 2, rects[8].y + rects[8].height / 2 - textsize.y / 2}, 80, 1, YELLOW);   
    if(CheckCollisionPointRec(mouse, rects[9]))
    {
        DrawRectangle(rects[9].x, rects[9].y, rects[9].width, rects[9].height, GREEN);
        if(IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            game_elements->game_flags->start_flag = true;
            game_elements->game_flags->game_over_flag = false;
            game_elements->game_flags->classic_map_flag = false;
            game_elements->game_flags->fantasy_map_flag = false;
            game_elements->game_flags->rotated_map_flag = false;
            save_data("./txt-files/records.txt", game_elements->game_info);
        }
    }
    text = "RESTART";
    textsize = MeasureTextEx(game_elements->menu->font,text, 75, 1);
    DrawTextEx(game_elements->menu->font, text, (Vector2)
    {rects[9].x + rects[9].width / 2 - textsize.x / 2, rects[9].y + rects[9].height / 2 - textsize.y / 2}, 75, 1, YELLOW);
    EndDrawing();
}
void pacman(GameElements *game_elements)
{
    game_elements->menu->time += GetFrameTime();
    game_elements->menu->star_time += GetFrameTime();

    if(game_elements->menu->star_time >= 1.5)
    {
        game_elements->menu->star_position.x = game_elements->menu->position.x + 600;
        game_elements->menu->star_position.y = game_elements->menu->position.y;
        game_elements->menu->star_time = 0;
    }
    DrawCircle(game_elements->menu->star_position.x + 80, game_elements->menu->star_position.y + 80, 20, RED);
    if(game_elements->menu->time >= 0.2)
    {
        game_elements->menu->mouth_flag = !game_elements->menu->mouth_flag;
        game_elements->menu->time = 0;
    }
    game_elements->menu->position.x += 3;
    if(game_elements->menu->position.x >= GetScreenWidth())
    {
        game_elements->menu->position.x = -game_elements->menu->pacman.width;
        game_elements->menu->position.y = rand() % GetScreenHeight();
    }
    if(game_elements->menu->position.y >= GetScreenHeight())
    {
        game_elements->menu->position.y = rand() % GetScreenHeight();
    }
    if(game_elements->menu->direction = 'r')
    {
        DrawTexture(game_elements->menu->mouth_flag ? game_elements->menu->pacman_right : game_elements->menu->pacman,
        game_elements->menu->position.x, game_elements->menu->position.y, WHITE);
    }
    DrawTexture(game_elements->menu->ghost, game_elements->menu->position.x - 400, game_elements->menu->position.y, WHITE);
}
int menu(GameElements *game_elements)
{
    Vector2 mouse_position = GetMousePosition();
    int static i = 0;
    BeginDrawing();
    pacman(game_elements);
    if(IsKeyPressed(KEY_DOWN))
        i++;
    else if(IsKeyPressed(KEY_UP))
        i--;
    i += scroll_wheel();
    ClearBackground(game_elements->setting->background[game_elements->setting->i % 3]);
    //start the menu
    Rectangle rec1 = {GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 - 650, 640, 160};
    char *text = "START";
    Vector2 text_size = MeasureTextEx(game_elements->menu->font, text, 120, 1.0f);
    if(CheckCollisionPointRec(mouse_position, rec1) || i % 5 == 0 || i % 5 + 5 == 0)
    {
        i = 0;
        DrawRectangle(GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 - 650, 640, 160, RED);
        DrawTextEx(game_elements->menu->font, text, (Vector2){GetScreenWidth() / 2 - 320 + (640 / 2 - text_size.x / 2), GetScreenHeight() / 2 - 650 + (160 / 2 - text_size.y / 2)}, 120, 1.0f, WHITE);
    }
    else
    {
        DrawRectangle(GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 - 650, 640, 160, BLUE);
        DrawTextEx(game_elements->menu->font, text, (Vector2){GetScreenWidth() / 2 - 320 + (640 / 2 - text_size.x / 2), GetScreenHeight() / 2 - 650 + (160 / 2 - text_size.y / 2)}, 120, 1.0f, WHITE);
    }
    if((CheckCollisionPointRec(mouse_position, rec1) || i % 5 == 0 || i % 5 + 5 == 0) && (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        game_elements->game_flags->start_flag = true;
        if(game_elements->game_flags->sounds_flag)
            PlaySound(game_elements->game_sounds->click);
    }
    //setting
    text = "SETTING";
    text_size = MeasureTextEx(game_elements->menu->font, text, 120, 1.0f);
    Rectangle rec2 = {GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 - 400, 640, 160};
    if(CheckCollisionPointRec(mouse_position, rec2) || i % 5 == 1 || i % 5 + 5 == 1)
    {
        i = 1;
        DrawRectangle(GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 - 400, 640, 160, RED);
        DrawTextEx(game_elements->menu->font, text, (Vector2){GetScreenWidth() / 2 - 320 + (640 / 2 - text_size.x / 2), GetScreenHeight() / 2 - 400 + (160 / 2 - text_size.y / 2)}, 120, 1.0f, WHITE);
    }
    else
    {
        DrawRectangle(GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 - 400, 640, 160, BLUE);
        DrawTextEx(game_elements->menu->font, text, (Vector2){GetScreenWidth() / 2 - 320 + (640 / 2 - text_size.x / 2), GetScreenHeight() / 2 - 400 + (160 / 2 - text_size.y / 2)}, 120, 1.0f, WHITE);
    }
    if((CheckCollisionPointRec(mouse_position, rec2) || i % 5 == 1 || i % 5 + 5 == 1) && (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        game_elements->game_flags->setting_flag = true;
        if(game_elements->game_flags->sounds_flag)
            PlaySound(game_elements->game_sounds->click);
    }
    //records
    text = "RECORDS";
    text_size = MeasureTextEx(game_elements->menu->font, text, 120, 1.0f);
    Rectangle rec3 = {GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 - 150, 640, 160};
    if(CheckCollisionPointRec(mouse_position, rec3) || i % 5 == 2 || i % 5 + 5 == 2)
    {
        i = 2;
        DrawRectangle(GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 - 150, 640, 160, RED);
        DrawTextEx(game_elements->menu->font, text, (Vector2){GetScreenWidth() / 2 - 320 + (640 / 2 - text_size.x / 2), GetScreenHeight() / 2 - 150 + (160 / 2 - text_size.y / 2)}, 120, 1.0f, WHITE);
    }
    else
    {
        DrawRectangle(GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 - 150, 640, 160, BLUE);
        DrawTextEx(game_elements->menu->font, text, (Vector2){GetScreenWidth() / 2 - 320 + (640 / 2 - text_size.x / 2), GetScreenHeight() / 2 - 150 + (160 / 2 - text_size.y / 2)}, 120, 1.0f, WHITE);
    }
    if((CheckCollisionPointRec(mouse_position, rec3) || i % 5 == 2 || i % 5 + 5 == 2) && (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        game_elements->game_flags->records_flag = true;
        if(game_elements->game_flags->sounds_flag)
            PlaySound(game_elements->game_sounds->click);
    }
    //last game
    text = "REPLAY";
    text_size = MeasureTextEx(game_elements->menu->font, text, 120, 1.0f);
    Rectangle rec4 = {GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 + 100, 640, 160};
    if(CheckCollisionPointRec(mouse_position, rec4) || i % 5 == 3 || i % 5 + 5 == 3)
    {
        i = 3;
        DrawRectangle(GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 + 100, 640, 160, RED);
        DrawTextEx(game_elements->menu->font, text, (Vector2){GetScreenWidth() / 2 - 320 + (640 / 2 - text_size.x / 2), GetScreenHeight() / 2 + 100 + (160 / 2 - text_size.y / 2)}, 120, 1.0f, WHITE);
    }
    else
    {
        DrawRectangle(GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 + 100, 640, 160, BLUE);
        DrawTextEx(game_elements->menu->font, text, (Vector2){GetScreenWidth() / 2 - 320 + (640 / 2 - text_size.x / 2), GetScreenHeight() / 2 + 100 + (160 / 2 - text_size.y / 2)}, 120, 1.0f, WHITE);
    }
    if((CheckCollisionPointRec(mouse_position, rec4) || i % 5 == 3 || i % 5 + 5 == 3) && (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {
        game_elements->game_flags->last_games_flag = true;
        if(game_elements->game_flags->sounds_flag)
            PlaySound(game_elements->game_sounds->click);
    }
    //exit
    text = "EXIT";
    text_size = MeasureTextEx(game_elements->menu->font, text, 120, 1.0f);
    Rectangle rec5 = {GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 + 350, 640, 160};
    if(CheckCollisionPointRec(mouse_position, rec5) || i % 5 == 4 || i % 5 + 5 == 4)
    {
        i = 4;
        DrawRectangle(GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 + 350, 640, 160, RED);
        DrawTextEx(game_elements->menu->font, text, (Vector2){GetScreenWidth() / 2 - 320 + (640 / 2 - text_size.x / 2), GetScreenHeight() / 2 + 350 + (160 / 2 - text_size.y / 2)}, 120, 1.0f, WHITE);
    }
    else
    {
        DrawRectangle(GetScreenWidth() / 2 - 320, GetScreenHeight() / 2 + 350, 640, 160, BLUE);
        DrawTextEx(game_elements->menu->font, text, (Vector2){GetScreenWidth() / 2 - 320 + (640 / 2 - text_size.x / 2), GetScreenHeight() / 2 + 350 + (160 / 2 - text_size.y / 2)}, 120, 1.0f, WHITE);
    }
    if((CheckCollisionPointRec(mouse_position, rec4) || i % 5 == 4 || i % 5 + 5 == 4) && (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)))
    {    
        if(game_elements->game_flags->sounds_flag)
            PlaySound(game_elements->game_sounds->click);
        game_elements->game_flags->exit_flag = true;
    }
    EndDrawing();
}

#endif
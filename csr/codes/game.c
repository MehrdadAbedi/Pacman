#ifndef GAME_H
#define GAME_H

#include "ghosts.h"
#include "window.h"
#include "fruits.h"
#include "menu.h"
#include "pacman.h"

void star(GameElements *game_elements, int number)
{
    int m = rand() % game_elements->board_size->cols, n = rand() % game_elements->board_size->rows;
    for(int i = 0; i < number; i++)
    {
        while (game_elements->Board[n][m] != 0)
        {
            m = rand() % game_elements->board_size->cols;
            n = rand() % game_elements->board_size->rows;
        }
        game_elements->Board[n][m] = 2;
    }
}
int count_star(GameElements *game_elements, int number)
{
    int sum = 0;
    for(int i = 0; i < game_elements->board_size->rows; i++)
    {
        for(int j = 0; j < game_elements->board_size->cols; j++)
        {
            if(game_elements->Board[i][j] == 2)
                sum++;
        }
    }
    return number - sum;
}
int clean_stars(GameElements *game_elements)
{
    for(int i = 0; i < game_elements->board_size->rows; i++)
    {
        for(int j = 0; j < game_elements->board_size->cols; j++)
        {
            if(game_elements->Board[i][j] == 2)
                game_elements->Board[i][j] = 0;
        }
    }
}
void vis_health(GameElements *game_elements)
{
    for(int i = 0; i < game_elements->pacman->health; i++)
    {
        DrawTexture(game_elements->pacman->heart, i * 80 + game_elements->zero_point->x - game_elements->BlockSize, -120 + game_elements->zero_point->y, WHITE);
    }
    if(game_elements->pacman->health == 5)
    {
        DrawTextEx(game_elements->menu->font, "FULL!", (Vector2) {(game_elements->pacman->health) * 80 + game_elements->zero_point->x - 20, -120 + game_elements->zero_point->y + 10}, 60, 1, YELLOW);
    }
}
void draw_screen(GameElements *game_elements)
{
    ClearBackground(game_elements->setting->background[game_elements->setting->i % 3]);
    game_elements->game_info->time += GetFrameTime();
    game_elements->game_info->minutes = (int) game_elements->game_info->time / 60;
    game_elements->game_info->seconds = (int) game_elements->game_info->time % 60;
    game_elements->game_info->game_scores = count_star(game_elements, stars) + scores;

    if(game_elements->game_flags->fantasy_map_flag)
        show_map2(game_elements);
    else if(game_elements->game_flags->classic_map_flag)
        show_map1(game_elements);
    else if(game_elements->game_flags->rotated_map_flag)
        show_map3(game_elements);

    DrawTextEx(game_elements->menu->font, TextFormat("Time: %2.d:%2.d", game_elements->game_info->minutes, game_elements->game_info->seconds),
    (Vector2) {game_elements->zero_point->x - 500, game_elements->zero_point->y}, 50, 1, WHITE);
    DrawTextEx(game_elements->menu->font, TextFormat("Scores: %d", game_elements->game_info->game_scores),
    (Vector2) {game_elements->zero_point->x - 500, game_elements->zero_point->y + 100}, 50, 1, WHITE);
    DrawTextEx(game_elements->menu->font, TextFormat("Speed: %d", game_elements->pacman->speed),
    (Vector2) {game_elements->zero_point->x - 500, game_elements->zero_point->y + 200}, 50, 1, WHITE);    

    if(game_elements->game_flags->rotated_map_flag)
    {
        teleport(game_elements);
    }
    apple(game_elements);
    mushroom(game_elements);
    pepper_handling(game_elements);

    if(game_elements->game_flags->easy_flag)
    {
        ghost_move(game_elements, game_elements->ghosts->pink_ghost);
        ghost_move(game_elements, game_elements->ghosts->red_ghost);
        ghost_move(game_elements, game_elements->ghosts->blue_ghost);
        ghost_move(game_elements, game_elements->ghosts->green_ghost);
    }
    else if(game_elements->game_flags->medium_flag)
    {
        ghost_move(game_elements, game_elements->ghosts->pink_ghost);
        ghost_move(game_elements, game_elements->ghosts->red_ghost);
        ghost_move(game_elements, game_elements->ghosts->blue_ghost);
        ghost_move(game_elements, game_elements->ghosts->green_ghost); 
        ghost_move(game_elements, game_elements->ghosts->yellow_ghost);  
        chase_pacman(game_elements->ghosts->fire_red_ghost, game_elements);     
    }
    else if(game_elements->game_flags->hard_flag)
    {
        ghost_move(game_elements, game_elements->ghosts->pink_ghost);
        ghost_move(game_elements, game_elements->ghosts->red_ghost);
        ghost_move(game_elements, game_elements->ghosts->blue_ghost);
        ghost_move(game_elements, game_elements->ghosts->green_ghost); 
        ghost_move(game_elements, game_elements->ghosts->yellow_ghost);  
        ghost_move(game_elements, game_elements->ghosts->brown_ghost);  
        chase_pacman(game_elements->ghosts->fire_red_ghost, game_elements); 
        chase_pacman(game_elements->ghosts->fire_blue_ghost, game_elements); 
    }

    vis_health(game_elements);
    if(game_elements->timer->time_direction >= 0.4)
        game_elements->timer->time_direction = 0;
    cherry_handling(game_elements);
}
void update(GameElements *game_elements)
{
    //pacman mouth and fruits
    game_elements->timer->time_mouth += GetFrameTime();
    game_elements->timer->time_direction += GetFrameTime();
    game_elements->fruits->Pepper->time += GetFrameTime();
    game_elements->fruits->Cherry->time += GetFrameTime();
    game_elements->fruits->Apple->time += GetFrameTime();
    game_elements->fruits->Mushroom->time += GetFrameTime();
    game_elements->pacman->time += GetFrameTime();

    game_elements->border->time += GetFrameTime();

    //ghosts
    game_elements->ghosts->pink_ghost->time += GetFrameTime();
    game_elements->ghosts->blue_ghost->time += GetFrameTime();
    game_elements->ghosts->red_ghost->time += GetFrameTime();
    game_elements->ghosts->green_ghost->time += GetFrameTime();

    if(game_elements->game_flags->hard_flag || game_elements->game_flags->medium_flag)
    {
        game_elements->ghosts->fire_red_ghost->time += GetFrameTime();
        game_elements->ghosts->yellow_ghost->time += GetFrameTime();
        
        if(game_elements->game_flags->hard_flag)
        {
            game_elements->ghosts->fire_blue_ghost->time += GetFrameTime();
            game_elements->ghosts->brown_ghost->time += GetFrameTime();
        }
    }

    if(game_elements->timer->time_mouth >= 0.3)
    {
        game_elements->timer->time_flag_mouth = !game_elements->timer->time_flag_mouth;
        game_elements->timer->time_mouth = 0;
    }
}
void init_game(GameElements *game_elements)
{
    if(game_elements->game_flags->fantasy_map_flag || game_elements->game_flags->rotated_map_flag)
    {
        game_elements->board_size->rows = 30;
        game_elements->board_size->cols = 30;
    }
    else if(game_elements->game_flags->classic_map_flag)
    {
        game_elements->board_size->rows = 35;
        game_elements->board_size->cols = 35;        
    }


    initializeBoard(game_elements);

    if(game_elements->game_flags->fantasy_map_flag)
    {
        get_map("../txt-files/fantasy_map.txt", game_elements);    
    }
    else if(game_elements->game_flags->classic_map_flag)
    {
        get_map("../txt-files/classic_map.txt", game_elements);
    }
    else if(game_elements->game_flags->rotated_map_flag)
    {
        get_map("../txt-files/green_map.txt", game_elements);
    }
    init_ghosts_map(game_elements->ghosts, game_elements);   
    pacman_location(game_elements);
    game_elements->pacman->direction = game_elements->board_size->cols / 2 <= game_elements->pacman->i ? 'l' : 'r';
    game_elements->pacman->speed = 250;
    game_elements->fruits->Pepper->ability_flag = false;
    game_elements->fruits->Pepper->exist_flag = true;
    game_elements->fruits->Cherry->ability_flag = false;
    game_elements->fruits->Cherry->exist_flag = true;
    game_elements->fruits->Apple->exist_flag = true;
    game_elements->fruits->Mushroom->exist_flag = true;
    game_elements->fruits->Apple->time = 0;
    game_elements->fruits->Mushroom->time = 0;
    game_elements->fruits->Cherry->time = 0;
    game_elements->fruits->Pepper->time = 0;
    init_fruit(game_elements->fruits->Apple, game_elements);
    init_fruit(game_elements->fruits->Mushroom, game_elements);
    init_fruit(game_elements->fruits->Pepper, game_elements);
    init_fruit(game_elements->fruits->Cherry, game_elements);                    
    clean_stars(game_elements);
    scores = 0;
    memset(game_elements->game_info, 0, sizeof(GameInfo));
    star(game_elements, stars);
    game_elements->pacman->health = HEALTH;
    game_elements->game_flags->load_game_flag = false;
    //initialize
    game_elements->pacman->flash_flag = true;
    game_elements->pacman->time = 0;
    game_elements->pacman->exist_flag = true;
    game_elements->pacman->blink_flag = false;
    if(game_elements->game_flags->easy_flag)
        game_elements->ghosts->ghost_speed = 125;
    else if(game_elements->game_flags->medium_flag)
        game_elements->ghosts->ghost_speed = 150;
    else if(game_elements->game_flags->hard_flag)
        game_elements->ghosts->ghost_speed = 175;
    game_elements->pacman->last_direction = '\0';
    game_elements->pacman->direction = '\0';
    game_elements->pacman->flash_position.x = game_elements->pacman->i + game_elements->zero_point->x - 20;
    game_elements->pacman->flash_position.y = game_elements->pacman->j + game_elements->zero_point->y - 200;
}
int start_game(GameElements *game_elements)
{
    Vector2 mouse = GetMousePosition();
    if(!game_elements->game_flags->pause_flag)
    {
        BeginDrawing();
        if(count_health(game_elements) <= 0)
        {
            if(game_elements->game_flags->sounds_flag)
                PlaySound(game_elements->game_sounds->game_over);
            game_elements->game_flags->game_over_flag = true;
        }
        update(game_elements);
        if(count_star(game_elements, stars) == stars)
        {
            star(game_elements, stars);
            scores += stars;
        }
        draw_screen(game_elements);
        pacman_move(game_elements);
        DrawTexture(game_elements->menu->back, 100, GetScreenHeight() - 200, WHITE);
        if(CheckCollisionPointRec(mouse, (Rectangle) {100, GetScreenHeight() - 200, game_elements->menu->back.width, game_elements->menu->back.height}) && (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_ENTER)))
        {
            if(game_elements->game_flags->sounds_flag)
                PlaySound(game_elements->game_sounds->click);
            game_elements->game_flags->pause_flag = true;
        }
        EndDrawing();
    }
    else
    {
        BeginDrawing();
        DrawRectangle(GetScreenWidth() / 2 - 510, GetScreenHeight() / 2 - 210, 1020, 420, BLACK);
        DrawRectangle(GetScreenWidth() / 2 - 500, GetScreenHeight() / 2 - 200, 1000, 400, (Color) {3, 56, 244, 255});
        DrawRectangle(GetScreenWidth() / 2 - 500 + 50 - 5, (GetScreenHeight() / 2 - 200) + 230 - 5, 435, 130, BLACK);        
        DrawRectangle(GetScreenWidth() / 2 - 500 + 520, (GetScreenHeight() / 2 - 200) + 225, 435, 130, BLACK);        
        DrawRectangle(GetScreenWidth() / 2 - 500 + 50, (GetScreenHeight() / 2 - 200) + 230, 425, 120, (Color) {12, 164, 126, 255});
        if(CheckCollisionPointRec((mouse), (Rectangle) {GetScreenWidth() / 2 - 500 + 50, (GetScreenHeight() / 2 - 200) + 230, 425, 120}))
        {
            DrawRectangle(GetScreenWidth() / 2 - 500 + 50, (GetScreenHeight() / 2 - 200) + 230, 425, 120, (Color) {5, 224, 217, 255});
            if(IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                if(game_elements->game_flags->sounds_flag)
                    PlaySound(game_elements->game_sounds->click);
                game_elements->game_flags->pause_flag = false;
                game_elements->pacman->health = 0;
            }            
        }
        DrawRectangle(GetScreenWidth() / 2 - 500 + 525, (GetScreenHeight() / 2 - 200) + 230, 425, 120, (Color) {12, 164, 126, 255});      
        if(CheckCollisionPointRec((mouse), (Rectangle) {GetScreenWidth() / 2 - 500 + 525, (GetScreenHeight() / 2 - 200) + 230, 425, 120}))
        {
            DrawRectangle(GetScreenWidth() / 2 - 500 + 525, (GetScreenHeight() / 2 - 200) + 230, 425, 120, (Color) {5, 224, 217, 255});            
            if(IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                if(game_elements->game_flags->sounds_flag)
                    PlaySound(game_elements->game_sounds->click);                
                game_elements->game_flags->pause_flag = false;
            }        
        }  
        char *text = "Are you sure you want\nto quit the game?";
        Vector2 textsize = MeasureTextEx(game_elements->menu->font, text, 60, 0);
        DrawTextEx(game_elements->menu->font, text, (Vector2) {GetScreenWidth() / 2 - 500 + 50, GetScreenHeight() / 2 - 200 + 50}, 60, 0, YELLOW);
        text = "yes!";
        textsize = MeasureTextEx(game_elements->menu->font, text, 100, 1);
        DrawTextEx(game_elements->menu->font, text, (Vector2) {GetScreenWidth() / 2 - 500 + 50 + (425 / 2 - textsize.x / 2), (GetScreenHeight() / 2 - 200 + 10) + 230}, 100, 1, YELLOW);
        text = "no!";
        textsize = MeasureTextEx(game_elements->menu->font, text, 100, 1);
        DrawTextEx(game_elements->menu->font, text, (Vector2) {GetScreenWidth() / 2 - 500 + 525 + (425 / 2 - textsize.x / 2), (GetScreenHeight() / 2 - 200 + 10) + 230}, 100, 1, YELLOW);
        EndDrawing();
    }

}
void choose_map(GameElements *game_elements, Texture classic_mode, Texture fantasy_mode, Texture rotated_mode)
{
    Vector2 mouse = GetMousePosition();
    BeginDrawing();
    ClearBackground(game_elements->setting->background[game_elements->setting->i % 3]);
    DrawTexture(game_elements->menu->back, 100, GetScreenHeight() - 200, WHITE);
    if(CheckCollisionPointRec(mouse, (Rectangle) {100, GetScreenHeight() - 200, game_elements->menu->back.width, game_elements->menu->back.height}) && (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_ENTER)))
        game_elements->game_flags->start_flag = false;
    if(CheckCollisionPointRec(mouse, (Rectangle) {GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - classic_mode.height / 2 - 210, 820, 820}))
    {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ENTER))
        {
            if(game_elements->game_flags->sounds_flag)
            {
                PlaySound(game_elements->game_sounds->click);
            }
            game_elements->game_flags->classic_map_flag = true;
            game_elements->game_flags->load_game_flag = true;
            init_game(game_elements);
        }
        DrawRectangle(GetScreenWidth() / 2 - 410, GetScreenHeight() / 2 - classic_mode.height / 2 - 210, 820, 820, RED);
    }
    if(CheckCollisionPointRec(mouse, (Rectangle) {GetScreenWidth() / 2 + 590, GetScreenHeight() / 2 - fantasy_mode.height / 2 - 210, 820, 820}))
    {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ENTER))
        {
            if(game_elements->game_flags->sounds_flag)
            {
                PlaySound(game_elements->game_sounds->click);
            }            
            game_elements->game_flags->fantasy_map_flag = true;
            game_elements->game_flags->load_game_flag = true;
            init_game(game_elements);
        }            
        DrawRectangle(GetScreenWidth() / 2 + 590, GetScreenHeight() / 2 - fantasy_mode.height / 2 - 210, 820, 820, RED);
    }
    if(CheckCollisionPointRec(mouse, (Rectangle) {GetScreenWidth() / 2 - 1410, GetScreenHeight() / 2 - fantasy_mode.height / 2 - 210, 820, 820}))
    {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ENTER))
        {
            if(game_elements->game_flags->sounds_flag)
            {
                PlaySound(game_elements->game_sounds->click);
            }
            game_elements->game_flags->rotated_map_flag = true;
            game_elements->game_flags->load_game_flag = true;
            init_game(game_elements);
        }
        DrawRectangle(GetScreenWidth() / 2 - 1410, GetScreenHeight() / 2 - fantasy_mode.height / 2 - 210, 820, 820, RED);
    }
    char *text = "CLASSIC MAP";
    Vector2 textsize = MeasureTextEx(game_elements->menu->font, text, 100, 1);
    DrawTexture(classic_mode, GetScreenWidth() / 2 - 400, GetScreenHeight() / 2 - classic_mode.height / 2 - 200, WHITE);
    DrawTexture(fantasy_mode, GetScreenWidth() / 2 + 600, GetScreenHeight() / 2 - fantasy_mode.height / 2 - 200, WHITE);
    DrawTexture(rotated_mode, GetScreenWidth() / 2 - 1400, GetScreenHeight() / 2 - rotated_mode.height / 2 - 200, WHITE);
    DrawTextEx(game_elements->menu->font, text, (Vector2) {GetScreenWidth() / 2 - 400 + 400 - textsize.x / 2, GetScreenHeight() / 2 + classic_mode.height / 2 + 40 - 200}, 100, 1, WHITE);
    text = "FANTASY MAP";
    textsize = MeasureTextEx(game_elements->menu->font, text, 100, 1);
    DrawTextEx(game_elements->menu->font, text, (Vector2) {GetScreenWidth() / 2 + 600 + 400 - textsize.x / 2, GetScreenHeight() / 2 + classic_mode.height / 2 + 40 - 200}, 100, 1, WHITE);
    text = "GREEN MAP";
    textsize = MeasureTextEx(game_elements->menu->font, text, 100, 1);
    DrawTextEx(game_elements->menu->font, text, (Vector2) {GetScreenWidth() / 2 - 1400 + 400 - textsize.x / 2, GetScreenHeight() / 2 + rotated_mode.height / 2 + 40 - 200}, 100, 1, WHITE);
    EndDrawing();
}
void game()
{
    InitAudioDevice();
    SetRandomSeed(6);

    Vector2 zero_point;  
    Window window = {
        LoadImage("../images/icon.png"),
        3200,
        1900,
        FLAG_WINDOW_RESIZABLE,
        "PACMAN GAME",
    };
    Border border;
    Pacman pacman;
    Sounds game_sounds;
    Records records;
    GameInfo game_info;
    GameFlags game_flags = {false, false, false, false, false, false, false, false, false, false, false,
    true, true, false, false, true, false, true, false};
    
    Ghosts ghosts;
    ghosts.blue_ghost = (Ghost *)malloc(sizeof(Ghost));
    ghosts.red_ghost = (Ghost *)malloc(sizeof(Ghost));
    ghosts.brown_ghost = (Ghost *)malloc(sizeof(Ghost));
    ghosts.green_ghost = (Ghost *)malloc(sizeof(Ghost));
    ghosts.pink_ghost = (Ghost *)malloc(sizeof(Ghost));
    ghosts.yellow_ghost = (Ghost *)malloc(sizeof(Ghost));
    ghosts.fire_red_ghost = (Ghost *) malloc(sizeof(Ghost));
    ghosts.fire_blue_ghost = (Ghost *) malloc(sizeof(Ghost));

    Fruits fruits; 
    fruits.Apple = (Fruit *) malloc(sizeof(Fruit));
    fruits.Mushroom = (Fruit *) malloc(sizeof(Fruit));
    fruits.Pepper = (Fruit *) malloc(sizeof(Fruit));
    fruits.Cherry = (Fruit *) malloc(sizeof(Fruit));

    Setting setting;
    Menu menu1;
    Timer timer = {
        0,
        false,
        0,
    };

    BoardSize board_size;
    int **board = NULL;

    char player[20];
    player[0] = '\0';


    GameElements game_elements = {
        &fruits,
        &timer,
        &ghosts,
        &pacman,
        &border,
        &window,
        &zero_point,
        &game_flags,
        &game_sounds,
        &game_info,
        &records,
        &setting,
        &menu1,
        &board_size,
        player,
        board,
        0,
        50
    };


    create_window(&window);

    init_menu(&game_elements);

    //flags for loading resources
    game_elements.records->record_bar.id = 0;
    setting.window.id = 0;
    game_elements.pacman->flash_move = 80;

    border.time = 0;
    game_elements.menu->font = LoadFont("../joystix-monospace.ttf");
    load_sounds(&game_elements);

    game_elements.border->I = 0;
    Texture fantasy_mode = LoadTexture("../images/fantasy_map.png");
    Texture classic_mode = LoadTexture("../images/classic_map.png");
    Texture rotated_mode = LoadTexture("../images/rotated_map.png");
    
    border.tranparent_layer = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
    PlayMusicStream(game_sounds.game_music);

    SetTargetFPS(120);

    while(!WindowShouldClose())
    {
        if(game_elements.game_flags->music_flag)
            UpdateMusicStream(game_sounds.game_music);
        
        
        if(game_flags.fantasy_map_flag || game_flags.game_over_flag || game_flags.rotated_map_flag)
        {
            zero_point.x = GetScreenWidth() / 2 - game_elements.board_size->rows * game_elements.BlockSize / 2;
            zero_point.y = GetScreenHeight() / 2 - game_elements.board_size->rows * game_elements.BlockSize / 2;            
        }
        else if(game_flags.classic_map_flag)
        {
            zero_point.x = GetScreenWidth() / 2 - game_elements.board_size->rows * game_elements.BlockSize / 2;
            zero_point.y = GetScreenHeight() / 2 - game_elements.board_size->rows * game_elements.BlockSize / 2;            
        }
        else
        {
            zero_point.x = GetScreenWidth() / 2 - 1300;
            zero_point.y = GetScreenHeight() / 2 - 800;
        }

        if(game_flags.window_name_flag)
        {
            name_window(&game_elements);
        }
        else
        {
            if(!(game_flags.exit_flag || game_flags.last_games_flag || game_flags.records_flag || game_flags.setting_flag || game_flags.start_flag))
                menu(&game_elements);     
            else if(game_flags.start_flag)
            {
                if(!game_flags.classic_map_flag && !game_flags.fantasy_map_flag && !game_flags.rotated_map_flag)
                    choose_map(&game_elements, classic_mode, fantasy_mode, rotated_mode);
                if(game_flags.fantasy_map_flag || game_flags.classic_map_flag || game_flags.rotated_map_flag)
                {
                    if(!game_flags.game_over_flag)
                    {
                        if(game_elements.pacman->flash_move == 80)
                        {
                            load_game(&game_elements);
                        }
                        start_game(&game_elements);
                    }
                    else
                    {
                        game_over_screen(&game_elements);
                    }
                }
            }
            else if(game_flags.records_flag)
            {
                if(game_elements.records->record_bar.id == 0)
                    load_records(&game_elements);
                vis_records("../txt-files/records.txt", &game_elements);
                Rectangle rec_back = {100, GetScreenHeight() - 200, 100, 100};
                Vector2 mouse = GetMousePosition();
                if(CheckCollisionPointRec(mouse, rec_back) && (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_ENTER)))
                    game_flags.records_flag = false;
            }
            else if(game_flags.setting_flag)
            {
                if(setting.window.id == 0)
                {
                    load_setting(&game_elements);
                }
                setting_window(&game_elements);
            }
            else if(game_flags.exit_flag)
                break;
        }
    }
    UnloadFont(game_elements.menu->font);
    unload_sounds(&game_elements);
    UnloadMusicStream(game_sounds.game_music);
    unload_setting(&game_elements);
    unload_game1(&game_elements);
    unload_records(&game_elements);
    free(fruits.Apple); free(fruits.Mushroom);
    free(fruits.Cherry); free(fruits.Pepper);
    free(ghosts.blue_ghost); free(ghosts.red_ghost);
    free(ghosts.brown_ghost); free(ghosts.green_ghost);
    free(ghosts.pink_ghost); free(ghosts.yellow_ghost); 
    free(ghosts.fire_red_ghost); free(ghosts.fire_blue_ghost);
    UnloadImage(window.icon);
    freeBoard(&game_elements);
    CloseWindow();
}

#endif
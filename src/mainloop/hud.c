/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** hud.c
*/

#include "../../include/wolf3d.h"

void print_score(void)
{
    hud_t **hud = get_hud();
    sfRenderWindow **window = get_window();
    char score_str[32];
    sfVector2f score_pos = {50, 0};

    if (!hud || !(*hud) || !(*hud)->score_text)
        return;
    snprintf(score_str, sizeof(score_str), "Score: %d", (*hud)->score);
    sfText_setString((*hud)->score_text, score_str);
    sfText_setPosition((*hud)->score_text, score_pos);
    (*hud)->score_shadow = sfText_copy((*hud)->score_text);
    sfText_setPosition((*hud)->score_shadow,
        (sfVector2f){score_pos.x + 4, score_pos.y + 4});
    sfText_setColor((*hud)->score_shadow, sfColor_fromRGBA(0, 0, 0, 200));
    sfRenderWindow_drawText((*window), (*hud)->score_shadow, NULL);
    sfRenderWindow_drawText((*window), (*hud)->score_text, NULL);
    sfText_destroy((*hud)->score_shadow);
}

void print_time_shadow(sfVector2f time_pos)
{
    hud_t **hud = get_hud();
    sfRenderWindow **window = get_window();

    if (!hud || !(*hud) || !(*hud)->time_txt)
        return;
    (*hud)->time_shadow = sfText_copy((*hud)->time_txt);
    sfText_setPosition((*hud)->time_shadow, (sfVector2f){time_pos.x + 4,
        time_pos.y + 4});
    sfText_setColor((*hud)->time_shadow, sfColor_fromRGBA(0, 0, 0, 200));
    sfRenderWindow_drawText((*window), (*hud)->time_shadow, NULL);
    sfText_destroy((*hud)->time_shadow);
}

void handle_hud(void)
{
    hud_t **hud = get_hud();
    clocks_t **clock = get_clock();
    sfRenderWindow **window = get_window();
    main_screen_t **main_screen = get_main_screen();
    float seconds;
    int minutes = 0;
    int sec_disp;
    char time_str[16];
    sfVector2f time_pos = {(WIN_WIDTH((*window)) / 2), 50};

    (*hud)->time_survived = sfClock_getElapsedTime((*clock)->main_loop);
    seconds = sfTime_asSeconds((*hud)->time_survived);
    minutes = (int)seconds / 60;
    sec_disp = (int)seconds % 60;
    snprintf(time_str, sizeof(time_str), "%02d:%02d", minutes, sec_disp);
    set_text(&(*hud)->time_txt, (*main_screen)->font, time_str, time_pos);
    print_time_shadow(time_pos);
}

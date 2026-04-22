/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** free_gameloop
*/

#include "../../include/wolf3d.h"

void free_hud(void)
{
    hud_t **hud = get_hud();

    if (!hud || !(*hud))
        return;
    if ((*hud)->score_text)
        sfText_destroy((*hud)->score_text);
    if ((*hud)->time_txt)
        sfText_destroy((*hud)->time_txt);
    if ((*hud)->overlay.sprite)
        sfSprite_destroy((*hud)->overlay.sprite);
    if ((*hud)->dim_effect)
        sfRectangleShape_destroy((*hud)->dim_effect);
    free(*hud);
    *hud = NULL;
}

void free_clocks(void)
{
    clocks_t **clock = get_clock();

    if ((*clock)->main_menu)
        sfClock_destroy((*clock)->main_menu);
    if ((*clock)->main_loop)
        sfClock_destroy((*clock)->main_loop);
    if ((*clock)->end_game)
        sfClock_destroy((*clock)->end_game);
    if ((*clock)->weapon_anim_clock)
        sfClock_destroy((*clock)->weapon_anim_clock);
    free_hud();
}

void free_all(sfRenderWindow **window,
    sfVertexArray *ceiling, sfVertexArray *floor)
{
    if (*window) {
        sfRenderWindow_destroy(*window);
        *window = NULL;
    }
    if (ceiling)
        sfVertexArray_destroy(ceiling);
    if (floor)
        sfVertexArray_destroy(floor);
}

void free_game_resources(void)
{
    sfRenderWindow **window = get_window();
    sfVertexArray *ceiling = get_ceiling();
    sfVertexArray *floor = get_floor();
    player_t **player = get_player();

    free_all(window, ceiling, floor);
    if (*player) {
        sfRectangleShape_destroy((*player)->line);
        sfCircleShape_destroy((*player)->circle);
        if ((*player)->flashlight_effect) {
            sfCircleShape_destroy((*player)->flashlight_effect);
        }
        free(*player);
        *player = NULL;
    }
    free_clocks();
}

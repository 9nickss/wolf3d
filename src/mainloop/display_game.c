/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** display_mainloop
*/

#include "../../include/wolf3d.h"

void draw_hud(void)
{
    hud_t **hud = get_hud();
    sfRenderWindow *window = *get_window();

    handle_hud();
    sfRenderWindow_drawRectangleShape(window, (*hud)->dim_effect, NULL);
    print_score();
    sfRenderWindow_drawText(window, (*hud)->time_txt, NULL);
    sfRenderWindow_drawSprite(window, (*hud)->overlay.sprite, NULL);
}

void draw_mainloop(void)
{
    update_dash_effects();
    update_particles();
    cast_all_rays();
    draw_dash_flash();
    draw_particles();
    draw_weapon();
    draw_hud();
    draw_2d_map();
    draw_player_direction();
    draw_player();
    draw_flashlight();
}

void draw_end_game(void)
{
    return;
}

void draw_game(void)
{
    void (*draw_state[NB_STATE])(void) = {draw_main_screen,
        draw_main_menu, draw_mainloop, draw_end_game};
    state_t *state = get_state();

    draw_state[*state]();
}

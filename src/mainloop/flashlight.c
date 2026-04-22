/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** flashlight.c
*/

#include "../../include/wolf3d.h"

void toggle_flashlight(void)
{
    static bool key_pressed = false;
    player_t *player = *get_player();

    if (sfKeyboard_isKeyPressed(sfKeyF)) {
        if (!key_pressed) {
            player->flashlight_on = !player->flashlight_on;
            key_pressed = true;
        }
    } else {
        key_pressed = false;
    }
}

void draw_flashlight(void)
{
    sfRenderWindow *window = *get_window();
    player_t *player = *get_player();
    sfRenderStates states = {sfBlendAdd, sfTransform_Identity, NULL, NULL};

    if (player->has_flashlight && player->flashlight_on)
        sfRenderWindow_drawCircleShape(window,
            player->flashlight_effect, &states);
}

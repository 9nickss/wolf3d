/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** gameloop
*/

#include "../../include/wolf3d.h"

int gameloop(void)
{
    bool *in_settings = false;

    if (init_all_struct() == 84)
        return 84;
    while (sfRenderWindow_isOpen(*get_window())) {
        sfRenderWindow_clear(*get_window(), sfBlack);
        in_settings = get_in_settings();
        if (*in_settings) {
            settings_event();
            display_settings();
        } else {
            analyse_events();
            draw_game();
        }
        sfRenderWindow_display(*get_window());
    }
    free_main_menu();
    free_game_resources();
    free_settings_resources();
    return 0;
}

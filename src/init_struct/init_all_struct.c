/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_all_struct
*/

#include "../../include/wolf3d.h"

int init_all_settings(void)
{
    init_keybinds();
    if (init_settings() == 84)
        return 84;
    if (init_state() == 84)
        return 84;
    if (init_main_menu() == 84)
        return 84;
    return 0;
}

int init_all_struct(void)
{
    if (init_window() == 84)
        return 84;
    if (init_main_screen() == 84)
        return 84;
    if (init_player() == 84)
        return 84;
    if (init_weapon() == 84)
        return 84;
    if (init_clock() == 84)
        return 84;
    if (init_hud() == 84)
        return 84;
    if (init_all_settings() == 84)
        return 84;
    if (init_map() == 84)
        return 84;
    return 0;
}

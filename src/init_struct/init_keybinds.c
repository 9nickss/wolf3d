/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_keybinds
*/

#include "../../include/wolf3d.h"

keybinds_t *get_keybinds(void)
{
    static keybinds_t keybinds = {0};

    return &keybinds;
}

int init_keybinds(void)
{
    keybinds_t *keybinds = get_keybinds();

    (*keybinds).move_forward = sfKeyZ;
    (*keybinds).move_backward = sfKeyS;
    (*keybinds).move_left = sfKeyQ;
    (*keybinds).move_right = sfKeyD;
    (*keybinds).rotate_left = sfKeyLeft;
    (*keybinds).rotate_right = sfKeyRight;
    return 0;
}

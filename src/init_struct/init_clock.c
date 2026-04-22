/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_clock
*/

#include "../../include/wolf3d.h"

clocks_t **get_clock(void)
{
    static clocks_t *clock = NULL;

    return &clock;
}

static int more_clocks_init(void)
{
    clocks_t **clock = get_clock();

    (*clock)->walk_clock = sfClock_create();
    if (!(*clock)->walk_clock)
        return 84;
    (*clock)->dash_clock = sfClock_create();
    if (!(*clock)->dash_clock)
        return 84;
    return 0;
}

int init_clock(void)
{
    clocks_t **clock = get_clock();

    (*clock) = malloc(sizeof(clocks_t));
    if (!(*clock))
        return 84;
    (*clock)->main_menu = sfClock_create();
    if (!(*clock)->main_menu)
        return 84;
    (*clock)->main_loop = sfClock_create();
    if (!(*clock)->main_loop)
        return 84;
    (*clock)->end_game = sfClock_create();
    if (!(*clock)->end_game)
        return 84;
    (*clock)->weapon_anim_clock = sfClock_create();
    if (!(*clock)->weapon_anim_clock)
        return 84;
    if (more_clocks_init() == 84)
        return 84;
    return 0;
}

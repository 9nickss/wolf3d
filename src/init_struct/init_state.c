/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_state
*/

#include "../../include/wolf3d.h"

state_t *get_state(void)
{
    static state_t state = {0};

    return &state;
}

bool *get_in_settings(void)
{
    static bool in_settings = false;

    return &in_settings;
}

int init_state(void)
{
    state_t *state = get_state();

    *state = MAIN_SCREEN;
    return 0;
}

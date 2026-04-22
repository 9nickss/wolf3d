/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** event_main_menu
*/

#include "../../include/wolf3d.h"

void new_game(void)
{
    state_t *state = get_state();
    clocks_t **clock = get_clock();

    *state = MAIN_LOOP;
    sfClock_restart((*clock)->main_loop);
    play_background_music();
}

void load_game(void)
{
    return;
}

void settings(void)
{
    bool *in_settings = get_in_settings();

    *in_settings = true;
}

void quit(void)
{
    sfRenderWindow *window = *get_window();

    sfRenderWindow_close(window);
}

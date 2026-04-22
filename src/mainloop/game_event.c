/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** game_event
*/

#include "../../include/wolf3d.h"

void main_screen_event(sfRenderWindow *window, sfEvent event)
{
    clocks_t *clock = *get_clock();
    state_t *state = get_state();

    while (sfRenderWindow_pollEvent(window, &event)) {
        close_window(window, event);
        full_screen_window(window, event);
        if (event.type == sfEvtKeyPressed ||
            event.type == sfEvtMouseButtonPressed) {
            *state = MAIN_MENU;
            sfClock_restart(clock->main_menu);
        }
    }
}

void mouse_menu(sfEvent event)
{
    if (event.type == sfEvtMouseMoved ||
        event.type == sfEvtMouseButtonPressed) {
        valid_label_mouse();
        arrows_mouse_menu();
    }
    if (event.type == sfEvtKeyPressed) {
        valid_label_key();
        arrows_key_menu();
    }
}

void main_menu_event(sfRenderWindow *window, sfEvent event)
{
    clocks_t *clock = *get_clock();

    while (sfRenderWindow_pollEvent(window, &event)) {
        close_window(window, event);
        full_screen_window(window, event);
        if (sfClock_getElapsedTime(clock->main_menu).microseconds > 1000) {
            mouse_menu(event);
            sfClock_restart(clock->main_menu);
        }
    }
}

void mainloop_event(sfRenderWindow *window, sfEvent event)
{
    keybinds_t keybinds = *get_keybinds();
    state_t *state = get_state();

    while (sfRenderWindow_pollEvent(window, &event)) {
        close_window(window, event);
        full_screen_window(window, event);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            *state = MAIN_MENU;
    }
    move_player(keybinds);
}

void analyse_events(void)
{
    void (*event_state[NB_STATE])(sfRenderWindow *, sfEvent) =
        {main_screen_event, main_menu_event, mainloop_event};
    sfRenderWindow *window = *get_window();
    state_t *state = get_state();
    sfEvent event;

    event_state[*state](window, event);
}

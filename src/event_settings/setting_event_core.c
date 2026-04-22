/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** setting_event_core
*/

#include "../../include/wolf3d.h"

void handle_event_by_type(settings_page_t *settings, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(settings->window);
        return;
    }
    if (event.type == sfEvtKeyPressed) {
        handle_key_press(settings, event);
    }
}

void handle_escape_key(settings_page_t *settings)
{
    bool *in_settings = get_in_settings();

    *in_settings = false;
    if (settings->tab_change_sound) {
        sfSound_play(settings->tab_change_sound);
    }
}

void handle_key_press(settings_page_t *settings, sfEvent event)
{
    if (event.key.code == sfKeyEscape) {
        handle_escape_key(settings);
        return;
    }
    if (event.key.code == sfKeyLeft || event.key.code == sfKeyRight) {
        handle_left_right_keys(settings, event);
        return;
    }
    if (event.key.code == sfKeyUp || event.key.code == sfKeyDown) {
        handle_up_down_keys(settings, event);
        return;
    }
    handle_settings_input(settings->current_page, event);
}

void settings_event(void)
{
    sfRenderWindow *window = *get_window();
    settings_page_t *settings = *get_settings_page();
    sfEvent event;

    if (!settings)
        return;
    settings->window = window;
    while (sfRenderWindow_pollEvent(window, &event)) {
        handle_event_by_type(settings, event);
    }
}

void route_settings_by_page(settings_page_t *settings,
    settings_t page, sfEvent event)
{
    switch (page) {
        case GAME:
            handle_game_settings(settings, event);
            break;
        case CONTROLS:
            handle_controls_settings(settings, event);
            break;
        case VIDEO:
            handle_video_settings(settings, event);
            break;
        case AUDIO:
            handle_audio_settings(settings, event);
            break;
    }
}

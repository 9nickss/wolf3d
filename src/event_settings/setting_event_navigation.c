/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** setting_event_navigation
*/

#include "../../include/wolf3d.h"

bool should_handle_special_navigation(settings_page_t *settings)
{
    if (settings->current_page == GAME && settings->is_adjusting_sensitivity) {
        return true;
    }
    if (settings->current_page == AUDIO) {
        if (settings->is_adjusting_volume || settings->is_adjusting_music) {
            return true;
        }
    }
    return false;
}

void handle_left_right_keys(settings_page_t *settings, sfEvent event)
{
    int direction;

    if (should_handle_special_navigation(settings)) {
        handle_settings_input(settings->current_page, event);
        return;
    }
    direction = (event.key.code == sfKeyLeft) ? -1 : 1;
    change_settings_page(&settings->current_page, direction);
    if (settings->tab_change_sound) {
        sfSound_play(settings->tab_change_sound);
    }
}

void handle_up_down_keys(settings_page_t *settings, sfEvent event)
{
    handle_settings_input(settings->current_page, event);
}

void handle_settings_input(settings_t page, sfEvent event)
{
    settings_page_t *settings = *get_settings_page();
    keybinds_t *keybinds = get_keybinds();

    if (!settings || !keybinds)
        return;
    if (handle_rebinding(settings, keybinds, page, event))
        return;
    if (event.type != sfEvtKeyPressed)
        return;
    route_settings_by_page(settings, page, event);
}

void change_settings_page(settings_t *current_page, int direction)
{
    int new_page = (int)(*current_page) + direction;

    if (new_page < 0) {
        new_page = AUDIO;
    } else if (new_page > AUDIO) {
        new_page = GAME;
    }
    *current_page = (settings_t)new_page;
}

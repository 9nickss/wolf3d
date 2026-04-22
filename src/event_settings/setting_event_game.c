/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** setting_event_game
*/

#include "../../include/wolf3d.h"

void handle_sensitivity_exit(settings_page_t *settings)
{
    settings->is_adjusting_sensitivity = false;
}

void decrease_sensitivity(settings_page_t *settings)
{
    if (settings->sensitivity > 1) {
        settings->sensitivity--;
        apply_sensitivity_setting(settings->sensitivity);
    }
}

void increase_sensitivity(settings_page_t *settings)
{
    if (settings->sensitivity < 10) {
        settings->sensitivity++;
        apply_sensitivity_setting(settings->sensitivity);
    }
}

void handle_sensitivity_adjustment(settings_page_t *settings, sfEvent event)
{
    if (event.key.code == sfKeyLeft) {
        decrease_sensitivity(settings);
        return;
    }
    if (event.key.code == sfKeyRight) {
        increase_sensitivity(settings);
        return;
    }
    if (event.key.code == sfKeyEnter || event.key.code == sfKeyEscape) {
        handle_sensitivity_exit(settings);
    }
}

void handle_game_settings(settings_page_t *settings, sfEvent event)
{
    if (settings->is_adjusting_sensitivity) {
        handle_sensitivity_adjustment(settings, event);
        return;
    }
    if (event.key.code == sfKeyEnter) {
        settings->is_adjusting_sensitivity = true;
    }
}

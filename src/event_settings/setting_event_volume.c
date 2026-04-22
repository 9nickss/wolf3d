/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** setting_event_volume
*/

#include "../../include/wolf3d.h"

void decrease_master_volume(settings_page_t *settings)
{
    if (settings->master_volume > 0) {
        settings->master_volume -= 5;
        apply_volume_setting(settings->master_volume);
    }
}

void increase_master_volume(settings_page_t *settings)
{
    if (settings->master_volume < 100) {
        settings->master_volume += 5;
        apply_volume_setting(settings->master_volume);
    }
}

void handle_master_exit(settings_page_t *settings)
{
    settings->is_adjusting_volume = false;
}

void handle_master_volume_down(settings_page_t *settings)
{
    settings->is_adjusting_volume = false;
    settings->selected_audio_option = 1;
}

void handle_master_volume(settings_page_t *settings, sfEvent event)
{
    if (event.key.code == sfKeyLeft) {
        decrease_master_volume(settings);
        return;
    }
    if (event.key.code == sfKeyRight) {
        increase_master_volume(settings);
        return;
    }
    if (event.key.code == sfKeyEnter || event.key.code == sfKeyEscape) {
        handle_master_exit(settings);
        return;
    }
    if (event.key.code == sfKeyDown) {
        handle_master_volume_down(settings);
    }
}

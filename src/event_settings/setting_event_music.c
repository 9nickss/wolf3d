/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** setting_event_music
*/

#include "../../include/wolf3d.h"

void decrease_music_volume(settings_page_t *settings)
{
    if (settings->music_volume > 0) {
        settings->music_volume -= 5;
        apply_music_volume(settings->music_volume);
    }
}

void increase_music_volume(settings_page_t *settings)
{
    if (settings->music_volume < 100) {
        settings->music_volume += 5;
        apply_music_volume(settings->music_volume);
    }
}

void handle_music_exit(settings_page_t *settings)
{
    settings->is_adjusting_music = false;
}

void handle_music_volume_up(settings_page_t *settings)
{
    settings->is_adjusting_music = false;
    settings->selected_audio_option = 0;
}

void handle_music_volume(settings_page_t *settings, sfEvent event)
{
    if (event.key.code == sfKeyLeft) {
        decrease_music_volume(settings);
        return;
    }
    if (event.key.code == sfKeyRight) {
        increase_music_volume(settings);
        return;
    }
    if (event.key.code == sfKeyEnter || event.key.code == sfKeyEscape) {
        handle_music_exit(settings);
        return;
    }
    if (event.key.code == sfKeyUp) {
        handle_music_volume_up(settings);
    }
}

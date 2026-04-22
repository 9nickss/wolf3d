/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** setting_event_audio
*/

#include "../../include/wolf3d.h"

void handle_audio_down(settings_page_t *settings)
{
    if (settings->selected_audio_option == 0) {
        settings->selected_audio_option = 1;
    }
}

void handle_audio_up(settings_page_t *settings)
{
    if (settings->selected_audio_option == 1) {
        settings->selected_audio_option = 0;
    }
}

void handle_audio_enter(settings_page_t *settings)
{
    if (settings->selected_audio_option == 0) {
        settings->is_adjusting_volume = true;
    } else if (settings->selected_audio_option == 1) {
        settings->is_adjusting_music = true;
    }
}

void handle_audio_navigation(settings_page_t *settings, sfEvent event)
{
    if (event.key.code == sfKeyDown) {
        handle_audio_down(settings);
        return;
    }
    if (event.key.code == sfKeyUp) {
        handle_audio_up(settings);
        return;
    }
    if (event.key.code == sfKeyEnter) {
        handle_audio_enter(settings);
    }
}

void handle_audio_settings(settings_page_t *settings, sfEvent event)
{
    if (settings->is_adjusting_volume) {
        handle_master_volume(settings, event);
        return;
    }
    if (settings->is_adjusting_music) {
        handle_music_volume(settings, event);
        return;
    }
    handle_audio_navigation(settings, event);
}

/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** setting_event_video_mode
*/

#include "../../include/wolf3d.h"

void handle_video_mode_up(settings_page_t *settings)
{
    if (settings->selected_video_option > 0) {
        settings->selected_video_option--;
    }
}

void handle_video_mode_down(settings_page_t *settings)
{
    if (settings->selected_video_option < 2) {
        settings->selected_video_option++;
    }
}

void handle_video_mode_escape(settings_page_t *settings)
{
    settings->selected_video_option = settings->current_display_mode;
    settings->is_selecting_video_mode = false;
}

void apply_video_mode(settings_page_t *settings)
{
    settings->current_display_mode =
        (display_mode_t)settings->selected_video_option;
    apply_display_mode(settings->current_display_mode);
    settings->is_selecting_video_mode = false;
}

void handle_video_mode_selection(settings_page_t *settings, sfEvent event)
{
    if (event.key.code == sfKeyUp) {
        handle_video_mode_up(settings);
        return;
    }
    if (event.key.code == sfKeyDown) {
        handle_video_mode_down(settings);
        return;
    }
    if (event.key.code == sfKeyEnter) {
        apply_video_mode(settings);
        return;
    }
    if (event.key.code == sfKeyEscape) {
        handle_video_mode_escape(settings);
    }
}

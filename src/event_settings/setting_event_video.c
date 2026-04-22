/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** setting_event_video
*/

#include "../../include/wolf3d.h"

void handle_video_default_selection(settings_page_t *settings)
{
    if (settings->selected_video_option == -1 &&
        settings->selected_fps_option == -1) {
        settings->selected_video_option = settings->current_display_mode;
    }
}

void handle_video_enter(settings_page_t *settings)
{
    if (settings->selected_video_option != -1) {
        settings->is_selecting_video_mode = true;
    } else if (settings->selected_fps_option != -1) {
        settings->is_selecting_fps = true;
    }
}

void handle_video_up(settings_page_t *settings)
{
    if (settings->selected_fps_option != -1) {
        settings->selected_fps_option = -1;
        settings->selected_video_option = settings->current_display_mode;
    }
}

void handle_video_down(settings_page_t *settings)
{
    if (settings->selected_video_option != -1) {
        settings->selected_video_option = -1;
        settings->selected_fps_option = (settings->current_fps == 30) ? 0 : 1;
    }
}

void handle_video_navigation(settings_page_t *settings, sfEvent event)
{
    if (event.key.code == sfKeyEnter) {
        handle_video_enter(settings);
        return;
    }
    if (event.key.code == sfKeyDown) {
        handle_video_down(settings);
        return;
    }
    if (event.key.code == sfKeyUp) {
        handle_video_up(settings);
        return;
    }
    handle_video_default_selection(settings);
}

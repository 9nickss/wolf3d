/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** setting_event_video_fps
*/

#include "../../include/wolf3d.h"

void handle_fps_down(settings_page_t *settings)
{
    if (settings->selected_fps_option < 1) {
        settings->selected_fps_option++;
    }
}

void handle_fps_escape(settings_page_t *settings)
{
    settings->selected_fps_option = (settings->current_fps == 30) ? 0 : 1;
    settings->is_selecting_fps = false;
}

void apply_fps_option(settings_page_t *settings)
{
    int fps;

    fps = (settings->selected_fps_option == 0) ? 30 : 60;
    apply_fps_setting(fps);
    settings->is_selecting_fps = false;
}

void handle_fps_selection(settings_page_t *settings, sfEvent event)
{
    if (event.key.code == sfKeyUp) {
        handle_fps_up(settings);
        return;
    }
    if (event.key.code == sfKeyDown) {
        handle_fps_down(settings);
        return;
    }
    if (event.key.code == sfKeyEnter) {
        apply_fps_option(settings);
        return;
    }
    if (event.key.code == sfKeyEscape) {
        handle_fps_escape(settings);
    }
}

void handle_video_settings(settings_page_t *settings, sfEvent event)
{
    if (settings->is_selecting_video_mode) {
        handle_video_mode_selection(settings, event);
        return;
    }
    if (settings->is_selecting_fps) {
        handle_fps_selection(settings, event);
        return;
    }
    handle_video_navigation(settings, event);
}

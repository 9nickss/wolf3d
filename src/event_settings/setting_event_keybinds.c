/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** setting_event_keybinds
*/

#include "../../include/wolf3d.h"

void apply_rebinding(int selected_keybind, keybinds_t *keybinds, sfEvent event)
{
    switch (selected_keybind) {
        case 0:
            keybinds->move_forward = event.key.code;
            break;
        case 1:
            keybinds->move_backward = event.key.code;
            break;
        case 2:
            keybinds->move_left = event.key.code;
            break;
        case 3:
            keybinds->move_right = event.key.code;
            break;
        case 4:
            keybinds->rotate_left = event.key.code;
            break;
        case 5:
            keybinds->rotate_right = event.key.code;
            break;
    }
}

void handle_fps_up(settings_page_t *settings)
{
    if (settings->selected_fps_option > 0) {
        settings->selected_fps_option--;
    }
}

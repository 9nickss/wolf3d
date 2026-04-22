/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** setting_event_controls
*/

#include "../../include/wolf3d.h"

bool handle_rebinding(settings_page_t *settings, keybinds_t *keybinds,
    settings_t page, sfEvent event)
{
    if (!settings->rebinding_active || page != CONTROLS ||
        event.type != sfEvtKeyPressed)
        return false;
    apply_rebinding(settings->selected_keybind, keybinds, event);
    settings->rebinding_active = false;
    return true;
}

void handle_controls_up_navigation(settings_page_t *settings)
{
    if (settings->selected_keybind > 0) {
        settings->selected_keybind--;
    } else if (settings->selected_keybind == -1) {
        settings->selected_keybind = 5;
    }
}

void handle_controls_down_navigation(settings_page_t *settings)
{
    if (settings->selected_keybind < 5) {
        settings->selected_keybind++;
    } else if (settings->selected_keybind == -1) {
        settings->selected_keybind = 0;
    }
}

void handle_controls_enter(settings_page_t *settings)
{
    if (settings->selected_keybind != -1) {
        settings->rebinding_active = true;
    }
}

void handle_controls_settings(settings_page_t *settings, sfEvent event)
{
    if (event.key.code == sfKeyUp) {
        handle_controls_up_navigation(settings);
        return;
    }
    if (event.key.code == sfKeyDown) {
        handle_controls_down_navigation(settings);
        return;
    }
    if (event.key.code == sfKeyEnter) {
        handle_controls_enter(settings);
    }
}

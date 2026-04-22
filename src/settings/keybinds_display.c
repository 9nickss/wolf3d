/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** keybind_display.c - Functions for drawing keybinds in the settings
*/

#include "../../include/wolf3d.h"

void configure_keybind_params(keybind_params_t *params,
    settings_page_t *settings, keybind_position_t pos_info)
{
    params->action = pos_info.action;
    params->key = pos_info.key;
    params->position = pos_info.position;
    params->isSelected = (settings->selected_keybind == pos_info.index);
    params->isRebinding = (settings->rebinding_active &&
        settings->selected_keybind == pos_info.index);
}

static void draw_single_keybind(render_context_t context,
    settings_page_t *settings, sfVector2f startPos,
    keybind_position_t pos_info)
{
    keybind_params_t params;

    params.startPos = startPos;
    configure_keybind_params(&params, settings, pos_info);
    draw_keybind(context.window, context.font, params);
}

void draw_movement_keybinds(sfRenderWindow *window, sfFont *font,
    settings_page_t *settings, sfVector2f startPos)
{
    keybinds_t *keybinds = get_keybinds();
    keybind_position_t pos_info;
    render_context_t context = {window, font};

    if (!keybinds)
        return;
    pos_info = (keybind_position_t){
        .position = 2,
        .index = 0,
        .key = keybinds->move_forward,
        .action = "Move Forward"
    };
    draw_single_keybind(context, settings, startPos, pos_info);
    pos_info = (keybind_position_t){
        .position = 3,
        .index = 1,
        .key = keybinds->move_backward,
        .action = "Move Backward"
    };
    draw_single_keybind(context, settings, startPos, pos_info);
}

void draw_strafing_keybinds(sfRenderWindow *window, sfFont *font,
    settings_page_t *settings, sfVector2f startPos)
{
    keybinds_t *keybinds = get_keybinds();
    keybind_position_t pos_info;
    render_context_t context = {window, font};

    if (!keybinds)
        return;
    pos_info = (keybind_position_t){
        .position = 4,
        .index = 2,
        .key = keybinds->move_left,
        .action = "Move Left"
    };
    draw_single_keybind(context, settings, startPos, pos_info);
    pos_info = (keybind_position_t){
        .position = 5,
        .index = 3,
        .key = keybinds->move_right,
        .action = "Move Right"
    };
    draw_single_keybind(context, settings, startPos, pos_info);
}

void draw_all_keybinds(sfRenderWindow *window, sfFont *font,
    settings_page_t *settings, sfVector2f startPos)
{
    if (!settings || !window || !font)
        return;
    draw_movement_keybinds(window, font, settings, startPos);
    draw_strafing_keybinds(window, font, settings, startPos);
}

void draw_rotation_keybinds(sfRenderWindow *window, sfFont *font,
    settings_page_t *settings, sfVector2f startPos)
{
    keybinds_t *keybinds = get_keybinds();
    keybind_position_t pos_info;
    render_context_t context = {window, font};

    if (!keybinds)
        return;
    pos_info = (keybind_position_t){
        .position = 6,
        .index = 4,
        .key = keybinds->rotate_left,
        .action = "Rotate Left"
    };
    draw_single_keybind(context, settings, startPos, pos_info);
    pos_info = (keybind_position_t){
        .position = 7,
        .index = 5,
        .key = keybinds->rotate_right,
        .action = "Rotate Right"
    };
    draw_single_keybind(context, settings, startPos, pos_info);
}

/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** player_moves
*/

#include "../../include/wolf3d.h"

static void dash_step(sfVector2f *current_pos, sfVector2f step_direction,
    float dash_distance, float *distance_traveled)
{
    sfVector2f next_pos;

    while (*distance_traveled < dash_distance) {
        next_pos.x = (*current_pos).x + step_direction.x;
        next_pos.y = (*current_pos).y + step_direction.y;
        if (is_wall(next_pos.x, next_pos.y) != 0)
            break;
        *current_pos = next_pos;
        *distance_traveled += 1.0f;
    }
}

void dash(void)
{
    player_t *player = *get_player();
    clocks_t *clock = *get_clock();
    settings_page_t *settings_page = *get_settings_page();
    sfTime elapsed = sfClock_getElapsedTime(clock->dash_clock);
    float seconds = sfTime_asSeconds(elapsed);
    float dash_distance = (SPEED / settings_page->current_fps) * 80.0f;
    sfVector2f target_pos;
    sfVector2f step_direction = {player->dir.x * 1.0f,
        player->dir.y * 1.0f};
    float distance_traveled = 0.0f;

    if (seconds < 5 && !player->can_dash)
        return;
    target_pos = player->pos;
    dash_step(&target_pos, step_direction, dash_distance, &distance_traveled);
    update_dash_struct(target_pos);
}

void left_rotation(void)
{
    player_t *player = *get_player();

    player->angle -= 0.05f;
    player->dir = (sfVector2f){cos(player->angle), sin(player->angle)};
}

void right_rotation(void)
{
    player_t *player = *get_player();

    player->angle += 0.05f;
    player->dir = (sfVector2f){cos(player->angle), sin(player->angle)};
}

static void update_movement_state(keybinds_t keybinds)
{
    player_t **player = get_player();

    if (!sfKeyboard_isKeyPressed(keybinds.move_forward) &&
        !sfKeyboard_isKeyPressed(keybinds.move_backward) &&
        !sfKeyboard_isKeyPressed(keybinds.move_left) &&
        !sfKeyboard_isKeyPressed(keybinds.move_right) &&
        !sfKeyboard_isKeyPressed(sfKeyLShift))
    (*player)->is_moving = false;
}

static void move_while_dash(keybinds_t keybinds)
{
    if (!(*get_player())->is_dashing) {
        if (sfKeyboard_isKeyPressed(keybinds.move_forward))
            move_forward();
        if (sfKeyboard_isKeyPressed(keybinds.move_backward))
            move_backward();
        if (sfKeyboard_isKeyPressed(keybinds.move_left))
            move_left();
        if (sfKeyboard_isKeyPressed(keybinds.move_right))
            move_right();
    }
}

void move_player(keybinds_t keybinds)
{
    update_dash_animation();
    update_dash_effects();
    move_while_dash(keybinds);
    if (sfKeyboard_isKeyPressed(keybinds.rotate_left))
        left_rotation();
    if (sfKeyboard_isKeyPressed(keybinds.rotate_right))
        right_rotation();
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        dash();
    toggle_flashlight();
    update_movement_state(keybinds);
    check_attack_input();
}

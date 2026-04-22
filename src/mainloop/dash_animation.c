/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** dash_animation.c
*/

#include "../../include/wolf3d.h"

void reset_fov(void)
{
    player_t *player = *get_player();

    if (player->visual_fov_mult <= 1.0f) {
        player->visual_fov_mult = 1.0f;
        player->is_dashing = false;
    }
}

void update_dash_effects(void)
{
    player_t *player = *get_player();
    clocks_t *clock = *get_clock();
    sfTime elapsed = sfClock_getElapsedTime(clock->dash_clock);
    float seconds = sfTime_asSeconds(elapsed);

    if (player->is_dashing && seconds > 0.3f) {
        if (player->visual_fov_mult > 1.0f) {
            player->visual_fov_mult -= 0.2f;
            reset_fov();
        }
    }
}

void draw_dash_flash(void)
{
    player_t *player = *get_player();
    sfRenderWindow *window = *get_window();
    clocks_t *clock = *get_clock();
    sfTime elapsed = sfClock_getElapsedTime(clock->dash_clock);
    float seconds = sfTime_asSeconds(elapsed);
    sfRectangleShape *flash;
    int alpha;

    if (!player->is_dashing || seconds >= 0.1f)
        return;
    flash = sfRectangleShape_create();
    sfRectangleShape_setSize(flash,
        (sfVector2f){WIN_WIDTH(window), WIN_HEIGHT(window)});
    sfRectangleShape_setPosition(flash, (sfVector2f){0, 0});
    alpha = (int)(255 * (0.1f - seconds) / 0.1f);
    sfRectangleShape_setFillColor(flash,
        sfColor_fromRGBA(255, 255, 255, alpha));
    sfRenderWindow_drawRectangleShape(window, flash, NULL);
    sfRectangleShape_destroy(flash);
}

static float calculate_smooth_progress(float progress)
{
    float temp = 1.0f - progress;

    return 1.0f - temp * temp;
}

static float interpolate(float start, float target, float progress)
{
    return start + (target - start) * progress;
}

static void update_player_position(player_t *player, float progress)
{
    float start_x = player->dash_start_pos.x;
    float target_x = player->dash_target_pos.x;
    float start_y = player->dash_start_pos.y;
    float target_y = player->dash_target_pos.y;

    player->pos.x = interpolate(start_x, target_x, progress);
    player->pos.y = interpolate(start_y, target_y, progress);
}

void update_dash_struct(sfVector2f target_pos)
{
    player_t *player = *get_player();
    clocks_t *clock = *get_clock();

    player->is_dashing = true;
    player->dash_start_pos = player->pos;
    player->dash_target_pos = target_pos;
    player->visual_fov_mult = 1.6f;
    sfClock_restart(clock->dash_clock);
    player->can_dash = false;
}

void update_dash_animation(void)
{
    player_t *player = *get_player();
    sfTime elapsed = sfClock_getElapsedTime((*get_clock())->dash_clock);
    float seconds = sfTime_asSeconds(elapsed);
    float dash_progress;
    float smooth_progress;

    if (!player->is_dashing)
        return;
    dash_progress = seconds / player->dash_duration;
    if (dash_progress >= 1.0f) {
        player->pos = player->dash_target_pos;
        player->is_dashing = false;
        return;
    }
    smooth_progress = calculate_smooth_progress(dash_progress);
    update_player_position(player, smooth_progress);
}

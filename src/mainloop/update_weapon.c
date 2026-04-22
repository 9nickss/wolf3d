/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** update_weaopon.c
*/

#include "../../include/wolf3d.h"

void movement_anim(float *y_offset, float *x_offset)
{
    clocks_t **clock = get_clock();
    sfTime elapsed;
    float seconds;
    static float bobbing = 0.0f;

    elapsed = sfClock_getElapsedTime((*clock)->walk_clock);
    seconds = sfTime_asSeconds(elapsed);
    if (seconds > 0.01f) {
        sfClock_restart((*clock)->walk_clock);
        bobbing += 0.1f;
        if (bobbing > 6.28)
            bobbing = 0.0f;
    }
    *y_offset += sinf(bobbing) * 8.0f;
    *x_offset += sinf(bobbing * 2.0f) * 3.0f;
}

static void attack_frames(float *y_offset)
{
    player_t **player = get_player();

    if ((*player)->is_attacking) {
        switch ((*player)->attack_frame) {
            case 0:
                *y_offset = 10.0f;
                break;
            case 1:
                *y_offset = 40.0f;
                break;
            case 2:
                *y_offset = 20.0f;
                break;
            default:
                *y_offset = 0.0f;
        }
    }
}

void update_weapon_pos(void)
{
    player_t **player = get_player();
    sfRenderWindow *window = *get_window();
    sfVector2f weapon_pos;
    float y_offset = 0.0f;
    float x_offset = 0.0f;

    weapon_pos.x = WIN_WIDTH(window) / 2 - (306 / 2) + 350;
    weapon_pos.y = WIN_HEIGHT(window) / 2 - 204 + 250;
    attack_frames(&y_offset);
    if ((*player)->is_moving)
        movement_anim(&y_offset, &x_offset);
    weapon_pos.y += y_offset;
    weapon_pos.x += x_offset;
    sfSprite_setPosition((*player)->weapon->sprite, weapon_pos);
}

static void update_rect(sfIntRect *frame_rect)
{
    player_t **player = get_player();

    (*frame_rect).left = (*player)->attack_frame * 306;
    (*frame_rect).top = 0;
    (*frame_rect).width = 306;
    (*frame_rect).height = 204;
}

void handle_attack_anim(void)
{
    player_t **player = get_player();
    clocks_t **clocks = get_clock();
    sfTime elapsed;
    float seconds;
    sfIntRect frame_rect;

    if (!(*player)->is_attacking)
        return;
    elapsed = sfClock_getElapsedTime((*clocks)->weapon_anim_clock);
    seconds = sfTime_asSeconds(elapsed);
    if (seconds > 0.15) {
        sfClock_restart((*clocks)->weapon_anim_clock);
        (*player)->attack_frame++;
        if ((*player)->attack_frame >= 3) {
            (*player)->is_attacking = false;
            (*player)->attack_frame = 0;
        }
        update_rect(&frame_rect);
        sfSprite_setTextureRect((*player)->weapon->sprite, frame_rect);
    }
}

void check_attack_input(void)
{
    player_t **player = get_player();
    clocks_t **clocks = get_clock();
    sfIntRect first_frame = {0, 0, 306, 204};

    if (sfKeyboard_isKeyPressed(sfKeySpace) && !(*player)->is_attacking) {
        (*player)->is_attacking = true;
        (*player)->attack_frame = 0;
        sfClock_restart((*clocks)->weapon_anim_clock);
        sfSprite_setTextureRect((*player)->weapon->sprite, first_frame);
    }
}

void draw_weapon(void)
{
    sfRenderWindow *window = *get_window();
    player_t **player = get_player();

    if ((*player)->weapon) {
        update_weapon_pos();
        handle_attack_anim();
        sfRenderWindow_drawSprite(window, (*player)->weapon->sprite, NULL);
    }
}

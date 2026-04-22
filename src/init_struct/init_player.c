/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_player
*/

#include "../../include/wolf3d.h"

player_t **get_player(void)
{
    static player_t *player = NULL;

    return &player;
}

static void init_dash(void)
{
    player_t **player = get_player();

    (*player)->can_dash = true;
    (*player)->base_fov = 1.0f;
    (*player)->visual_fov_mult = 1.0f;
    (*player)->fov = (*player)->base_fov;
    (*player)->is_dashing = false;
    (*player)->dash_duration = 0.25f;
}

static int allocate_player(player_t **player)
{
    *player = malloc(sizeof(player_t));
    if (!(*player))
        return 84;
    return 0;
}

static void set_rotation_speed(player_t *player, settings_page_t *settings)
{
    float base_rotation_speed = 0.05f;
    float sensitivity_factor = 0;

    if (settings) {
        sensitivity_factor = settings->sensitivity / 5.0f;
        player->rotation_speed = base_rotation_speed * sensitivity_factor;
    } else {
        player->rotation_speed = base_rotation_speed;
    }
}

static void init_player_fields(player_t *player)
{
    player->angle = 0;
    player->pos = (sfVector2f){3 * TILE_SIZE + TILE_SIZE / 2,
        3 * TILE_SIZE + TILE_SIZE / 2};
    player->dir = (sfVector2f){cos(player->angle), sin(player->angle)};
    player->can_dash = true;
}

static int create_shapes(player_t *player)
{
    player->circle = sfCircleShape_create();
    if (!player->circle)
        return 84;
    player->line = sfRectangleShape_create();
    if (!player->line)
        return 84;
    return 0;
}

int init_flashlight(player_t *player)
{
    sfVector2f center;
    float radius;

    player->has_flashlight = true;
    player->flashlight_on = false;
    player->flashlight_effect = sfCircleShape_create();
    if (!player->flashlight_effect)
        return 84;
    radius = 325.0f;
    sfCircleShape_setRadius(player->flashlight_effect, radius);
    center.x = WIN_WIDTH(*get_window()) / 2.0f - radius;
    center.y = WIN_HEIGHT(*get_window()) / 1.85f - radius;
    sfCircleShape_setPosition(player->flashlight_effect, center);
    sfCircleShape_setFillColor(player->flashlight_effect,
        sfColor_fromRGBA(255, 250, 205, 60));
    return 0;
}

int init_player(void)
{
    player_t **player = get_player();
    settings_page_t *settings = *get_settings_page();

    if (allocate_player(player) == 84)
        return 84;
    set_rotation_speed(*player, settings);
    init_player_fields(*player);
    if (create_shapes(*player) == 84)
        return 84;
    init_dash();
    if (init_flashlight(*player) == 84)
        return 84;
    (*player)->particles = NULL;
    return 0;
}

int init_weapon(void)
{
    player_t **player = get_player();
    sfIntRect first_frame = {30, 0, 306, 204};

    (*player)->weapon = get_sprite("assets/items/weapon_sprite.png");
    if (!(*player)->weapon)
        return 84;
    (*player)->is_attacking = false;
    (*player)->attack_frame = 0;
    (*player)->is_moving = false;
    sfSprite_setTextureRect((*player)->weapon->sprite, first_frame);
    sfSprite_setScale((*player)->weapon->sprite, (sfVector2f){2.3, 2.3});
    return 0;
}

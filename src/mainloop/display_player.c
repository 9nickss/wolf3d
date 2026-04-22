/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** display_player
*/

#include "../../include/wolf3d.h"

void draw_player_direction(void)
{
    sfRenderWindow *window = *get_window();
    player_t *player = *get_player();
    float player_x = (WIN_WIDTH(window) - MINIMAP_SIZE) +
        (player->pos.x / TILE_SIZE) * (MINIMAP_SIZE / MAP_SIZE);
    float player_y = (player->pos.y / TILE_SIZE) *
        (MINIMAP_SIZE / MAP_SIZE);
    float length = (MINIMAP_SIZE / MAP_SIZE) * 2;
    float thickness = (MINIMAP_SIZE / MAP_SIZE) * 0.3;

    sfRectangleShape_setFillColor(player->line, sfRed);
    sfRectangleShape_setSize(player->line, (sfVector2f){length, thickness});
    sfRectangleShape_setOrigin(player->line,
        (sfVector2f){0.0f, thickness * 0.5});
    sfRectangleShape_setPosition(player->line,
        (sfVector2f){player_x, player_y});
    sfRectangleShape_setRotation(player->line, player->angle * (180 / M_PI));
    sfRenderWindow_drawRectangleShape(window, player->line, NULL);
}

void draw_player(void)
{
    sfRenderWindow *window = *get_window();
    player_t *player = *get_player();
    float player_x = (WIN_WIDTH(window) - MINIMAP_SIZE) +
        (player->pos.x / TILE_SIZE) * (MINIMAP_SIZE / MAP_SIZE);
    float player_y = (player->pos.y / TILE_SIZE) * (MINIMAP_SIZE / MAP_SIZE);
    float circle_radius = (MINIMAP_SIZE / MAP_SIZE) * 0.4;

    sfCircleShape_setRadius(player->circle, circle_radius);
    sfCircleShape_setFillColor(player->circle, sfRed);
    sfCircleShape_setPosition(player->circle,
        (sfVector2f){player_x, player_y});
    sfCircleShape_setOrigin(player->circle,
        (sfVector2f){circle_radius, circle_radius});
    sfCircleShape_setRotation(player->circle, player->angle * (180 / M_PI));
    sfRenderWindow_drawCircleShape(window, player->circle, NULL);
}

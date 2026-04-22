/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** basic_mouvements
*/

#include "../../include/wolf3d.h"

static void handle_wall(sfVector2f new_pos)
{
    player_t *player = *get_player();

    if (is_wall(new_pos.x, new_pos.y) == 0) {
        player->pos = new_pos;
        return;
    }
    if (is_wall(new_pos.x, player->pos.y) == 0) {
        player->pos.x = new_pos.x;
        return;
    }
    if (is_wall(player->pos.x, new_pos.y) == 0) {
        player->pos.y = new_pos.y;
        return;
    }
}

void move_forward(void)
{
    settings_page_t *settings = *get_settings_page();
    player_t *player = *get_player();
    sfVector2f new_pos = (sfVector2f){
        player->pos.x + player->dir.x * (SPEED / settings->current_fps),
        player->pos.y + player->dir.y * (SPEED / settings->current_fps)};

    handle_wall(new_pos);
    (*player).is_moving = true;
}

void move_backward(void)
{
    settings_page_t *settings = *get_settings_page();
    player_t *player = *get_player();
    sfVector2f new_pos = (sfVector2f){
        player->pos.x - player->dir.x * (SPEED / settings->current_fps),
        player->pos.y - player->dir.y * (SPEED / settings->current_fps)};

    handle_wall(new_pos);
    (*player).is_moving = true;
}

void move_right(void)
{
    settings_page_t *settings = *get_settings_page();
    player_t *player = *get_player();
    sfVector2f new_pos = (sfVector2f){
        player->pos.x - player->dir.y * (SPEED / settings->current_fps),
        player->pos.y + player->dir.x * (SPEED / settings->current_fps)};

    handle_wall(new_pos);
    (*player).is_moving = true;
}

void move_left(void)
{
    settings_page_t *settings = *get_settings_page();
    player_t *player = *get_player();
    sfVector2f new_pos = (sfVector2f){
        player->pos.x + player->dir.y * (SPEED / settings->current_fps),
        player->pos.y - player->dir.x * (SPEED / settings->current_fps)};

    handle_wall(new_pos);
    (*player).is_moving = true;
}

/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** set_sprite
*/

#include "../../include/wolf3d.h"

void set_sprite(bool on, sprite_t *sprite, sfVector2f pos, sfVector2f scale)
{
    sprite->on = on;
    sprite->pos = pos;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setScale(sprite->sprite, scale);
}

sprite_t *get_sprite(const char *path)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    if (!sprite)
        return NULL;
    sprite->texture = sfTexture_createFromFile(path, NULL);
    if (!sprite->texture)
        return NULL;
    sprite->sprite = sfSprite_create();
    if (!sprite->sprite)
        return NULL;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sprite->pos = (sfVector2f){0, 0};
    sprite->on = false;
    return sprite;
}

/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** video_resources.c
*/

#include "../../include/wolf3d.h"

sfFont *load_font(void)
{
    sfFont *font = NULL;

    font = sfFont_createFromFile("fonts/ghost.otf");
    if (!font)
        font = sfFont_createFromFile("assets/fonts/ghost.otf");
    return font;
}

void init_helmet_sprite(sfSprite **sprite, sfTexture **texture)
{
    *texture = NULL;
    *sprite = NULL;
    *texture = sfTexture_createFromFile("assets/helmet.png", NULL);
    if (!(*texture))
        return;
    *sprite = sfSprite_create();
    if (*sprite) {
        sfSprite_setTexture(*sprite, *texture, sfTrue);
        sfSprite_setScale(*sprite, (sfVector2f){0.1f, 0.1f});
    }
}

void setup_video_resources(settings_page_t **settings, sfFont **font,
    sfSprite **helmetSprite, sfTexture **helmetTexture)
{
    *settings = *get_settings_page();
    *font = load_font();
    if (*font && *settings && (*settings)->video) {
        init_helmet_sprite(helmetSprite, helmetTexture);
    }
}

void cleanup_video_resources(sfSprite *helmetSprite, sfTexture *helmetTexture,
    sfFont *font)
{
    if (helmetSprite) {
        sfSprite_destroy(helmetSprite);
    }
    if (helmetTexture) {
        sfTexture_destroy(helmetTexture);
    }
    if (font) {
        sfFont_destroy(font);
    }
}

void init_video_positions(sfVector2f bgPos, sfVector2u textureSize,
    sfVector2f *startPos, sfVector2f *fpsPosition)
{
    startPos->x = bgPos.x + textureSize.x * 0.25f;
    startPos->y = bgPos.y + 180;
    fpsPosition->x = startPos->x;
    fpsPosition->y = startPos->y + 300;
}

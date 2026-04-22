/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** game_settings.c - Main game settings UI
*/

#include "../../include/wolf3d.h"

static void draw_settings_title(sfRenderWindow *window, sfFont *font,
    sfVector2f bgPos, sfVector2u textureSize)
{
    sfText *title = NULL;
    sfFloatRect titleBounds;
    sfVector2f titlePos;

    title = sfText_create();
    if (!title)
        return;
    sfText_setFont(title, font);
    sfText_setString(title, "GAME SETTINGS");
    sfText_setCharacterSize(title, 36);
    sfText_setFillColor(title, sfWhite);
    titleBounds = sfText_getLocalBounds(title);
    titlePos.x = bgPos.x + textureSize.x / 2 - titleBounds.width / 2;
    titlePos.y = bgPos.y + 50;
    sfText_setPosition(title, titlePos);
    sfRenderWindow_drawText(window, title, NULL);
    sfText_destroy(title);
}

static void draw_game_settings_helmet(sfRenderWindow *window,
    sfVector2f startPos)
{
    sfTexture *helmetTexture = NULL;
    sfSprite *helmetSprite = NULL;
    sfVector2f helmetPos;

    helmetTexture = sfTexture_createFromFile("assets/helmet.png", NULL);
    if (!helmetTexture)
        return;
    helmetSprite = sfSprite_create();
    if (!helmetSprite) {
        sfTexture_destroy(helmetTexture);
        return;
    }
    helmetPos.x = startPos.x - 40;
    helmetPos.y = startPos.y + 105;
    sfSprite_setTexture(helmetSprite, helmetTexture, sfTrue);
    sfSprite_setScale(helmetSprite, (sfVector2f){0.1f, 0.1f});
    sfSprite_setPosition(helmetSprite, helmetPos);
    sfRenderWindow_drawSprite(window, helmetSprite, NULL);
    sfSprite_destroy(helmetSprite);
    sfTexture_destroy(helmetTexture);
}

static int setup_settings_resources(settings_page_t **settings, sfFont **font)
{
    *settings = *get_settings_page();
    *font = sfFont_createFromFile("fonts/ghost.otf");
    if (!*font)
        *font = sfFont_createFromFile("assets/fonts/ghost.otf");
    if (!*font || !*settings || !(*settings)->game)
        return 0;
    return 1;
}

void draw_game_settings(sfRenderWindow *window)
{
    settings_page_t *settings = NULL;
    sfFont *font = NULL;
    sfVector2f bgPos;
    sfVector2u textureSize;
    sfVector2f startPos;

    if (!setup_settings_resources(&settings, &font))
        return;
    bgPos = sfSprite_getPosition(settings->game->sprite);
    textureSize = sfTexture_getSize(sfSprite_getTexture
        (settings->game->sprite));
    startPos.x = bgPos.x + textureSize.x * 0.25f;
    startPos.y = bgPos.y + 180;
    draw_settings_title(window, font, bgPos, textureSize);
    draw_game_settings_helmet(window, startPos);
    draw_sensitivity_control(window, font, settings, startPos);
    sfFont_destroy(font);
}

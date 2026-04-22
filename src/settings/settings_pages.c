/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** settings_pages - Page content display for settings menu
*/

#include "../../include/wolf3d.h"

sprite_t *get_current_page_sprite(settings_page_t *settings)
{
    if (!settings)
        return NULL;
    switch (settings->current_page) {
        case GAME:
            return settings->game;
        case CONTROLS:
            return settings->controle;
        case VIDEO:
            return settings->video;
        case AUDIO:
            return settings->audio;
        default:
            return NULL;
    }
}

void draw_page_sprite(sfRenderWindow *window, sprite_t *current)
{
    sfVector2u windowSize;
    sfVector2u textureSize;
    float xPosition;
    float yPosition = 100.0f;

    if (!current || !window)
        return;
    windowSize = sfRenderWindow_getSize(window);
    textureSize = sfTexture_getSize(sfSprite_getTexture(current->sprite));
    xPosition = (windowSize.x - textureSize.x) / 2.0f;
    sfSprite_setPosition(current->sprite, (sfVector2f){xPosition, yPosition});
    sfSprite_setScale(current->sprite, (sfVector2f){1.0f, 1.0f});
    sfRenderWindow_drawSprite(window, current->sprite, NULL);
}

void draw_current_page_content(sfRenderWindow *window,
    settings_page_t *settings)
{
    if (!window || !settings)
        return;
    switch (settings->current_page) {
        case GAME:
            draw_game_settings(window);
            break;
        case CONTROLS:
            draw_controls_settings(window);
            break;
        case VIDEO:
            draw_video_settings(window);
            break;
        case AUDIO:
            draw_audio_settings(window);
            break;
    }
}

static sprite_t *get_settings_page_sprite(settings_page_t *settings)
{
    sprite_t *current = NULL;

    if (!settings)
        return NULL;
    switch (settings->current_page) {
        case GAME:
            current = settings->game;
            break;
        case CONTROLS:
            current = settings->controle;
            break;
        case VIDEO:
            current = settings->video;
            break;
        case AUDIO:
            current = settings->audio;
            break;
    }
    return current;
}

static void position_and_draw_sprite(sfRenderWindow *window, sprite_t *sprite,
    sfVector2u windowSize)
{
    sfVector2u textureSize;
    float xPosition;
    float yPosition = 100.0f;

    if (!sprite || !window)
        return;
    textureSize = sfTexture_getSize(sfSprite_getTexture(sprite->sprite));
    xPosition = (windowSize.x - textureSize.x) / 2.0f;
    sfSprite_setPosition(sprite->sprite, (sfVector2f){xPosition, yPosition});
    sfSprite_setScale(sprite->sprite, (sfVector2f){1.0f, 1.0f});
    sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
}

static void draw_page_specific_settings(sfRenderWindow *window,
    settings_page_t *settings)
{
    if (!window || !settings)
        return;
    switch (settings->current_page) {
        case GAME:
            draw_game_settings(window);
            break;
        case CONTROLS:
            draw_controls_settings(window);
            break;
        case VIDEO:
            draw_video_settings(window);
            break;
        case AUDIO:
            draw_audio_settings(window);
            break;
    }
}

static void draw_settings_background(sfRenderWindow *window,
    settings_page_t *settings)
{
    if (!settings || !settings->all || !window)
        return;
    sfRenderWindow_drawSprite(window, settings->all->sprite, NULL);
}

void draw_settings_page(void)
{
    sfRenderWindow *window = *get_window();
    settings_page_t *settings = *get_settings_page();
    sprite_t *current = NULL;
    sfVector2u windowSize;

    if (!settings || !settings->all || !window)
        return;
    windowSize = sfRenderWindow_getSize(window);
    draw_settings_background(window, settings);
    current = get_settings_page_sprite(settings);
    if (current) {
        position_and_draw_sprite(window, current, windowSize);
        draw_page_specific_settings(window, settings);
    }
}

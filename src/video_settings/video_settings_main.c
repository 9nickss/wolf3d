/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** video_settings_main.c
*/

#include "../../include/wolf3d.h"

void draw_video_sections(sfRenderWindow *window, sfFont *font,
    settings_page_t *settings, sfSprite *helmetSprite)
{
    sfVector2f bgPos;
    sfVector2u textureSize;
    sfVector2f startPos;
    sfVector2f fpsPosition;

    bgPos = sfSprite_getPosition(settings->video->sprite);
    textureSize = sfTexture_getSize(sfSprite_getTexture
        (settings->video->sprite));
    startPos.x = bgPos.x + textureSize.x * 0.25f;
    startPos.y = bgPos.y + 180;
    fpsPosition.x = startPos.x;
    fpsPosition.y = startPos.y + 300;
    draw_video_header(window, font, bgPos, textureSize);
    draw_display_mode_section(window, font, startPos, helmetSprite);
    draw_fps_section(window, font, fpsPosition, helmetSprite);
}

void draw_video_settings(sfRenderWindow *window)
{
    settings_page_t *settings = NULL;
    sfFont *font = NULL;
    sfTexture *helmetTexture = NULL;
    sfSprite *helmetSprite = NULL;

    setup_video_resources(&settings, &font, &helmetSprite, &helmetTexture);
    if (!font || !settings || !settings->video)
        return;
    draw_video_sections(window, font, settings, helmetSprite);
    cleanup_video_resources(helmetSprite, helmetTexture, font);
}

void apply_display_mode(display_mode_t mode)
{
    sfRenderWindow **window = get_window();

    if (*window) {
        sfRenderWindow_destroy(*window);
        *window = NULL;
    }
    if (mode == WINDOWED)
        init_windowed();
    else if (mode == FULLSCREEN)
        init_full_screen();
    else
        init_window();
}

void apply_fps_setting(int fps)
{
    sfRenderWindow *window = *get_window();
    settings_page_t *settings = *get_settings_page();

    if (fps != 30 && fps != 60) {
        fps = 60;
    }
    settings->current_fps = fps;
    sfRenderWindow_setFramerateLimit(window, fps);
}

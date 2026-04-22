/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** video_fps.c
*/

#include "../../include/wolf3d.h"

void draw_fps_label(sfRenderWindow *window, sfFont *font, sfVector2f position)
{
    sfText *fpsLabel = NULL;

    fpsLabel = sfText_create();
    if (!fpsLabel)
        return;
    sfText_setFont(fpsLabel, font);
    sfText_setString(fpsLabel, "FPS Limit:");
    sfText_setCharacterSize(fpsLabel, 27);
    sfText_setFillColor(fpsLabel, sfWhite);
    sfText_setPosition(fpsLabel, position);
    sfRenderWindow_drawText(window, fpsLabel, NULL);
    sfText_destroy(fpsLabel);
}

void draw_current_fps_value(sfRenderWindow *window, sfFont *font,
    sfVector2f position, int current_fps)
{
    sfText *currentFps = NULL;
    char fps_str[10];

    currentFps = sfText_create();
    if (!currentFps)
        return;
    sprintf(fps_str, "%d FPS", current_fps);
    sfText_setFont(currentFps, font);
    sfText_setString(currentFps, fps_str);
    sfText_setCharacterSize(currentFps, 24);
    sfText_setFillColor(currentFps, sfYellow);
    sfText_setPosition(currentFps,
        (sfVector2f){position.x + 20, position.y + 40});
    sfRenderWindow_drawText(window, currentFps, NULL);
    sfText_destroy(currentFps);
}

void draw_fps_option(sfRenderWindow *window, sfFont *font,
    sfVector2f position, settings_page_t *settings)
{
    draw_fps_label(window, font, position);
    if (settings->is_selecting_fps) {
        draw_fps_dropdown(window, font, position, settings);
    } else {
        draw_current_fps_value(window, font, position, settings->current_fps);
        draw_prompt_message(window, font, position);
    }
}

void draw_fps_helmet(sfRenderWindow *window, sfSprite *helmetSprite,
    sfVector2f fpsPosition, settings_page_t *settings)
{
    if (settings->selected_fps_option != -1 &&
        !settings->is_selecting_video_mode && helmetSprite) {
        sfSprite_setPosition(helmetSprite, (sfVector2f){
            fpsPosition.x - 40,
            fpsPosition.y + 5
        });
        sfRenderWindow_drawSprite(window, helmetSprite, NULL);
    }
}

void draw_fps_section(sfRenderWindow *window, sfFont *font,
    sfVector2f fpsPosition, sfSprite *helmetSprite)
{
    settings_page_t *settings = *get_settings_page();

    draw_fps_helmet(window, helmetSprite, fpsPosition, settings);
    draw_fps_option(window, font, fpsPosition, settings);
}

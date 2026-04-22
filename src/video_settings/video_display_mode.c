/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** video_display_mode.c
*/

#include "../../include/wolf3d.h"

bool should_draw_mode_helmet(settings_page_t *settings)
{
    return (settings && settings->selected_video_option != -1 &&
        !settings->is_selecting_fps);
}

void create_mode_label_text(sfRenderWindow *window, sfText *label,
    sfFont *font, sfVector2f startPos)
{
    sfText_setFont(label, font);
    sfText_setString(label, "Display Mode:");
    sfText_setCharacterSize(label, 27);
    sfText_setFillColor(label, sfWhite);
    sfText_setPosition(label, (sfVector2f){
        startPos.x,
        startPos.y + 80
    });
    sfRenderWindow_drawText(window, label, NULL);
}

void draw_display_mode_label(sfRenderWindow *window, sfFont *font,
    sfVector2f startPos, sfSprite *helmetSprite)
{
    sfText *displayModeLabel = NULL;
    settings_page_t *settings = *get_settings_page();

    displayModeLabel = sfText_create();
    if (!displayModeLabel)
        return;
    if (should_draw_mode_helmet(settings) && helmetSprite) {
        draw_helmet_sprite(window, helmetSprite, (sfVector2f){
            startPos.x - 40,
            startPos.y + 85
        });
    }
    create_mode_label_text(window, displayModeLabel, font, startPos);
    sfText_destroy(displayModeLabel);
}

void draw_current_display_mode(sfRenderWindow *window, sfFont *font,
    sfVector2f startPos, settings_page_t *settings)
{
    sfText *currentMode = NULL;
    const char *option_names[3] =
        {"Windowed", "Fullscreen", "Windowed Fullscreen"};

    currentMode = sfText_create();
    if (!currentMode)
        return;
    sfText_setFont(currentMode, font);
    sfText_setString(currentMode,
        option_names[settings->current_display_mode]);
    sfText_setCharacterSize(currentMode, 24);
    sfText_setFillColor(currentMode, sfYellow);
    sfText_setPosition(currentMode, (sfVector2f){
        startPos.x,
        startPos.y + 110
    });
    sfRenderWindow_drawText(window, currentMode, NULL);
    sfText_destroy(currentMode);
}

void draw_display_mode_section(sfRenderWindow *window, sfFont *font,
    sfVector2f startPos, sfSprite *helmetSprite)
{
    settings_page_t *settings = *get_settings_page();

    draw_display_mode_label(window, font, startPos, helmetSprite);
    if (settings->is_selecting_video_mode) {
        draw_video_dropdown(window, font, startPos, settings);
    } else {
        draw_current_display_mode(window, font, startPos, settings);
        draw_display_prompt(window, font, startPos);
    }
}

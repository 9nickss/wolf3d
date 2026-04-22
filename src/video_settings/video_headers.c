/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** video_headers.c
*/

#include "../../include/wolf3d.h"

void draw_video_title(sfRenderWindow *window, sfFont *font, sfVector2f bgPos,
    sfVector2u textureSize)
{
    sfText *title = NULL;
    sfFloatRect titleBounds;

    title = sfText_create();
    if (!title)
        return;
    sfText_setFont(title, font);
    sfText_setString(title, "VIDEO SETTINGS");
    sfText_setCharacterSize(title, 36);
    sfText_setFillColor(title, sfWhite);
    titleBounds = sfText_getLocalBounds(title);
    sfText_setPosition(title, (sfVector2f){
        bgPos.x + textureSize.x / 2 - titleBounds.width / 2,
        bgPos.y + 50
    });
    sfRenderWindow_drawText(window, title, NULL);
    sfText_destroy(title);
}

void draw_instructions(sfRenderWindow *window, sfFont *font, sfVector2f bgPos,
    sfVector2u textureSize)
{
    sfText *instructions = NULL;
    sfFloatRect instrBounds;

    instructions = sfText_create();
    if (!instructions)
        return;
    sfText_setFont(instructions, font);
    sfText_setString(instructions, "Press Up/Down to select, Enter to apply");
    sfText_setCharacterSize(instructions, 18);
    sfText_setFillColor(instructions, sfWhite);
    instrBounds = sfText_getLocalBounds(instructions);
    sfText_setPosition(instructions, (sfVector2f){
        bgPos.x + textureSize.x / 2 - instrBounds.width / 2,
        bgPos.y + 95
    });
    sfRenderWindow_drawText(window, instructions, NULL);
    sfText_destroy(instructions);
}

void draw_video_header(sfRenderWindow *window, sfFont *font,
    sfVector2f bgPos, sfVector2u textureSize)
{
    settings_page_t *settings = *get_settings_page();

    draw_video_title(window, font, bgPos, textureSize);
    if (settings->is_selecting_video_mode || settings->is_selecting_fps) {
        draw_instructions(window, font, bgPos, textureSize);
    }
}

void draw_video_option(sfRenderWindow *window, sfFont *font,
    video_option_style_t style, sfVector2f startPos)
{
    sfText *optionText = sfText_create();

    if (!optionText)
        return;
    sfText_setFont(optionText, font);
    sfText_setString(optionText, style.text);
    sfText_setCharacterSize(optionText, 24);
    if (style.selected && style.active) {
        sfText_setFillColor(optionText, sfGreen);
    } else if (style.selected) {
        sfText_setFillColor(optionText, sfYellow);
    } else {
        sfText_setFillColor(optionText, sfWhite);
    }
    sfText_setPosition(optionText, (sfVector2f){
        startPos.x,
        startPos.y + style.position * 55
    });
    sfRenderWindow_drawText(window, optionText, NULL);
    sfText_destroy(optionText);
}

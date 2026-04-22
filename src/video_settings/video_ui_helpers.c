/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** video_ui_helpers.c
*/

#include "../../include/wolf3d.h"

void draw_selection_arrow(sfRenderWindow *window,
    sfFont *font, sfVector2f position)
{
    sfText *arrow = NULL;

    arrow = sfText_create();
    if (!arrow)
        return;
    sfText_setFont(arrow, font);
    sfText_setString(arrow, ">");
    sfText_setCharacterSize(arrow, 24);
    sfText_setFillColor(arrow, sfYellow);
    sfText_setPosition(arrow, position);
    sfRenderWindow_drawText(window, arrow, NULL);
    sfText_destroy(arrow);
}

void draw_checkmark(sfRenderWindow *window, sfFont *font, sfVector2f position)
{
    sfText *check = NULL;

    check = sfText_create();
    if (!check)
        return;
    sfText_setFont(check, font);
    sfText_setString(check, "✓");
    sfText_setCharacterSize(check, 24);
    sfText_setFillColor(check, sfGreen);
    sfText_setPosition(check, position);
    sfRenderWindow_drawText(window, check, NULL);
    sfText_destroy(check);
}

void draw_display_arrow(sfRenderWindow *window,
    sfFont *font, sfVector2f position)
{
    sfText *arrow = NULL;

    arrow = sfText_create();
    if (!arrow)
        return;
    sfText_setFont(arrow, font);
    sfText_setString(arrow, ">");
    sfText_setCharacterSize(arrow, 24);
    sfText_setFillColor(arrow, sfYellow);
    sfText_setPosition(arrow, position);
    sfRenderWindow_drawText(window, arrow, NULL);
    sfText_destroy(arrow);
}

void draw_display_checkmark(sfRenderWindow *window, sfFont *font,
    sfVector2f position)
{
    sfText *checkmark = NULL;

    checkmark = sfText_create();
    if (!checkmark)
        return;
    sfText_setFont(checkmark, font);
    sfText_setString(checkmark, "✓");
    sfText_setCharacterSize(checkmark, 24);
    sfText_setFillColor(checkmark, sfGreen);
    sfText_setPosition(checkmark, position);
    sfRenderWindow_drawText(window, checkmark, NULL);
    sfText_destroy(checkmark);
}

void draw_helmet_sprite(sfRenderWindow *window, sfSprite *helmetSprite,
    sfVector2f position)
{
    if (!helmetSprite)
        return;
    sfSprite_setPosition(helmetSprite, position);
    sfRenderWindow_drawSprite(window, helmetSprite, NULL);
}

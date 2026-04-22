/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** audio_controls.c - Core volume control elements
*/

#include "../../include/wolf3d.h"

void draw_master_volume_label(sfRenderWindow *window, sfFont *font)
{
    sfText *volumeLabel = sfText_create();

    if (!volumeLabel)
        return;
    sfText_setFont(volumeLabel, font);
    sfText_setString(volumeLabel, "Master Volume:");
    sfText_setCharacterSize(volumeLabel, 27);
    sfText_setFillColor(volumeLabel, sfWhite);
    sfText_setPosition(volumeLabel, (sfVector2f){671, 381});
    sfRenderWindow_drawText(window, volumeLabel, NULL);
    sfText_destroy(volumeLabel);
}

void draw_volume_slider_background(sfRenderWindow *window,
    sfVector2f position, float width, float height)
{
    sfRectangleShape *sliderBg = sfRectangleShape_create();
    sfVector2f sliderPos = {position.x, position.y + 150};

    if (!sliderBg)
        return;
    sfRectangleShape_setPosition(sliderBg, sliderPos);
    sfRectangleShape_setSize(sliderBg, (sfVector2f){width, height});
    sfRectangleShape_setFillColor(sliderBg, (sfColor){60, 60, 60, 255});
    sfRectangleShape_setOutlineThickness(sliderBg, 1);
    sfRectangleShape_setOutlineColor(sliderBg, sfWhite);
    sfRenderWindow_drawRectangleShape(window, sliderBg, NULL);
    sfRectangleShape_destroy(sliderBg);
}

void draw_volume_slider_fill(sfRenderWindow *window,
    sfVector2f position, slider_size_t size, float fillRatio)
{
    sfRectangleShape *sliderFill = sfRectangleShape_create();
    sfVector2f sliderPos = {position.x, position.y + 150};

    if (!sliderFill)
        return;
    sfRectangleShape_setPosition(sliderFill, sliderPos);
    sfRectangleShape_setSize(sliderFill,
        (sfVector2f){size.width * fillRatio, size.height});
    sfRectangleShape_setFillColor(sliderFill, sfYellow);
    sfRenderWindow_drawRectangleShape(window, sliderFill, NULL);
    sfRectangleShape_destroy(sliderFill);
}

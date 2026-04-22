/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** music_controls.c - Music volume controls for audio settings
*/

#include "../../include/wolf3d.h"

void draw_music_label(sfRenderWindow *window, sfFont *font,
    sfVector2f position)
{
    sfText *musicLabel = sfText_create();

    if (!musicLabel)
        return;
    sfText_setFont(musicLabel, font);
    sfText_setString(musicLabel, "Music Volume:");
    sfText_setCharacterSize(musicLabel, 27);
    sfText_setFillColor(musicLabel, sfWhite);
    sfText_setPosition(musicLabel, (sfVector2f){
        position.x,
        position.y + 200
    });
    sfRenderWindow_drawText(window, musicLabel, NULL);
    sfText_destroy(musicLabel);
}

void draw_slider_background(sfRenderWindow *window, sfVector2f position,
    float width, float height)
{
    sfRectangleShape *sliderBg = sfRectangleShape_create();
    sfVector2f sliderPos = {position.x, position.y + 250};

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

void draw_slider_fill(sfRenderWindow *window, sfVector2f position,
    slider_size_t size, float fillRatio)
{
    sfRectangleShape *sliderFill = sfRectangleShape_create();
    sfVector2f sliderPos = {position.x, position.y + 250};

    if (!sliderFill)
        return;
    sfRectangleShape_setPosition(sliderFill, sliderPos);
    sfRectangleShape_setSize(sliderFill,
        (sfVector2f){size.width * fillRatio, size.height});
    sfRectangleShape_setFillColor(sliderFill, sfYellow);
    sfRenderWindow_drawRectangleShape(window, sliderFill, NULL);
    sfRectangleShape_destroy(sliderFill);
}

void draw_volume_text(sfRenderWindow *window, sfFont *font,
    sfVector2f position, int volume)
{
    char volumeStr[10];
    sfText *volumeValue = sfText_create();

    sprintf(volumeStr, "%d%%", volume);
    if (!volumeValue)
        return;
    sfText_setFont(volumeValue, font);
    sfText_setString(volumeValue, volumeStr);
    sfText_setCharacterSize(volumeValue, 24);
    sfText_setFillColor(volumeValue, sfYellow);
    sfText_setPosition(volumeValue, (sfVector2f){
        position.x + 270,
        position.y + 245
    });
    sfRenderWindow_drawText(window, volumeValue, NULL);
    sfText_destroy(volumeValue);
}

void draw_adjustment_arrows(sfRenderWindow *window, sfFont *font,
    sfVector2f position, sfBool isAdjusting)
{
    sfText *arrowsText;

    if (!isAdjusting)
        return;
    arrowsText = sfText_create();
    if (!arrowsText)
        return;
    sfText_setFont(arrowsText, font);
    sfText_setString(arrowsText, "◄     ►");
    sfText_setCharacterSize(arrowsText, 24);
    sfText_setFillColor(arrowsText, sfGreen);
    sfText_setPosition(arrowsText, (sfVector2f){
        position.x + 100,
        position.y + 280
    });
    sfRenderWindow_drawText(window, arrowsText, NULL);
    sfText_destroy(arrowsText);
}

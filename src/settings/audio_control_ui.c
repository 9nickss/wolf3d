/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** audio_controls_ui.c - Text and UI elements for volume controls
*/

#include "../../include/wolf3d.h"

void draw_master_volume_value(sfRenderWindow *window, sfFont *font,
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
        position.y + 145
    });
    sfRenderWindow_drawText(window, volumeValue, NULL);
    sfText_destroy(volumeValue);
}

void draw_volume_adjustment_arrows(sfRenderWindow *window, sfFont *font,
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
        position.y + 80
    });
    sfRenderWindow_drawText(window, arrowsText, NULL);
    sfText_destroy(arrowsText);
}

void draw_volume_instructions(sfRenderWindow *window, sfFont *font,
    sfVector2f position)
{
    sfText *instruction = sfText_create();

    if (!instruction)
        return;
    sfText_setFont(instruction, font);
    sfText_setString(instruction,
        "Press Enter to adjust, then Left/Right arrows");
    sfText_setCharacterSize(instruction, 18);
    sfText_setFillColor(instruction, sfWhite);
    sfText_setPosition(instruction, (sfVector2f){
        position.x + 100,
        position.y - 85
    });
    sfRenderWindow_drawText(window, instruction, NULL);
    sfText_destroy(instruction);
}

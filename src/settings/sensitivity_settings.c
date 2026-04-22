/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** sensitivity_settings.c - Sensitivity settings UI and functionality
*/

#include "../../include/wolf3d.h"

static void draw_sensitivity_label(sfRenderWindow *window, sfFont *font)
{
    sfText *sensitivityLabel = NULL;

    sensitivityLabel = sfText_create();
    if (!sensitivityLabel)
        return;
    sfText_setFont(sensitivityLabel, font);
    sfText_setString(sensitivityLabel, "Sensitivity:");
    sfText_setCharacterSize(sensitivityLabel, 27);
    sfText_setFillColor(sensitivityLabel, sfWhite);
    sfText_setPosition(sensitivityLabel, (sfVector2f){671, 380});
    sfRenderWindow_drawText(window, sensitivityLabel, NULL);
    sfText_destroy(sensitivityLabel);
}

static void draw_sensitivity_slider_background(sfRenderWindow *window,
    sfVector2f sliderPos, float sliderWidth, float sliderHeight)
{
    sfRectangleShape *sliderBg = NULL;

    sliderBg = sfRectangleShape_create();
    if (!sliderBg)
        return;
    sfRectangleShape_setPosition(sliderBg, sliderPos);
    sfRectangleShape_setSize(sliderBg,
        (sfVector2f){sliderWidth, sliderHeight});
    sfRectangleShape_setFillColor(sliderBg, (sfColor){60, 60, 60, 255});
    sfRectangleShape_setOutlineThickness(sliderBg, 1);
    sfRectangleShape_setOutlineColor(sliderBg, sfWhite);
    sfRenderWindow_drawRectangleShape(window, sliderBg, NULL);
    sfRectangleShape_destroy(sliderBg);
}

static void draw_sensitivity_slider_fill(sfRenderWindow *window,
    sfVector2f sliderPos, sfVector2f sliderSize, float fillRatio)
{
    sfRectangleShape *sliderFill = NULL;

    sliderFill = sfRectangleShape_create();
    if (!sliderFill)
        return;
    sfRectangleShape_setPosition(sliderFill, sliderPos);
    sfRectangleShape_setSize(sliderFill,
        (sfVector2f){sliderSize.x * fillRatio, sliderSize.y});
    sfRectangleShape_setFillColor(sliderFill, sfYellow);
    sfRenderWindow_drawRectangleShape(window, sliderFill, NULL);
    sfRectangleShape_destroy(sliderFill);
}

static void draw_sensitivity_slider(sfRenderWindow *window,
    settings_page_t *settings, sfVector2f position)
{
    float sliderWidth = 250;
    float sliderHeight = 10;
    sfVector2f sliderPos = {position.x, position.y + 150};
    sfVector2f sliderSize = {sliderWidth, sliderHeight};
    float fillRatio;

    if (!window || !settings)
        return;
    draw_sensitivity_slider_background(window, sliderPos,
        sliderWidth, sliderHeight);
    fillRatio = (float)settings->sensitivity / 10.0f;
    draw_sensitivity_slider_fill(window, sliderPos, sliderSize, fillRatio);
}

static void draw_sensitivity_value(sfRenderWindow *window, sfFont *font,
    settings_page_t *settings, sfVector2f position)
{
    sfText *sensitivityValue = NULL;
    char sensitivityStr[10];

    sprintf(sensitivityStr, "%d", settings->sensitivity);
    sensitivityValue = sfText_create();
    if (!sensitivityValue)
        return;
    sfText_setFont(sensitivityValue, font);
    sfText_setString(sensitivityValue, sensitivityStr);
    sfText_setCharacterSize(sensitivityValue, 24);
    sfText_setFillColor(sensitivityValue, sfYellow);
    sfText_setPosition(sensitivityValue, (sfVector2f){
        position.x + 270, position.y + 140
    });
    sfRenderWindow_drawText(window, sensitivityValue, NULL);
    sfText_destroy(sensitivityValue);
}

void draw_sensitivity_arrows(sfRenderWindow *window, sfFont *font,
    settings_page_t *settings, sfVector2f position)
{
    sfText *arrowsText = NULL;

    if (!settings->is_adjusting_sensitivity)
        return;
    arrowsText = sfText_create();
    if (!arrowsText)
        return;
    sfText_setFont(arrowsText, font);
    sfText_setString(arrowsText, "◄     ►");
    sfText_setCharacterSize(arrowsText, 24);
    sfText_setFillColor(arrowsText, sfGreen);
    sfText_setPosition(arrowsText, (sfVector2f){
        position.x + 100, position.y + 80
    });
    sfRenderWindow_drawText(window, arrowsText, NULL);
    sfText_destroy(arrowsText);
}

void draw_adjustment_instructions(sfRenderWindow *window, sfFont *font,
    sfVector2f position)
{
    sfText *instruction = NULL;

    instruction = sfText_create();
    if (!instruction)
        return;
    sfText_setFont(instruction, font);
    sfText_setString(instruction,
        "Press Enter to adjust, then Left/Right arrows");
    sfText_setCharacterSize(instruction, 18);
    sfText_setFillColor(instruction, sfWhite);
    sfText_setPosition(instruction, (sfVector2f){
        position.x + 100, position.y - 80
    });
    sfRenderWindow_drawText(window, instruction, NULL);
    sfText_destroy(instruction);
}

void draw_sensitivity_control(sfRenderWindow *window, sfFont *font,
    settings_page_t *settings, sfVector2f position)
{
    if (!window || !font || !settings)
        return;
    draw_sensitivity_label(window, font);
    draw_sensitivity_slider(window, settings, position);
    draw_sensitivity_value(window, font, settings, position);
    draw_sensitivity_arrows(window, font, settings, position);
    draw_adjustment_instructions(window, font, position);
}

void apply_sensitivity_setting(int sensitivity)
{
    settings_page_t *settings = *get_settings_page();
    player_t *player = *get_player();
    float sensitivity_factor;
    float base_rotation_speed;

    if (sensitivity < 1)
        sensitivity = 1;
    if (sensitivity > 10)
        sensitivity = 10;
    settings->sensitivity = sensitivity;
    base_rotation_speed = 0.05f;
    sensitivity_factor = sensitivity / 5.0f;
    if (player) {
        player->rotation_speed = base_rotation_speed * sensitivity_factor;
    }
}

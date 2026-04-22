/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** video_dropdown.c
*/

#include "../../include/wolf3d.h"

void draw_video_option_item(sfRenderWindow *window, sfFont *font,
    option_style_t style, sfVector2f position)
{
    sfText *optionText = NULL;

    optionText = sfText_create();
    if (!optionText)
        return;
    sfText_setFont(optionText, font);
    sfText_setString(optionText, style.text);
    sfText_setCharacterSize(optionText, 24);
    sfText_setFillColor(optionText, style.isSelected ? sfYellow : sfWhite);
    sfText_setPosition(optionText, position);
    sfRenderWindow_drawText(window, optionText, NULL);
    sfText_destroy(optionText);
}

sfRectangleShape *create_dropdown_rect(float rectLeft, float rectTop,
    float rectWidth, float rectHeight)
{
    sfRectangleShape *optionsRect = NULL;

    optionsRect = sfRectangleShape_create();
    if (!optionsRect)
        return NULL;
    sfRectangleShape_setPosition(optionsRect, (sfVector2f){rectLeft, rectTop});
    sfRectangleShape_setSize(optionsRect, (sfVector2f){rectWidth, rectHeight});
    sfRectangleShape_setFillColor(optionsRect, (sfColor){20, 20, 20, 230});
    sfRectangleShape_setOutlineThickness(optionsRect, 2);
    sfRectangleShape_setOutlineColor(optionsRect, sfWhite);
    return optionsRect;
}

dropdown_positions_t init_dropdown_positions(float left,
    float top, float width)
{
    dropdown_positions_t positions;

    positions.rectLeft = left;
    positions.rectTop = top;
    positions.rectWidth = width;
    return positions;
}

void draw_dropdown_options(sfRenderWindow *window, sfFont *font,
    dropdown_positions_t positions, settings_page_t *settings)
{
    option_style_t style;
    int i = 0;
    const char *option_names[3] =
        {"Windowed", "Fullscreen", "Windowed Fullscreen"};

    for (i = 0; i < 3; i++) {
        style = (option_style_t){option_names[i],
            (i == settings->selected_video_option)};
        draw_video_option_item(window, font, style, (sfVector2f)
            {positions.rectLeft + 40, positions.rectTop + 20 + (i * 40)});
        if (i == settings->selected_video_option) {
            draw_display_arrow(window, font, (sfVector2f)
                {positions.rectLeft + 10, positions.rectTop + 20 + (i * 40)});
        }
    }
    draw_display_checkmark(window, font,
        (sfVector2f){positions.rectLeft + positions.rectWidth - 40,
        positions.rectTop + 20 + (settings->current_display_mode * 40)});
}

void draw_video_dropdown(sfRenderWindow *window, sfFont *font,
    sfVector2f startPos, settings_page_t *settings)
{
    sfRectangleShape *optionsRect = NULL;
    dropdown_positions_t positions;
    float rectWidth = 350.0f;
    float rectHeight = 160.0f;

    positions = init_dropdown_positions(
        startPos.x - 40,
        startPos.y + 140,
        rectWidth
    );
    optionsRect = create_dropdown_rect(positions.rectLeft, positions.rectTop,
        rectWidth, rectHeight);
    if (!optionsRect)
        return;
    sfRenderWindow_drawRectangleShape(window, optionsRect, NULL);
    sfRectangleShape_destroy(optionsRect);
    draw_dropdown_options(window, font, positions, settings);
}

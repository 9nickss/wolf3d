/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** video_fps_dropdown.c
*/

#include "../../include/wolf3d.h"

void draw_fps_option_item(sfRenderWindow *window, sfFont *font,
    option_style_t style, sfVector2f position)
{
    sfText *fpsText = NULL;

    fpsText = sfText_create();
    if (!fpsText)
        return;
    sfText_setFont(fpsText, font);
    sfText_setString(fpsText, style.text);
    sfText_setCharacterSize(fpsText, 24);
    sfText_setFillColor(fpsText, style.isSelected ? sfYellow : sfWhite);
    sfText_setPosition(fpsText, position);
    sfRenderWindow_drawText(window, fpsText, NULL);
    sfText_destroy(fpsText);
}

fps_dropdown_data_t init_fps_dropdown_data(float left, float top, float width,
    const char **options)
{
    fps_dropdown_data_t data;

    data.rectLeft = left;
    data.rectTop = top;
    data.rectWidth = width;
    data.options = options;
    return data;
}

void draw_fps_dropdown_items(sfRenderWindow *window, sfFont *font,
    fps_dropdown_data_t data, settings_page_t *settings)
{
    int i = 0;
    option_style_t style;

    for (i = 0; i < 2; i++) {
        style = (option_style_t){data.options[i],
            i == settings->selected_fps_option};
        draw_fps_option_item(window, font, style,
            (sfVector2f){data.rectLeft + 40, data.rectTop + 20 + (i * 40)});
        if (i == settings->selected_fps_option) {
            draw_selection_arrow(window, font, (sfVector2f){data.rectLeft +
                10, data.rectTop + 20 + (i * 40)});
        }
        if ((i == 0 && settings->current_fps == 30) ||
            (i == 1 && settings->current_fps == 60)) {
            draw_checkmark(window, font, (sfVector2f){data.rectLeft +
                data.rectWidth - 40, data.rectTop + 20 + (i * 40)});
        }
    }
}

sfRectangleShape *create_fps_dropdown_rect(float rectLeft, float rectTop,
    float rectWidth, float rectHeight)
{
    sfRectangleShape *fpsRect = NULL;

    fpsRect = sfRectangleShape_create();
    if (!fpsRect)
        return NULL;
    sfRectangleShape_setPosition(fpsRect, (sfVector2f){rectLeft, rectTop});
    sfRectangleShape_setSize(fpsRect, (sfVector2f){rectWidth, rectHeight});
    sfRectangleShape_setFillColor(fpsRect, (sfColor){20, 20, 20, 230});
    sfRectangleShape_setOutlineThickness(fpsRect, 2);
    sfRectangleShape_setOutlineColor(fpsRect, sfWhite);
    return fpsRect;
}

void draw_fps_dropdown(sfRenderWindow *window, sfFont *font,
    sfVector2f position, settings_page_t *settings)
{
    sfRectangleShape *fpsRect = NULL;
    const char *fps_options[2] = {"30 FPS", "60 FPS"};
    float rectLeft = 0.0f;
    float rectTop = 0.0f;
    float rectWidth = 200.0f;
    float rectHeight = 100.0f;
    fps_dropdown_data_t data;

    rectLeft = position.x - 20;
    rectTop = position.y + 40;
    fpsRect = create_fps_dropdown_rect(rectLeft,
        rectTop, rectWidth, rectHeight);
    if (!fpsRect)
        return;
    sfRenderWindow_drawRectangleShape(window, fpsRect, NULL);
    sfRectangleShape_destroy(fpsRect);
    data = init_fps_dropdown_data(rectLeft, rectTop, rectWidth, fps_options);
    draw_fps_dropdown_items(window, font, data, settings);
}

/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** video_prompt.c
*/

#include "../../include/wolf3d.h"

void draw_prompt_message(sfRenderWindow *window,
    sfFont *font, sfVector2f position)
{
    sfRectangleShape *promptRect = NULL;
    sfText *prompt = NULL;
    sfFloatRect textBounds;
    prompt_message_pos_t pos;

    pos = init_message_positions();
    prompt = create_message_text(font, "Press Enter to change");
    if (!prompt)
        return;
    textBounds = sfText_getLocalBounds(prompt);
    calculate_message_positions(position, textBounds, &pos);
    promptRect = create_message_rect(pos);
    if (!promptRect) {
        sfText_destroy(prompt);
        return;
    }
    render_message(window, prompt, promptRect, pos);
    sfText_destroy(prompt);
    sfRectangleShape_destroy(promptRect);
}

sfText *create_prompt_text(sfFont *font,
    const char *message, sfVector2f position)
{
    sfText *prompt = NULL;

    prompt = sfText_create();
    if (!prompt)
        return NULL;
    sfText_setFont(prompt, font);
    sfText_setString(prompt, message);
    sfText_setCharacterSize(prompt, 18);
    sfText_setFillColor(prompt, sfWhite);
    sfText_setPosition(prompt, position);
    return prompt;
}

sfRectangleShape *create_prompt_rect(sfFloatRect textBounds,
    sfVector2f position, float padding_x, float padding_y)
{
    sfRectangleShape *rect = NULL;
    float rectWidth = 0.0f;
    float rectHeight = 0.0f;

    rect = sfRectangleShape_create();
    if (!rect)
        return NULL;
    rectWidth = textBounds.width + (padding_x * 2);
    rectHeight = textBounds.height + (padding_y * 2);
    sfRectangleShape_setPosition(rect, position);
    sfRectangleShape_setSize(rect, (sfVector2f){rectWidth, rectHeight});
    sfRectangleShape_setFillColor(rect, (sfColor){40, 40, 40, 200});
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    return rect;
}

prompt_positions_t init_prompt_positions(void)
{
    prompt_positions_t positions;

    positions.rectX = 0.0f;
    positions.rectY = 0.0f;
    positions.textX = 0.0f;
    positions.textY = 0.0f;
    return positions;
}

void calculate_prompt_positions(sfVector2f startPos,
    prompt_positions_t *positions)
{
    positions->rectX = startPos.x;
    positions->rectY = startPos.y + 150;
    positions->textX = positions->rectX + 10;
    positions->textY = positions->rectY + 8;
}

/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** video_prompt_message.c
*/

#include "../../include/wolf3d.h"

prompt_message_pos_t init_message_positions(void)
{
    prompt_message_pos_t pos;

    pos.rectX = 0.0f;
    pos.rectY = 0.0f;
    pos.textX = 0.0f;
    pos.textY = 0.0f;
    pos.rectWidth = 0.0f;
    pos.rectHeight = 0.0f;
    return pos;
}

void calculate_message_positions(sfVector2f position, sfFloatRect textBounds,
    prompt_message_pos_t *pos)
{
    pos->rectWidth = textBounds.width + 20;
    pos->rectHeight = textBounds.height + 16;
    pos->rectX = position.x;
    pos->rectY = position.y + 75;
    pos->textX = pos->rectX + 10;
    pos->textY = pos->rectY + 8;
}

sfText *create_message_text(sfFont *font, const char *message)
{
    sfText *prompt = NULL;

    prompt = sfText_create();
    if (!prompt)
        return NULL;
    sfText_setFont(prompt, font);
    sfText_setString(prompt, message);
    sfText_setCharacterSize(prompt, 18);
    sfText_setFillColor(prompt, sfWhite);
    return prompt;
}

sfRectangleShape *create_message_rect(prompt_message_pos_t pos)
{
    sfRectangleShape *promptRect = NULL;

    promptRect = sfRectangleShape_create();
    if (!promptRect)
        return NULL;
    sfRectangleShape_setPosition(promptRect,
        (sfVector2f){pos.rectX, pos.rectY});
    sfRectangleShape_setSize(promptRect,
        (sfVector2f){pos.rectWidth, pos.rectHeight});
    sfRectangleShape_setFillColor(promptRect, (sfColor){40, 40, 40, 200});
    sfRectangleShape_setOutlineThickness(promptRect, 1);
    sfRectangleShape_setOutlineColor(promptRect, sfWhite);
    return promptRect;
}

void render_message(sfRenderWindow *window, sfText *prompt,
    sfRectangleShape *promptRect, prompt_message_pos_t pos)
{
    sfRenderWindow_drawRectangleShape(window, promptRect, NULL);
    sfText_setPosition(prompt, (sfVector2f){pos.textX, pos.textY});
    sfRenderWindow_drawText(window, prompt, NULL);
}

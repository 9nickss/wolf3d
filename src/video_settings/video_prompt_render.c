/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** video_prompt_render.c
*/

#include "../../include/wolf3d.h"

void render_prompt(sfRenderWindow *window, sfText *prompt,
    sfRectangleShape *promptRect, prompt_positions_t positions)
{
    sfRenderWindow_drawRectangleShape(window, promptRect, NULL);
    sfText_setPosition(prompt, (sfVector2f){positions.textX, positions.textY});
    sfRenderWindow_drawText(window, prompt, NULL);
}

bool prepare_prompt_resources(sfFont *font, sfVector2f startPos,
    prompt_resources_t *resources)
{
    sfFloatRect textBounds;

    resources->pos = init_prompt_positions();
    calculate_prompt_positions(startPos, &resources->pos);
    resources->prompt = create_prompt_text(font,
        "Press Enter to expand options",
        (sfVector2f){0, 0});
    if (!resources->prompt)
        return false;
    textBounds = sfText_getLocalBounds(resources->prompt);
    resources->promptRect = create_prompt_rect(textBounds,
        (sfVector2f){resources->pos.rectX, resources->pos.rectY}, 10, 8);
    if (!resources->promptRect) {
        sfText_destroy(resources->prompt);
        return false;
    }
    return true;
}

void draw_display_prompt(sfRenderWindow *window,
    sfFont *font, sfVector2f startPos)
{
    prompt_resources_t resources;

    resources.prompt = NULL;
    resources.promptRect = NULL;
    if (!prepare_prompt_resources(font, startPos, &resources))
        return;
    render_prompt(window, resources.prompt,
        resources.promptRect, resources.pos);
    sfText_destroy(resources.prompt);
    sfRectangleShape_destroy(resources.promptRect);
}

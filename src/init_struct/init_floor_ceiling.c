/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_floor_ceiling
*/

#include "../../include/wolf3d.h"

static void create_floor_quad(sfVertex *floor_quad, int win_width,
    int win_height)
{
    sfColor floor_color = sfColor_fromRGB(80, 80, 80);

    floor_quad[0].position = (sfVector2f){0, win_height / 2};
    floor_quad[0].color = floor_color;
    floor_quad[1].position = (sfVector2f){win_width, win_height / 2};
    floor_quad[1].color = floor_color;
    floor_quad[2].position = (sfVector2f){win_width, win_height};
    floor_quad[2].color = sfColor_fromRGB(40, 40, 40);
    floor_quad[3].position = (sfVector2f){0, win_height};
    floor_quad[3].color = sfColor_fromRGB(40, 40, 40);
}

static void create_ceiling_quad(sfVertex *ceiling_quad, int win_width,
    int win_height)
{
    sfColor ceiling_color = sfColor_fromRGB(180, 180, 180);

    ceiling_quad[0].position = (sfVector2f){0, 0};
    ceiling_quad[0].color = sfColor_fromRGB(100, 100, 140);
    ceiling_quad[1].position = (sfVector2f){win_width, 0};
    ceiling_quad[1].color = sfColor_fromRGB(100, 100, 140);
    ceiling_quad[2].position = (sfVector2f){win_width, win_height / 2};
    ceiling_quad[2].color = ceiling_color;
    ceiling_quad[3].position = (sfVector2f){0, win_height / 2};
    ceiling_quad[3].color = ceiling_color;
}

sfVertexArray *init_floor(void)
{
    sfRenderWindow *window = *get_window();
    sfVertexArray *floor = sfVertexArray_create();
    int win_width = WIN_WIDTH(window);
    int win_height = WIN_HEIGHT(window);
    sfVertex floor_quad[4];

    if (!floor)
        return NULL;
    sfVertexArray_setPrimitiveType(floor, sfQuads);
    create_floor_quad(floor_quad, win_width, win_height);
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(floor, floor_quad[i]);
    return floor;
}

sfVertexArray *get_floor(void)
{
    static sfVertexArray *floor = NULL;

    if (floor == NULL)
        floor = init_floor();
    return floor;
}

sfVertexArray *init_ceiling(void)
{
    sfRenderWindow *window = *get_window();
    sfVertexArray *ceiling = sfVertexArray_create();
    int win_width = WIN_WIDTH(window);
    int win_height = WIN_HEIGHT(window);
    sfVertex ceiling_quad[4];

    if (!ceiling)
        return NULL;
    sfVertexArray_setPrimitiveType(ceiling, sfQuads);
    create_ceiling_quad(ceiling_quad, win_width, win_height);
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(ceiling, ceiling_quad[i]);
    return ceiling;
}

sfVertexArray *get_ceiling(void)
{
    static sfVertexArray *ceiling = NULL;

    if (ceiling == NULL)
        ceiling = init_ceiling();
    return ceiling;
}

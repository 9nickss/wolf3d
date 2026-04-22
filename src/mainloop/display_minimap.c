/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** display_minimap
*/

#include "../../include/wolf3d.h"

void create_case_map(sfRectangleShape *rect, int x, int y)
{
    sfRenderWindow *window = *get_window();
    sfVector2f coord = (sfVector2f){WIN_WIDTH(window) - MINIMAP_SIZE +
        (x * (MINIMAP_SIZE / MAP_SIZE)), y * (MINIMAP_SIZE / MAP_SIZE)};
    int **map = *get_map();

    sfRectangleShape_setPosition(rect, coord);
    if (map[y][x] == 1)
        sfRectangleShape_setFillColor(rect, (sfColor){0, 0, 0, 0});
    else
        sfRectangleShape_setFillColor(rect, sfWhite);
}

void draw_2d_map(void)
{
    sfRenderWindow *window = *get_window();
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, (sfVector2f){MINIMAP_SIZE / MAP_SIZE,
        MINIMAP_SIZE / MAP_SIZE});
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            create_case_map(rect, x, y);
            sfRenderWindow_drawRectangleShape(window, rect, NULL);
        }
    }
    sfRectangleShape_destroy(rect);
}

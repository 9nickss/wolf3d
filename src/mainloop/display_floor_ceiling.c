/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** display_floor_ceiling
*/

#include "../../include/wolf3d.h"

int is_wall(int x, int y)
{
    int **map = *get_map();
    int map_x = x / TILE_SIZE;
    int map_y = y / TILE_SIZE;

    if (map_x < 0 || map_y < 0 || map_x >= MAP_SIZE || map_y >= MAP_SIZE)
        return 1;
    return map[map_y][map_x];
}

void draw_floor_and_ceiling(sfRenderWindow *window)
{
    sfVertexArray *floor_vertices = get_floor();
    sfVertexArray *ceiling_vertices = get_ceiling();

    sfRenderWindow_drawVertexArray(window, floor_vertices, NULL);
    sfRenderWindow_drawVertexArray(window, ceiling_vertices, NULL);
}

/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** ray_rendering.c - Main ray rendering functions
*/

#include "../../include/wolf3d.h"

void process_single_ray_column(sfVertexArray *wall_vertices,
    ray_column_params_t params, sfRenderWindow *window)
{
    float ray_angle = params.start_angle +
        params.column * params.ray_angle_step;
    int hit_side;
    sfVertex quad[4];
    wall_rect_t rect;
    sfColor wall_color;

    rect = calculate_wall_dimensions(params, window, &hit_side);
    wall_color = calculate_wall_color(hit_side, ray_angle,
        (TILE_SIZE * WIN_WIDTH(window)) / (2 * rect.bottom - rect.top));
    create_wall_quad(quad, rect, wall_color);
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(wall_vertices, quad[i]);
}

void cast_all_rays(void)
{
    sfRenderWindow *window = *get_window();
    player_t *player = *get_player();
    sfVertexArray *wall_vertices = sfVertexArray_create();
    float ray_angle_step = FOV / NUM_RAYS(window);
    float start_angle = player->angle - FOV / 2;
    float column_width = (float)WIN_WIDTH(window) / (float)NUM_RAYS(window);
    ray_column_params_t params;

    sfVertexArray_setPrimitiveType(wall_vertices, sfQuads);
    draw_floor_and_ceiling(window);
    params.start_angle = start_angle;
    params.ray_angle_step = ray_angle_step;
    params.column_width = column_width;
    for (int column = 0; column < (int)NUM_RAYS(window); column++) {
        params.column = column;
        process_single_ray_column(wall_vertices, params, window);
    }
    sfRenderWindow_drawVertexArray(window, wall_vertices, NULL);
    sfVertexArray_destroy(wall_vertices);
}

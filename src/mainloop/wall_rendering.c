/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** wall_rendering.c - Wall coloring and drawing
*/

#include "../../include/wolf3d.h"

sfColor get_wall_base_color(int hit_side, float ray_angle)
{
    if (hit_side == 0) {
        if (ray_angle > M_PI / 2 && ray_angle < 3 * M_PI / 2)
            return (sfColor){1, 0, 0, 255};
        else
            return (sfColor){0, 0, 1, 255};
    } else {
        if (ray_angle > 0 && ray_angle < M_PI)
            return (sfColor){0, 1, 0, 255};
        else
            return (sfColor){1, 1, 0, 255};
    }
}

sfColor apply_brightness_and_side_dimming(sfColor base_color,
    float brightness, int hit_side)
{
    int color_r = (int)(brightness * base_color.r * 255);
    int color_g = (int)(brightness * base_color.g * 255);
    int color_b = (int)(brightness * base_color.b * 255);
    sfColor wall_color = sfColor_fromRGB(color_r, color_g, color_b);

    if (hit_side == 1) {
        wall_color.r = (sfUint8)(wall_color.r * 0.7f);
        wall_color.g = (sfUint8)(wall_color.g * 0.7f);
        wall_color.b = (sfUint8)(wall_color.b * 0.7f);
    }
    return wall_color;
}

sfColor calculate_wall_color(int hit_side, float ray_angle,
    float corrected_dist)
{
    float brightness = fmax(0.3f, fmin(1.0f,
        1.0f - corrected_dist / (TILE_SIZE * 5)));
    sfColor base_color = get_wall_base_color(hit_side, ray_angle);

    return apply_brightness_and_side_dimming(base_color, brightness, hit_side);
}

void create_wall_quad(sfVertex *quad, wall_rect_t rect,
    sfColor wall_color)
{
    quad[0].position = (sfVector2f){rect.x, rect.top};
    quad[0].color = wall_color;
    quad[1].position = (sfVector2f){rect.x + rect.width, rect.top};
    quad[1].color = wall_color;
    quad[2].position = (sfVector2f){rect.x + rect.width, rect.bottom};
    quad[2].color = wall_color;
    quad[3].position = (sfVector2f){rect.x, rect.bottom};
    quad[3].color = wall_color;
}

wall_rect_t calculate_wall_dimensions(ray_column_params_t params,
    sfRenderWindow *window, int *hit_side)
{
    float ray_angle;
    int map_x;
    int map_y;
    float corrected_dist;
    wall_rect_t rect;
    float wall_height;
    float column_height;

    ray_angle = params.start_angle + params.column * params.ray_angle_step;
    corrected_dist = cast_single_ray(ray_angle, hit_side, &map_x, &map_y);
    corrected_dist = fmax(corrected_dist, 0.001f);
    wall_height = (TILE_SIZE / corrected_dist) * (WIN_WIDTH(window) / 2);
    column_height = fmin(wall_height, WIN_HEIGHT(window) * 4);
    rect.x = params.column * params.column_width;
    rect.width = params.column_width;
    rect.top = (WIN_HEIGHT(window) - column_height) / 2;
    rect.bottom = rect.top + column_height;
    return rect;
}

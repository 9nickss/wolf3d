/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** ray_casting_algorithm.c - DDA algorithm for ray casting
*/

#include "../../include/wolf3d.h"

void init_dda_params(float ray_angle, ray_position_t position,
    dda_cell_t *cell, dda_step_t *step)
{
    float sin_angle = sin(ray_angle);
    float cos_angle = cos(ray_angle);
    float delta_dist_x;
    float delta_dist_y;
    ray_outputs_t outputs;

    calculate_delta_distances(sin_angle, cos_angle,
        &delta_dist_x, &delta_dist_y);
    setup_ray_parameters(ray_angle, position, &outputs);
    cell->x = (int)position.x;
    cell->y = (int)position.y;
    cell->side_dist_x = outputs.side_dist_x;
    cell->side_dist_y = outputs.side_dist_y;
    step->step_x = outputs.step_x;
    step->step_y = outputs.step_y;
    step->delta_dist_x = delta_dist_x;
    step->delta_dist_y = delta_dist_y;
}

float run_dda_loop(dda_cell_t *cell, dda_step_t step,
    int *side, int *hit_wall)
{
    float max_distance = TILE_SIZE * 20;
    float distance = 0.0f;
    int hit = 0;

    while (!hit && distance < max_distance) {
        perform_dda_step(cell, step, side, &distance);
        if (is_wall(cell->x, cell->y))
            hit = 1;
    }
    *hit_wall = hit;
    return distance;
}

float perform_dda_algorithm(dda_result_t *result,
    float ray_angle, ray_position_t position)
{
    dda_cell_t cell;
    dda_step_t step;
    int hit_wall;
    float distance;

    init_dda_params(ray_angle, position, &cell, &step);
    distance = run_dda_loop(&cell, step, &result->hit_side, &hit_wall);
    result->map_x = cell.x;
    result->map_y = cell.y;
    return distance;
}

float cast_single_ray(float ray_angle, int *hit_side, int *map_x, int *map_y)
{
    player_t *player = *get_player();
    ray_position_t position = {player->pos.x, player->pos.y};
    dda_result_t result;
    float perp_wall_dist;

    ray_angle = fmod(ray_angle, 2 * M_PI);
    if (ray_angle < 0)
        ray_angle += 2 * M_PI;
    perp_wall_dist = perform_dda_algorithm(&result, ray_angle, position);
    *hit_side = result.hit_side;
    *map_x = result.map_x;
    *map_y = result.map_y;
    return calculate_corrected_distance(perp_wall_dist, ray_angle);
}

float calculate_wall_x(int side, float ray_angle, float distance)
{
    player_t *player = *get_player();
    float wall_x;

    if (side == 0)
        wall_x = player->pos.y + distance * sin(ray_angle);
    else
        wall_x = player->pos.x + distance * cos(ray_angle);
    wall_x -= floor(wall_x);
    return wall_x;
}

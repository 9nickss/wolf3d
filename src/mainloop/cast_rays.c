/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** ray_casting_core.c - Core ray casting functionality
*/

#include "../../include/wolf3d.h"

float calculate_corrected_distance(float wall_dist, float ray_angle)
{
    player_t *player = *get_player();

    return wall_dist * cos(ray_angle - player->angle);
}

void calculate_delta_distances(float sin_angle, float cos_angle,
    float *delta_dist_x, float *delta_dist_y)
{
    if (cos_angle == 0)
        *delta_dist_x = 1e30;
    else
        *delta_dist_x = fabs(1 / cos_angle);
    if (sin_angle == 0)
        *delta_dist_y = 1e30;
    else
        *delta_dist_y = fabs(1 / sin_angle);
}

void setup_step_and_side_dist(ray_inputs_t inputs,
    ray_outputs_t *outputs)
{
    int cell_x = (int)inputs.pos_x;
    int cell_y = (int)inputs.pos_y;

    if (inputs.cos_angle < 0) {
        outputs->step_x = -1;
        outputs->side_dist_x = (inputs.pos_x - cell_x) * inputs.delta_dist_x;
    } else {
        outputs->step_x = 1;
        outputs->side_dist_x = (cell_x + 1.0 - inputs.pos_x) *
            inputs.delta_dist_x;
    }
    if (inputs.sin_angle < 0) {
        outputs->step_y = -1;
        outputs->side_dist_y = (inputs.pos_y - cell_y) * inputs.delta_dist_y;
    } else {
        outputs->step_y = 1;
        outputs->side_dist_y = (cell_y + 1.0 - inputs.pos_y) *
            inputs.delta_dist_y;
    }
}

void setup_ray_parameters(float ray_angle, ray_position_t position,
    ray_outputs_t *outputs)
{
    float sin_angle = sin(ray_angle);
    float cos_angle = cos(ray_angle);
    float delta_dist_x;
    float delta_dist_y;
    ray_inputs_t inputs;

    calculate_delta_distances(sin_angle,
        cos_angle, &delta_dist_x, &delta_dist_y);
    inputs.pos_x = position.x;
    inputs.pos_y = position.y;
    inputs.cos_angle = cos_angle;
    inputs.sin_angle = sin_angle;
    inputs.delta_dist_x = delta_dist_x;
    inputs.delta_dist_y = delta_dist_y;
    setup_step_and_side_dist(inputs, outputs);
}

void perform_dda_step(dda_cell_t *cell, dda_step_t step,
    int *side, float *distance)
{
    if (cell->side_dist_x < cell->side_dist_y) {
        cell->side_dist_x += step.delta_dist_x;
        cell->x += step.step_x;
        *side = 0;
        *distance = cell->side_dist_x - step.delta_dist_x;
    } else {
        cell->side_dist_y += step.delta_dist_y;
        cell->y += step.step_y;
        *side = 1;
        *distance = cell->side_dist_y - step.delta_dist_y;
    }
}

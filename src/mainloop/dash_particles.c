/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** dash_particles.c
*/

#include "../../include/wolf3d.h"

void add_particle(sfVector2f pos)
{
    player_t *player = *get_player();
    particle_t *new_particle = malloc(sizeof(particle_t));
    
    if (!new_particle)
        return;
    
    // Randomize particle properties
    float angle = ((rand() % 628) / 100.0f); // Random angle in radians
    float speed = (rand() % 50) / 100.0f + 0.1f; // Random speed between 0.1 and 0.6
    
    new_particle->position = pos;
    new_particle->velocity.x = cosf(angle) * speed;
    new_particle->velocity.y = sinf(angle) * speed;
    new_particle->lifetime = 0.0f;
    new_particle->max_lifetime = (rand() % 50) / 100.0f + 0.5f; // 0.5 to 1.0 seconds
    new_particle->size = (rand() % 30) / 10.0f + 2.0f; // 2.0 to 5.0 pixels
    new_particle->color = sfColor_fromRGBA(255, 255, 255, 255);
    
    // Add to linked list
    new_particle->next = player->particles;
    player->particles = new_particle;
}

void create_dash_trail(void)
{
    player_t *player = *get_player();
    static sfVector2f last_pos = {0, 0};
    static sfClock *trail_clock = NULL;
    float distance;
    
    if (!trail_clock)
        trail_clock = sfClock_create();
    
    // Only spawn particles during dash
    if (!player->is_dashing)
        return;
    
    // Calculate distance moved since last particle
    distance = sqrt(pow(player->pos.x - last_pos.x, 2) + 
        pow(player->pos.y - last_pos.y, 2));
    
    // Only create new particles if moved enough or first time
    if (distance > 0.2f || (last_pos.x == 0 && last_pos.y == 0)) {
        // Create particles at current position (which is behind where you're going)
        for (int i = 0; i < 3; i++) {
            add_particle(player->pos);
        }
        last_pos = player->pos;
    }
    
    // Reset last_pos when dash ends
    if (!player->is_dashing) {
        last_pos = (sfVector2f){0, 0};
    }
}

void update_particles(void)
{
    player_t *player = *get_player();
    particle_t *current = player->particles;
    particle_t *prev = NULL;
    float delta_time = 0.016f; // Roughly 60FPS
    
    while (current != NULL) {
        // Update lifetime
        current->lifetime += delta_time;
        
        // Update position
        current->position.x += current->velocity.x;
        current->position.y += current->velocity.y;
        
        // Update color (fade out)
        float fade = 1.0f - (current->lifetime / current->max_lifetime);
        current->color.a = (sfUint8)(255 * fade);
        
        // Remove expired particles
        if (current->lifetime >= current->max_lifetime) {
            particle_t *to_remove = current;
            
            if (prev == NULL) {
                player->particles = current->next;
                current = player->particles;
            } else {
                prev->next = current->next;
                current = prev->next;
            }
            
            free(to_remove);
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    // Generate particles during dash
    if (player->is_dashing) {
        // Spawn 3 particles per frame during dash
        for (int i = 0; i < 3; i++) {
            sfVector2f pos = {
                player->pos.x,
                player->pos.y
            };
            add_particle(pos);
        }
    }
    create_dash_trail();
}

void draw_particles(void)
{
    player_t *player = *get_player();
    particle_t *current = player->particles;
    sfRenderWindow *window = *get_window();
    
    while (current != NULL) {
        // Calculate position relative to player
        float rel_x = current->position.x - player->pos.x;
        float rel_y = current->position.y - player->pos.y;
        
        // Transform to player space
        float transformed_x = rel_x * cos(-player->angle) - rel_y * sin(-player->angle);
        float transformed_y = rel_x * sin(-player->angle) + rel_y * cos(-player->angle);
        
        // Only draw if in front of player (depth check)
        if (transformed_y > 0.1f) {
            float distance = sqrt(transformed_x * transformed_x + transformed_y * transformed_y);
            
            // Perspective projection
            float screen_width = sfRenderWindow_getSize(window).x;
            float screen_height = sfRenderWindow_getSize(window).y;
            
            float screen_x = (transformed_x / transformed_y) * (screen_width / 2) + (screen_width / 2);
            float screen_y = (screen_height / 2) - (player->fov / distance * 20);
            
            // Scale size based on distance
            float size_factor = 8.0f / distance;
            if (size_factor > 10.0f) size_factor = 10.0f;
            
            // Draw particle
            sfCircleShape *circle = sfCircleShape_create();
            sfCircleShape_setRadius(circle, current->size * size_factor);
            sfCircleShape_setPosition(circle, (sfVector2f){screen_x, screen_y});
            sfCircleShape_setFillColor(circle, current->color);
            sfCircleShape_setOrigin(circle, (sfVector2f){current->size * size_factor, current->size * size_factor});
            
            sfRenderWindow_drawCircleShape(window, circle, NULL);
            sfCircleShape_destroy(circle);
        }
        
        current = current->next;
    }
}

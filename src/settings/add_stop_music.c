/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** add_stop_music.c
*/

#include "../../include/wolf3d.h"

void play_background_music(void)
{
    settings_page_t *settings = *get_settings_page();

    if (settings && settings->background_music) {
        if (sfMusic_getStatus(settings->background_music) != sfPlaying) {
            sfMusic_play(settings->background_music);
        }
    }
}

void stop_background_music(void)
{
    settings_page_t *settings = *get_settings_page();

    if (settings && settings->background_music) {
        sfMusic_stop(settings->background_music);
    }
}

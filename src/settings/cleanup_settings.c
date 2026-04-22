/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** cleanup_settings
*/

#include "../../include/wolf3d.h"

void free_settings_resources(void)
{
    settings_page_t *settings = *get_settings_page();

    if (!settings)
        return;
    if (settings->tab_change_sound)
        sfSound_destroy(settings->tab_change_sound);
    if (settings->tab_sound_buffer)
        sfSoundBuffer_destroy(settings->tab_sound_buffer);
    if (settings->background_music) {
        sfMusic_stop(settings->background_music);
        sfMusic_destroy(settings->background_music);
    }
}

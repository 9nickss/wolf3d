/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_settings
*/

#include "../../include/wolf3d.h"

settings_page_t **get_settings_page(void)
{
    static settings_page_t *settings = NULL;

    if (settings == NULL) {
        settings = malloc(sizeof(settings_page_t));
        if (!settings)
            return NULL;
        settings->current_page = GAME;
    }
    return &settings;
}

static void init_settings_pointers(settings_page_t *settings)
{
    settings->all = NULL;
    settings->game = NULL;
    settings->controle = NULL;
    settings->video = NULL;
    settings->audio = NULL;
    settings->tab_change_sound = NULL;
    settings->tab_sound_buffer = NULL;
}

static int load_settings_sprites(settings_page_t *settings)
{
    settings->all = get_sprite("assets/settings/settings.jpg");
    settings->game = get_sprite("assets/settings/settingsbg.png");
    settings->controle = get_sprite("assets/settings/settingsbg.png");
    settings->video = get_sprite("assets/settings/settingsbg.png");
    settings->audio = get_sprite("assets/settings/settingsbg.png");
    if (!settings->all || !settings->game || !settings->controle ||
        !settings->video || !settings->audio)
        return 84;
    return 0;
}

static void init_control_options(settings_page_t *settings)
{
    settings->selected_keybind = -1;
    settings->rebinding_active = false;
    settings->sensitivity = 5;
    settings->is_adjusting_sensitivity = false;
}

static void init_video_options(settings_page_t *settings)
{
    settings->current_display_mode = WINDOWED;
    settings->selected_video_option = -1;
    settings->current_fps = 60;
    settings->is_selecting_fps = false;
    settings->selected_fps_option = 1;
}

static void init_audio_options(settings_page_t *settings)
{
    settings->master_volume = 50;
    settings->is_adjusting_volume = false;
    settings->music_volume = 50;
    settings->is_adjusting_music = false;
    settings->selected_audio_option = 0;
}

static int init_sounds(settings_page_t *settings)
{
    settings->tab_sound_buffer = sfSoundBuffer_createFromFile(
        "sounds_effects/settings.wav");
    settings->tab_change_sound = sfSound_create();
    if (settings->tab_sound_buffer && settings->tab_change_sound) {
        sfSound_setBuffer(settings->tab_change_sound,
            settings->tab_sound_buffer);
        sfSound_setVolume(settings->tab_change_sound, 20.0f);
    }
    return 0;
}

static void init_music(settings_page_t *settings)
{
    float actual_volume;

    settings->background_music = sfMusic_createFromFile(
        "music_theme/ghostsaber.ogg");
    if (settings->background_music) {
        sfMusic_setLoop(settings->background_music, sfTrue);
        actual_volume = (float)settings->master_volume *
                        (float)settings->music_volume / 100.0f;
        sfMusic_setVolume(settings->background_music, actual_volume);
    }
}

static void setup_sprites(settings_page_t *settings)
{
    sfVector2f position = {0, 0};
    sfVector2f scale = {1, 1};

    set_sprite(true, settings->all, position, scale);
    set_sprite(true, settings->game, position, scale);
    set_sprite(true, settings->controle, position, scale);
    set_sprite(true, settings->video, position, scale);
    set_sprite(true, settings->audio, position, scale);
}

int init_settings(void)
{
    settings_page_t *settings = *get_settings_page();
    int status;

    if (!settings)
        return 84;
    init_settings_pointers(settings);
    status = load_settings_sprites(settings);
    if (status != 0)
        return status;
    init_control_options(settings);
    init_video_options(settings);
    init_audio_options(settings);
    init_sounds(settings);
    init_music(settings);
    setup_sprites(settings);
    return 0;
}

/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** audio_settings.c - Main audio settings UI
*/

#include "../../include/wolf3d.h"

static int setup_audio_resources(settings_page_t **settings, sfFont **font,
    sfVector2f *bgPos, sfVector2f *startPos)
{
    sfVector2u textureSize;

    *settings = *get_settings_page();
    *font = sfFont_createFromFile("fonts/ghost.otf");
    if (!*font)
        *font = sfFont_createFromFile("assets/fonts/ghost.otf");
    if (!*font || !*settings || !(*settings)->audio)
        return 0;
    *bgPos = sfSprite_getPosition((*settings)->audio->sprite);
    textureSize = sfTexture_getSize(
        sfSprite_getTexture((*settings)->audio->sprite));
    startPos->x = bgPos->x + textureSize.x * 0.25f;
    startPos->y = bgPos->y + 180;
    return 1;
}

static void draw_audio_title(sfRenderWindow *window, sfFont *font,
    sfVector2f bgPos, sfVector2u textureSize)
{
    sfText *title = sfText_create();
    sfFloatRect titleBounds;

    if (!title)
        return;
    sfText_setFont(title, font);
    sfText_setString(title, "AUDIO SETTINGS");
    sfText_setCharacterSize(title, 36);
    sfText_setFillColor(title, sfWhite);
    titleBounds = sfText_getLocalBounds(title);
    sfText_setPosition(title, (sfVector2f){
        bgPos.x + textureSize.x / 2 - titleBounds.width / 2,
        bgPos.y + 50
    });
    sfRenderWindow_drawText(window, title, NULL);
    sfText_destroy(title);
}

static sfSprite *create_helmet_sprite(sfTexture **helmetTexture)
{
    sfSprite *helmetSprite = NULL;

    *helmetTexture = sfTexture_createFromFile("assets/helmet.png", NULL);
    if (!*helmetTexture)
        return NULL;
    helmetSprite = sfSprite_create();
    if (!helmetSprite) {
        sfTexture_destroy(*helmetTexture);
        *helmetTexture = NULL;
        return NULL;
    }
    sfSprite_setTexture(helmetSprite, *helmetTexture, sfTrue);
    sfSprite_setScale(helmetSprite, (sfVector2f){0.1f, 0.1f});
    return helmetSprite;
}

static void draw_selection_helmet(sfRenderWindow *window,
    settings_page_t *settings, sfVector2f startPos)
{
    sfTexture *helmetTexture = NULL;
    sfSprite *helmetSprite = NULL;
    sfVector2f position;

    helmetSprite = create_helmet_sprite(&helmetTexture);
    if (!helmetSprite)
        return;
    position.x = startPos.x - 40;
    position.y = startPos.y +
        (settings->selected_audio_option == 0 ? 100 : 200);
    sfSprite_setPosition(helmetSprite, position);
    sfRenderWindow_drawSprite(window, helmetSprite, NULL);
    sfSprite_destroy(helmetSprite);
    sfTexture_destroy(helmetTexture);
}

static void draw_volume_slider(sfRenderWindow *window, sfVector2f position,
    int volume)
{
    float sliderWidth = 250;
    float sliderHeight = 10;
    float fillRatio = (float)volume / 100.0f;
    slider_size_t sliderSize = {sliderWidth, sliderHeight};

    draw_volume_slider_background(window, position, sliderWidth, sliderHeight);
    draw_volume_slider_fill(window, position, sliderSize, fillRatio);
}

void draw_audio_settings(sfRenderWindow *window)
{
    settings_page_t *settings;
    sfFont *font;
    sfVector2f bgPos;
    sfVector2f startPos;
    sfVector2u textureSize;

    if (!setup_audio_resources(&settings, &font, &bgPos, &startPos))
        return;
    textureSize = sfTexture_getSize(
        sfSprite_getTexture(settings->audio->sprite));
    draw_audio_title(window, font, bgPos, textureSize);
    draw_selection_helmet(window, settings, startPos);
    draw_volume_control(window, font, settings, startPos);
    draw_music_control(window, font, settings, startPos);
    sfFont_destroy(font);
}

void draw_volume_control(sfRenderWindow *window, sfFont *font,
    settings_page_t *settings, sfVector2f position)
{
    if (!window || !font || !settings)
        return;
    draw_master_volume_label(window, font);
    draw_volume_slider(window, position, settings->master_volume);
    draw_master_volume_value(window, font, position, settings->master_volume);
    draw_volume_adjustment_arrows(window, font, position,
        settings->is_adjusting_volume);
    draw_volume_instructions(window, font, position);
}

void draw_music_control(sfRenderWindow *window, sfFont *font,
    settings_page_t *settings, sfVector2f position)
{
    float sliderWidth = 250;
    float sliderHeight = 10;
    float fillRatio = (float)settings->music_volume / 100.0f;
    slider_size_t sliderSize = {sliderWidth, sliderHeight};

    draw_music_label(window, font, position);
    draw_slider_background(window, position, sliderWidth, sliderHeight);
    draw_slider_fill(window, position, sliderSize, fillRatio);
    draw_volume_text(window, font, position, settings->music_volume);
    draw_adjustment_arrows(window, font, position,
        settings->is_adjusting_music);
}

void apply_volume_setting(int volume)
{
    settings_page_t *settings = *get_settings_page();
    float actual_volume;

    if (volume < 0)
        volume = 0;
    if (volume > 100)
        volume = 100;
    settings->master_volume = volume;
    if (settings->tab_change_sound) {
        sfSound_setVolume(settings->tab_change_sound, volume);
    }
    if (settings->background_music) {
        actual_volume = (float)settings->master_volume *
            (float)settings->music_volume / 100.0f;
        sfMusic_setVolume(settings->background_music, actual_volume);
    }
}

void apply_music_volume(int volume)
{
    settings_page_t *settings = *get_settings_page();
    float actual_volume;

    if (volume < 0)
        volume = 0;
    if (volume > 100)
        volume = 100;
    settings->music_volume = volume;
    if (settings->background_music) {
        actual_volume = (float)settings->master_volume *
            (float)settings->music_volume / 100.0f;
        sfMusic_setVolume(settings->background_music, actual_volume);
    }
}

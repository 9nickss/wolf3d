/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** display_settings - Tab display and main settings display
*/

#include "../../include/wolf3d.h"

static sfFont *load_settings_font(void)
{
    sfFont *font = NULL;

    font = sfFont_createFromFile("fonts/ghost.otf");
    if (!font)
        font = sfFont_createFromFile("assets/fonts/ghost.otf");
    return font;
}

static void draw_single_tab(sfRenderWindow *window, const char *title,
    sfVector2f position, tab_style_t style)
{
    sfText *tabText = NULL;
    sfFloatRect textRect;

    tabText = sfText_create();
    if (!tabText)
        return;
    sfText_setFont(tabText, style.font);
    sfText_setString(tabText, title);
    sfText_setCharacterSize(tabText, 30);
    sfText_setFillColor(tabText, style.is_active ? sfYellow : sfWhite);
    textRect = sfText_getLocalBounds(tabText);
    sfText_setOrigin(tabText, (sfVector2f){textRect.width / 2, 0});
    sfText_setPosition(tabText, position);
    sfRenderWindow_drawText(window, tabText, NULL);
    sfText_destroy(tabText);
}

static void validate_settings_page(settings_page_t *settings)
{
    if (!settings)
        return;
    if (settings->current_page < GAME || settings->current_page > AUDIO)
        settings->current_page = GAME;
}

static void draw_all_tabs(sfRenderWindow *window, settings_page_t *settings,
    sfFont *font, sfVector2f tab_dimensions)
{
    const char *titles[] = {"GAME", "CONTROLS", "VIDEO", "AUDIO"};
    float xPosition;
    sfVector2f position;
    tab_style_t style;

    style.font = font;
    for (int i = 0; i < 4; i++) {
        xPosition = (i * tab_dimensions.x) + (tab_dimensions.x / 2);
        position.x = xPosition;
        position.y = tab_dimensions.y;
        style.is_active = (i == (int)settings->current_page);
        draw_single_tab(window, titles[i], position, style);
    }
}

void draw_settings_tabs(void)
{
    sfRenderWindow *window = *get_window();
    settings_page_t *settings = *get_settings_page();
    sfVector2f tab_dimensions;
    sfFont *font = NULL;

    if (!window || !settings)
        return;
    font = load_settings_font();
    if (!font)
        return;
    validate_settings_page(settings);
    tab_dimensions.x = WIN_WIDTH(window) / 4.0f;
    tab_dimensions.y = 30.0f;
    draw_all_tabs(window, settings, font, tab_dimensions);
    sfFont_destroy(font);
}

static void prepare_settings_background(sfRenderWindow *window,
    settings_page_t *settings)
{
    if (!settings || !window)
        return;
    sfRenderWindow_clear(window, (sfColor){0, 0, 0, 255});
    sfSprite_setColor(settings->all->sprite, (sfColor){255, 255, 255, 100});
    sfRenderWindow_drawSprite(window, settings->all->sprite, NULL);
}

void display_settings(void)
{
    sfRenderWindow *window = *get_window();
    settings_page_t *settings = *get_settings_page();
    sprite_t *current = NULL;

    if (!settings || !window)
        return;
    prepare_settings_background(window, settings);
    current = get_current_page_sprite(settings);
    if (current) {
        draw_page_sprite(window, current);
        draw_current_page_content(window, settings);
    }
    draw_settings_tabs();
    sfRenderWindow_display(window);
}

/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** controls_ui.c - UI elements for control settings
*/

#include "../../include/wolf3d.h"

static sfFont *load_controls_font(void)
{
    sfFont *font = sfFont_createFromFile("fonts/ghost.otf");

    if (!font)
        font = sfFont_createFromFile("assets/fonts/ghost.otf");
    return font;
}

static void draw_controls_title(sfRenderWindow *window, sfFont *font,
    sfVector2f bgPos, sfVector2u textureSize)
{
    sfText *title = sfText_create();
    sfFloatRect titleBounds;

    if (!title)
        return;
    sfText_setFont(title, font);
    sfText_setString(title, "CONTROLS SETTINGS");
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

static void draw_controls_instructions(sfRenderWindow *window, sfFont *font,
    sfVector2f bgPos, sfVector2u textureSize)
{
    sfText *instructions = sfText_create();
    sfFloatRect instrBounds;

    if (!instructions)
        return;
    sfText_setFont(instructions, font);
    sfText_setString(instructions, "Press Up/Down to select, Enter to rebind");
    sfText_setCharacterSize(instructions, 18);
    sfText_setFillColor(instructions, sfWhite);
    instrBounds = sfText_getLocalBounds(instructions);
    sfText_setPosition(instructions, (sfVector2f){
        bgPos.x + textureSize.x / 2 - instrBounds.width / 2,
        bgPos.y + 100
    });
    sfRenderWindow_drawText(window, instructions, NULL);
    sfText_destroy(instructions);
}

static int setup_controls_resources(keybinds_t **keybinds,
    settings_page_t **settings, sfFont **font, controls_ui_layout_t *layout)
{
    *keybinds = get_keybinds();
    *settings = *get_settings_page();
    *font = load_controls_font();
    if (!*font || !*keybinds || !*settings || !(*settings)->controle)
        return 0;
    layout->bgPos = sfSprite_getPosition((*settings)->controle->sprite);
    layout->textureSize = sfTexture_getSize(
        sfSprite_getTexture((*settings)->controle->sprite));
    layout->startPos.x = layout->bgPos.x + layout->textureSize.x * 0.25f;
    layout->startPos.y = layout->bgPos.y + 150;
    return 1;
}

void draw_controls_settings(sfRenderWindow *window)
{
    keybinds_t *keybinds;
    settings_page_t *settings;
    sfFont *font;
    controls_ui_layout_t layout;

    if (!setup_controls_resources(&keybinds, &settings, &font, &layout))
        return;
    draw_controls_title(window, font, layout.bgPos, layout.textureSize);
    draw_controls_instructions(window, font, layout.bgPos, layout.textureSize);
    draw_all_keybinds(window, font, settings, layout.startPos);
    draw_rotation_keybinds(window, font, settings, layout.startPos);
    sfFont_destroy(font);
}

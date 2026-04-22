/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** keybind_ui.c - UI elements for keybind display
*/

#include "../../include/wolf3d.h"

static const char *sfKey_strings[] = {
    "Unknown", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
    "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "Num0",
    "Num1", "Num2", "Num3", "Num4", "Num5", "Num6", "Num7", "Num8", "Num9",
    "Escape", "LControl", "LShift", "LAlt", "LSystem", "RControl", "RShift",
    "RAlt", "RSystem", "Menu", "LBracket", "RBracket", "Semicolon", "Comma",
    "Period", "Apostrophe", "Slash", "Backslash", "Grave", "Equal", "Hyphen",
    "Space", "Enter", "Backspace", "Tab", "PageUp", "PageDown", "End", "Home",
    "Insert", "Delete", "Add", "Subtract", "Multiply", "Divide", "Left",
    "Right", "Up", "Down", "Numpad0", "Numpad1", "Numpad2", "Numpad3",
    "Numpad4", "Numpad5", "Numpad6", "Numpad7", "Numpad8", "Numpad9", "F1",
    "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13",
    "F14", "F15", "Pause"
};

static sfTexture *create_helmet_texture(void)
{
    return sfTexture_createFromFile("assets/helmet.png", NULL);
}

static sfSprite *setup_helmet_sprite(sfTexture *texture,
    sfVector2f position, int row)
{
    sfSprite *sprite;

    if (!texture)
        return NULL;
    sprite = sfSprite_create();
    if (!sprite)
        return NULL;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){0.1f, 0.1f});
    sfSprite_setPosition(sprite, (sfVector2f){
        position.x - 40,
        position.y + row * 55
    });
    return sprite;
}

static void draw_selection_helmet(sfRenderWindow *window,
    keybind_display_t display)
{
    sfTexture *helmetTexture;
    sfSprite *helmetSprite;

    if (!display.isSelected || !window)
        return;
    helmetTexture = create_helmet_texture();
    if (!helmetTexture)
        return;
    helmetSprite = setup_helmet_sprite(helmetTexture,
        display.position, display.row);
    if (!helmetSprite) {
        sfTexture_destroy(helmetTexture);
        return;
    }
    sfRenderWindow_drawSprite(window, helmetSprite, NULL);
    sfSprite_destroy(helmetSprite);
    sfTexture_destroy(helmetTexture);
}

static void draw_action_text(sfRenderWindow *window, sfFont *font,
    const char *action, keybind_display_t display)
{
    sfText *actionText = sfText_create();

    if (!actionText)
        return;
    sfText_setFont(actionText, font);
    sfText_setString(actionText, action);
    sfText_setCharacterSize(actionText, 24);
    sfText_setFillColor(actionText, display.isSelected ? sfGreen : sfWhite);
    sfText_setPosition(actionText, (sfVector2f){
        display.position.x,
        display.position.y + display.row * 55
    });
    sfRenderWindow_drawText(window, actionText, NULL);
    sfText_destroy(actionText);
}

void draw_key_text(sfRenderWindow *window, sfFont *font,
    sfKeyCode key, keybind_display_t display)
{
    sfText *keyText = sfText_create();

    if (!keyText)
        return;
    sfText_setFont(keyText, font);
    sfText_setString(keyText, display.isRebinding ?
        "Press a key..." : sfKey_strings[key + 1]);
    sfText_setCharacterSize(keyText, 24);
    if (display.isRebinding)
        sfText_setFillColor(keyText, sfRed);
    else
        sfText_setFillColor(keyText, sfYellow);
    sfText_setPosition(keyText, (sfVector2f){
        display.position.x + 300,
        display.position.y + display.row * 55
    });
    sfRenderWindow_drawText(window, keyText, NULL);
    sfText_destroy(keyText);
}

void draw_keybind(sfRenderWindow *window,
    sfFont *font, keybind_params_t params)
{
    keybind_display_t display = {
        .position = params.startPos,
        .row = params.position,
        .isSelected = params.isSelected,
        .isRebinding = params.isRebinding
    };

    draw_selection_helmet(window, display);
    draw_action_text(window, font, params.action, display);
    draw_key_text(window, font, params.key, display);
}

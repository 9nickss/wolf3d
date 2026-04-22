/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** main_menu
*/

#include "../../include/wolf3d.h"

void set_text(sfText **text, sfFont *font,
    const char *text_value, sfVector2f pos)
{
    sfFloatRect bounds;

    sfText_setString(*text, text_value);
    sfText_setFont(*text, font);
    sfText_setFillColor(*text, sfWhite);
    sfText_setCharacterSize(*text, 100);
    sfText_setPosition(*text, pos);
    bounds = sfText_getLocalBounds(*text);
    sfText_setOrigin(*text, (sfVector2f){bounds.left + bounds.width / 2.0f,
        bounds.top + bounds.height / 2.0f});
}

button_t *add_button(label_t label, const char *text,
    const char *font, sfVector2f pos)
{
    button_t *button = malloc(sizeof(button_t));

    if (!button)
        return NULL;
    button->label = label;
    button->text = sfText_create();
    if (!button->text)
        return NULL;
    button->font = sfFont_createFromFile(font);
    if (!button->font)
        return NULL;
    set_text(&button->text, button->font, text, pos);
    button->on = false;
    return button;
}

int add_main_menu(label_t label, const char *text,
    const char *font, sfVector2f pos)
{
    menu_t **head = &(*get_main_menu())->menu;
    menu_t *current = malloc(sizeof(menu_t));
    menu_t *last = (*head)->prev;

    if (!current)
        return 84;
    current->button = add_button(label, text, font, pos);
    if (!current->button)
        return 84;
    current->next = *head;
    current->prev = last;
    last->next = current;
    (*head)->prev = current;
    return 0;
}

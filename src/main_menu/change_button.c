/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** change_button
*/

#include "../../include/wolf3d.h"

void browse_main_menu(menu_t **current)
{
    do {
        *current = (*current)->next;
    } while ((*current)->button->on != true);
}

void arrows_key_menu(void)
{
    menu_t *head = (*get_main_menu())->menu;
    menu_t *current = head;

    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        browse_main_menu(&current);
        current->button->on = false;
        current->prev->button->on = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        browse_main_menu(&current);
        current->button->on = false;
        current->next->button->on = true;
    }
}

void change_button_on(button_t **button)
{
    menu_t *head = (*get_main_menu())->menu;
    menu_t *tmp = head;

    browse_main_menu(&tmp);
    tmp->button->on = false;
    (*button)->on = true;
}

int browse_main_menu_mouse(menu_t **current, menu_t *head, bool state)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(*get_window());
    sfFloatRect bounds;

    do {
        *current = (*current)->next;
        bounds = sfText_getGlobalBounds((*current)->button->text);
        if (sfFloatRect_contains(&bounds, mouse.x, mouse.y) &&
            (*current)->button->on == state && state == false) {
            change_button_on(&(*current)->button);
            return 0;
        }
        if (sfFloatRect_contains(&bounds, mouse.x, mouse.y) &&
            (*current)->button->on == state && state == true) {
            change_button_on(&(*current)->button);
            return 0;
        }
    } while (*current != head);
    return 84;
}

void arrows_mouse_menu(void)
{
    menu_t *head = (*get_main_menu())->menu;
    menu_t *current = head;

    browse_main_menu_mouse(&current, head, false);
}

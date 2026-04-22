/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** display_main_menu
*/

#include "../../include/wolf3d.h"

void draw_buttons(button_t *button)
{
    sfRenderWindow *window = *get_window();

    if (!button)
        return;
    if (button->on == true) {
        sfText_setFillColor(button->text, sfYellow);
        sfText_setScale(button->text, (sfVector2f){0.8, 0.8});
    }
    if (button->on == false) {
        sfText_setFillColor(button->text, sfWhite);
        sfText_setScale(button->text, (sfVector2f){0.6, 0.6});
    }
    sfRenderWindow_drawText(window, button->text, NULL);
}

void browse_buttons(void)
{
    menu_t *head = (*get_main_menu())->menu;
    menu_t *current = head;

    if (!head)
        return;
    do {
        draw_buttons(current->button);
        current = current->next;
    } while (current != head);
}

void draw_main_menu(void)
{
    sfRenderWindow *window = *get_window();
    sprite_t *menu_screen = (*get_main_menu())->menu_screen;

    sfRenderWindow_drawSprite(window, menu_screen->sprite, NULL);
    browse_buttons();
}

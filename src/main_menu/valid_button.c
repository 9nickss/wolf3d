/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** valid_button
*/

#include "../../include/wolf3d.h"

void valid_label_mouse(void)
{
    void (*select_lab[NB_LABEL])(void) = {new_game, load_game, settings, quit};
    menu_t *head = (*get_main_menu())->menu;
    menu_t *current = head;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (browse_main_menu_mouse(&current, head, true) == 0)
            select_lab[current->button->label]();
    }
}

void valid_label_key(void)
{
    void (*select_lab[NB_LABEL])(void) = {new_game, load_game, settings, quit};
    menu_t *head = (*get_main_menu())->menu;
    menu_t *current = head;

    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        browse_main_menu(&current);
        select_lab[current->button->label]();
    }
}

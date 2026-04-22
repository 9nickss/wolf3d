/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** free_main_menu
*/

#include "../../include/wolf3d.h"

void free_main_menu(void)
{
    menu_t **head = &(*get_main_menu())->menu;
    menu_t *current = *head;
    menu_t *next = NULL;

    if (!(*head))
        return;
    (*head)->prev->next = NULL;
    while (current) {
        next = current->next;
        if (current->button) {
            sfText_destroy(current->button->text);
            sfFont_destroy(current->button->font);
            free(current->button);
        }
        free(current);
        current = next;
    }
    *head = NULL;
}

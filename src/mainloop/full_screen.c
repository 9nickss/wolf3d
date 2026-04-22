/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** full_screen
*/

#include "../../include/wolf3d.h"

void full_screen_window(sfRenderWindow *window, sfEvent event)
{
    static bool full_screen = false;
    static bool key_handled = false;

    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF11 &&
        !key_handled) {
        sfRenderWindow_destroy(window);
        if (full_screen == false) {
            init_full_screen();
            full_screen = true;
        } else {
            init_window();
            full_screen = false;
        }
        key_handled = true;
    }
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyF11)
        key_handled = false;
}

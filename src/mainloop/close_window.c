/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** close_window
*/

#include "../../include/wolf3d.h"

void close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    else if (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyF4 &&
        event.key.alt)
        sfRenderWindow_close(window);
}

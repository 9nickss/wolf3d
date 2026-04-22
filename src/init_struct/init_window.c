/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_window
*/

#include "../../include/wolf3d.h"

sfRenderWindow **get_window(void)
{
    static sfRenderWindow *window = NULL;

    return &window;
}

int init_full_screen(void)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    sfRenderWindow **window = get_window();

    *window = sfRenderWindow_create(mode, "GhostSaber 3d", sfFullscreen, NULL);
    if (!(*window))
        return 84;
    sfRenderWindow_setFramerateLimit(*window, 60);
    return 0;
}

int init_window(void)
{
    const sfVideoMode mode = sfVideoMode_getDesktopMode();
    sfRenderWindow **window = get_window();

    *window = sfRenderWindow_create(mode, "GhostSaber 3d",
        sfDefaultStyle, NULL);
    if (!(*window))
        return 84;
    sfRenderWindow_setFramerateLimit(*window, 60);
    return 0;
}

int init_windowed(void)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    sfRenderWindow **window = get_window();

    mode.width = 1280;
    mode.height = 720;
    *window = sfRenderWindow_create(mode, "GhostSaber 3d",
        sfDefaultStyle, NULL);
    if (!(*window))
        return 84;
    sfRenderWindow_setFramerateLimit(*window, 60);
    return 0;
}

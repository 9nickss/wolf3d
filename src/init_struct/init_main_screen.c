/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_main_screen
*/

#include "../../include/wolf3d.h"

main_screen_t **get_main_screen(void)
{
    static main_screen_t *main_screen = NULL;

    return &main_screen;
}

int init_bg_fg(sfRenderWindow *window, main_screen_t **main_screen)
{
    sfVector2f scale = (sfVector2f){(float)(WIN_WIDTH(window) / (float)1920),
        (float)(WIN_HEIGHT(window) / (float)1080)};

    (*main_screen)->bg = get_sprite("assets/main_screen/bg.jpg");
    if (!(*main_screen)->bg)
        return 84;
    set_sprite(false, (*main_screen)->bg, (sfVector2f){0, 0}, scale);
    (*main_screen)->fg = get_sprite("assets/main_screen/fg.png");
    if (!(*main_screen)->fg)
        return 84;
    set_sprite(false, (*main_screen)->fg, (sfVector2f){0, 0}, scale);
    return 0;
}

int init_text(sfRenderWindow *window, main_screen_t **main_screen)
{
    (*main_screen)->text = sfText_create();
    if (!(*main_screen)->text)
        return 84;
    (*main_screen)->font = sfFont_createFromFile("fonts/ghost.otf");
    if (!(*main_screen)->font)
        return 84;
    set_text(&(*main_screen)->text, (*main_screen)->font,
        "Press any key to start.",
        (sfVector2f){WIN_WIDTH(window) * 0.5, WIN_HEIGHT(window) * 0.70});
    (*main_screen)->title = sfText_create();
    if (!(*main_screen)->title)
        return 84;
    sfText_setLetterSpacing((*main_screen)->title, 0.5);
    set_text(&(*main_screen)->title, (*main_screen)->font,
        "GhostSaber            3d",
        (sfVector2f){WIN_WIDTH(window) * 0.5, WIN_HEIGHT(window) * 0.20});
        sfText_setScale((*main_screen)->title, (sfVector2f){2.5, 2.5});
    return 0;
}

int init_main_screen(void)
{
    sfRenderWindow *window = *get_window();
    main_screen_t **main_screen = get_main_screen();

    (*main_screen) = malloc(sizeof(main_screen_t));
    if (!(*main_screen))
        return 84;
    if (init_bg_fg(window, main_screen) == 84)
        return 84;
    if (init_text(window, main_screen) == 84)
        return 84;
    return 0;
}

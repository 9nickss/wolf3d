/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** display_main_screen
*/

#include "../../include/wolf3d.h"

void draw_text_main_screen(void)
{
    sfRenderWindow *window = *get_window();
    main_screen_t *main_screen = *get_main_screen();

    sfText_setFillColor(main_screen->text, sfBlack);
    sfText_setPosition(main_screen->text, (sfVector2f)
        {(WIN_WIDTH(window) * 0.5) + 4, (WIN_HEIGHT(window) * 0.70) + 4});
    sfRenderWindow_drawText(window, main_screen->text, NULL);
    sfText_setFillColor(main_screen->text, sfWhite);
    sfText_setPosition(main_screen->text, (sfVector2f)
        {WIN_WIDTH(window) * 0.5, WIN_HEIGHT(window) * 0.70});
    sfRenderWindow_drawText(window, main_screen->text, NULL);
}

void draw_title_main_screen(void)
{
    sfRenderWindow *window = *get_window();
    main_screen_t *main_screen = *get_main_screen();

    sfText_setFillColor(main_screen->title, sfBlack);
    sfText_setPosition(main_screen->title, (sfVector2f)
        {(WIN_WIDTH(window) * 0.5) + 8, (WIN_HEIGHT(window) * 0.20) + 8});
    sfRenderWindow_drawText(window, main_screen->title, NULL);
    sfText_setFillColor(main_screen->title, sfWhite);
    sfText_setPosition(main_screen->title, (sfVector2f)
        {WIN_WIDTH(window) * 0.5, WIN_HEIGHT(window) * 0.20});
    sfRenderWindow_drawText(window, main_screen->title, NULL);
}

void draw_main_screen(void)
{
    sfRenderWindow *window = *get_window();
    main_screen_t *main_screen = *get_main_screen();

    sfRenderWindow_drawSprite(window, main_screen->bg->sprite, NULL);
    draw_title_main_screen();
    sfRenderWindow_drawSprite(window, main_screen->fg->sprite, NULL);
    draw_text_main_screen();
}

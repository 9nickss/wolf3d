/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_main_menu
*/

#include "../../include/wolf3d.h"

main_menu_t **get_main_menu(void)
{
    static main_menu_t *main_menu;

    return &main_menu;
}

menu_t *init_head(void)
{
    sfRenderWindow *window = *get_window();
    menu_t *head = malloc(sizeof(menu_t));

    if (!head)
        return NULL;
    head->button = add_button(NEW_GAME, "New Game", "fonts/ghost.otf",
        (sfVector2f){WIN_WIDTH(window) * 0.5, WIN_HEIGHT(window) * 0.36});
    if (!head->button)
        return NULL;
    sfText_setScale(head->button->text, (sfVector2f){0.8, 0.8});
    head->button->on = true;
    head->prev = head;
    head->next = head;
    return head;
}

int fill_main_menu(void)
{
    sfRenderWindow *window = *get_window();

    (*get_main_menu())->menu = init_head();
    if (add_main_menu(LOAD_GAME, "Load Game", "fonts/ghost.otf", (sfVector2f)
        {WIN_WIDTH(window) * 0.5, WIN_HEIGHT(window) * 0.45}) == 84)
        return 84;
    if (add_main_menu(SETTINGS, "Settings", "fonts/ghost.otf", (sfVector2f)
        {WIN_WIDTH(window) * 0.5, WIN_HEIGHT(window) * 0.54}) == 84)
        return 84;
    if (add_main_menu(QUIT, "Quit", "fonts/ghost.otf", (sfVector2f)
        {WIN_WIDTH(window) * 0.5, WIN_HEIGHT(window) * 0.63}) == 84)
        return 84;
    return 0;
}

int init_main_menu(void)
{
    main_menu_t **main_menu = get_main_menu();
    sfRenderWindow *window = *get_window();
    sfVector2f scale = (sfVector2f){(float)WIN_WIDTH(window) / (float)3840,
        (float)WIN_HEIGHT(window) / (float)2160};

    *main_menu = malloc(sizeof(main_menu_t));
    if (!(*main_menu))
        return 84;
    if (fill_main_menu() == 84)
        return 84;
    (*main_menu)->menu_screen = get_sprite("assets/main_menu.png");
    if (!(*main_menu)->menu_screen)
        return 84;
    set_sprite(false, (*main_menu)->menu_screen, (sfVector2f){0, 0}, scale);
    return 0;
}

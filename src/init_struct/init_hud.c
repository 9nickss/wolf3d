/*
** EPITECH PROJECT, 2024
** G-ING-210-NCE-2-1-wolf3d-gabriel.spanneut-peressutti
** File description:
** init_hud.c
*/

#include "../../include/wolf3d.h"

hud_t **get_hud(void)
{
    static hud_t *hud = NULL;

    return &hud;
}

static int init_dim(void)
{
    hud_t **hud = get_hud();
    sfRenderWindow **window = get_window();

    (*hud)->dim_effect = sfRectangleShape_create();
    if (!(*hud)->dim_effect)
        return 84;
    sfRectangleShape_setSize((*hud)->dim_effect,
        (sfVector2f){WIN_WIDTH(*window), WIN_HEIGHT(*window)});
    sfRectangleShape_setPosition((*hud)->dim_effect, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor((*hud)->dim_effect,
        sfColor_fromRGBA(0, 0, 0, 200));
    return 0;
}

static int init_overlay(void)
{
    hud_t **hud = get_hud();
    sfRenderWindow **window = get_window();
    sfVector2f scale;
    sfVector2u txt_size;

    (*hud)->overlay = *get_sprite("assets/hud/overlay_hud_nobg_resized.png");
    if (!(*hud)->overlay.sprite)
        return 84;
    txt_size = sfTexture_getSize(sfSprite_getTexture((*hud)->overlay.sprite));
    scale.x = (float)WIN_WIDTH(*window) / txt_size.x * 1.14;
    scale.y = (float)WIN_HEIGHT(*window) / txt_size.y * 1.05;
    set_sprite(true, &(*hud)->overlay, (sfVector2f){-135, 20}, scale);
    sfSprite_setColor((*hud)->overlay.sprite,
        sfColor_fromRGBA(255, 255, 255, 150));
    if (init_dim() == 84)
        return 84;
    return 0;
}

static int init_shadow(void)
{
    hud_t **hud = get_hud();
    main_screen_t **main_screen = get_main_screen();

    (*hud)->time_shadow = sfText_create();
    if (!(*hud)->time_shadow)
        return 84;
    sfText_setFont((*hud)->time_shadow, (*main_screen)->font);
    return 0;
}

static int init_score(void)
{
    hud_t **hud = get_hud();
    main_screen_t **main_screen = get_main_screen();

    (*hud)->score = 0;
    (*hud)->score_text = sfText_create();
    if (!(*hud)->score_text)
        return 84;
    sfText_setFont((*hud)->score_text, (*main_screen)->font);
    sfText_setCharacterSize((*hud)->score_text, 60);
    sfText_setColor((*hud)->score_text, sfWhite);
    return 0;
}

static int init_time(void)
{
    hud_t **hud = get_hud();
    main_screen_t **main_screen = get_main_screen();

    (*hud)->time_txt = sfText_create();
    if (!(*hud)->time_txt)
        return 84;
    sfText_setFont((*hud)->time_txt, (*main_screen)->font);
    sfText_setCharacterSize((*hud)->time_txt, 30);
    sfText_setColor((*hud)->time_txt, sfWhite);
    return 0;
}

int init_hud(void)
{
    hud_t **hud = get_hud();

    (*hud) = malloc(sizeof(hud_t));
    if (!(*hud))
        return 84;
    if (init_time() == 84)
        return 84;
    if (init_shadow() == 84)
        return 84;
    if (init_score() == 84)
        return 84;
    if (init_overlay() == 84)
        return 84;
    return 0;
}

/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** main
*/

#include "../../include/wolf3d.h"

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return display_rules();
    if (ac == 1)
        return gameloop();
    return 84;
}

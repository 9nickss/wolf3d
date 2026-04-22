/*
** EPITECH PROJECT, 2024
** bsmyworldworld
** File description:
** display_rules
*/

#include "../../include/wolf3d.h"

int display_rules(void)
{
    write(1, "\nMap Controls:\n", 16);
    write(1, "  q / d   - Rotate map left / right\n", 37);
    write(1, "  z / s   - Rotate map up / down\n", 34);
    write(1, "  Arrows  - Move camera around the map\n", 40);
    write(1, "  Enter   - Reset map\n", 23);
    write(1, "  + / -   - Zoom in / out\n", 27);
    write(1, "  Esc     - Exit\n", 18);
    write(1, "  Toolbar - Adjust mouse selection area\n", 41);
    return 0;
}

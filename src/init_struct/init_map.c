/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_map
*/

#include "../../include/wolf3d.h"

int ***get_map(void)
{
    static int **map = NULL;

    return &map;
}

static int allocate_map_memory(int ***map)
{
    *map = malloc(MAP_SIZE * sizeof(int *));
    if (*map == NULL)
        return 84;
    for (int i = 0; i < MAP_SIZE; i++) {
        (*map)[i] = malloc(MAP_SIZE * sizeof(int));
        if ((*map)[i] == NULL)
            return 84;
    }
    return 0;
}

static int read_map_line(FILE *file, char *line)
{
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL)
        return 84;
    return 0;
}

static void parse_map_line(char *line, int *row)
{
    char *token = strtok(line, ",");

    for (int j = 0; j < MAP_SIZE; j++) {
        if (token != NULL) {
            row[j] = atoi(token);
            token = strtok(NULL, ",");
        }
    }
}

int init_map(void)
{
    FILE *file = fopen("map.txt", "r");
    int **map = *get_map();
    char line[MAX_LINE_LENGTH];

    if (file == NULL)
        return 84;
    if (allocate_map_memory(&map) != 0) {
        fclose(file);
        return 84;
    }
    for (int i = 0; i < MAP_SIZE; i++) {
        if (read_map_line(file, line) != 0) {
            fclose(file);
            return 84;
        }
        parse_map_line(line, map[i]);
    }
    *get_map() = map;
    fclose(file);
    return 0;
}

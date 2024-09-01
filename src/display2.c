/*
** EPITECH PROJECT, 2022
** display2
** File description:
** display2
*/

#include "../inc/tetris.h"

int display_default_key (int i)
{
    my_putstr(keyname(i));
    my_putstr(" (");
    my_put_nbr(i);
    my_putstr(")\n");
    return 0;
}

int is_finished2 (char *map, int i)
{
    for (int j = i;map[j] != '\0';j++) {
        if (map[j] != ' ' && map[j] != '\n') return 0;
    }
    return 1;
}

int my_strlen2 (char *str)
{
    int i = 0;
    for (i = 0;str[i] != '\0' && is_finished2(str, i) == 0;i++);
    return i + 1;
}

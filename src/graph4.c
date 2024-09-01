/*
** EPITECH PROJECT, 2022
** graphique
** File description:
** ncurses
*/

#include "../inc/tetris.h"

int **add_on_map(int **map, piece_t *p, flags *f)
{
    p->add.x = 0;
    p->add.y = 0;
    for (int i = 0; i < f->size.y; i++) {
        for (int j = 0; j < f->size.x; j++) {
            map = add_on_map2(map, p, i, j);
        }
    }
    return map;
}

void drop(flags *f, int **map, piece_t *p)
{
    while (check_coli(f, p, &map) == 0);
}

/*
** EPITECH PROJECT, 2022
** graphique
** File description:
** ncurses
*/

#include "../inc/tetris.h"

int **printw_next(piece_t *p, int **map, flags *f)
{
    start_color();
    init_pair(1, 0, 1);
    init_pair(2, 0, 2);
    init_pair(3, 0, 3);
    init_pair(4, 0, 4);
    init_pair(5, 0, 5);
    init_pair(6, 0, 6);
    init_pair(7, 0, 7);
    init_pair(8, 0, 8);
    if (p == NULL) return NULL;
    mvwprintw(stdscr, 0, 32, "NEXT:");
    for (int i = 0; i < p->size.y; i++) {
        for (int j = 0; j < p->size.x; j++) {
            attron(COLOR_PAIR(p->map[i][j]));
            mvwprintw(stdscr, i, j + f->size.x + 28, " ");
            attroff(COLOR_PAIR(p->map[i][j]));
        }
    }
    return map;
}

void printw_map2(int **map, int i, int j)
{
    if (map[i][j] == 0)
        mvwprintw(stdscr, i , j + (COLS / 4), ".");
        // printw(".");
    else {
        attron(COLOR_PAIR(map[i][j]));
        mvwprintw(stdscr, i , j + (COLS / 4), " ");
        // printw(" ");
        attroff(COLOR_PAIR(map[i][j]));
    }
}

void printw_map(int **map, piece_t *p, flags *f)
{
    clear();
    start_color();
    init_pair(1, 0, 1);
    init_pair(2, 0, 2);
    init_pair(3, 0, 3);
    init_pair(4, 0, 4);
    init_pair(5, 0, 5);
    init_pair(6, 0, 6);
    init_pair(7, 0, 7);
    init_pair(8, 0, 8);
    for (int i = 0; i < f->size.y; i++) {
        for (int j = 0; j < f->size.x; j++) {
            printw_map2(map, i, j);
        }
        printw("\n");
    }
    refresh();
}

int **add_on_map3(int **map, piece_t *p, int i, int j)
{
    if (p->add.x == p->size.x) {
        p->add.y += 1;
        p->add.x = 0;
    }
    if (p->map[p->add.y][p->add.x] != 0)
        map[i][j] = p->map[p->add.y][p->add.x];
    p->add.x += 1;
    return map;
}

int **add_on_map2(int **map, piece_t *p, int i, int j)
{
    if (i >= p->pos.y && i < p->size.y + p->pos.y) {
        if (j >= p->pos.x && j < p->size.x + p->pos.x)
            map = add_on_map3(map, p, i, j);
    }
    return map;
}

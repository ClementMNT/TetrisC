/*
** EPITECH PROJECT, 2022
** graphique
** File description:
** ncurses
*/

#include "../inc/tetris.h"

int **printw_pieces_cs(piece_t *p, int **map, int i, int j);

int my_rand (int min, int max)
{
    int nombreAleatoire = (rand() % (max - min + 1)) + min;
    return nombreAleatoire;
}

void clean_rotate(piece_t *p, flags *f)
{
    while (p->rotate != 0) {
        transp(p, f);
        if (p->rotate > 3)
            p->rotate = 0;
    }
}

piece_t *get_random_piece (piece_t *p, piece_t *tmp)
{
    int len = 0, len2 = -1, len3 = 0;
    piece_t *result = NULL, *result1 = malloc(sizeof(piece_t));
    for (piece_t *ptr = p;ptr != NULL;ptr = ptr->next)
        (ptr->error == 0) ? len++ : 0;
    while (result == tmp || len2 == -1) {
        len2 = -1;
        len3 = my_rand(0, len - 1);
        for (piece_t *ptr = p;ptr != NULL && len2 != len3;ptr = ptr->next) {
            (ptr->error == 0) ? len2++ : 0;
            (len2 == len3) ? result = ptr : 0;
        }
    }
    result1->color = result->color;
    result1->map = result->map;
    result1->pos = result->pos;
    result1->rotate = result->rotate;
    result1->size = result->size;
    return result1;
}

int **printw_pieces(piece_t *p, int **map, flags *f)
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
    for (int i = 0; i < p->size.y; i++) {
        for (int j = 0; j < p->size.x; j++) {
            printw_pieces_cs(p, map, i, j);
        }
    }
    return map;
}

int **printw_pieces_cs(piece_t *p, int **map, int i, int j)
{
    if (p->map[i][j] == 0 && map[i + p->pos.y][j + p->pos.x] == 0) {
        mvwprintw(stdscr, i + p->pos.y, j + p->pos.x + (COLS / 4), ".");
    } else {
        attron(COLOR_PAIR(p->map[i][j]));
        mvwprintw(stdscr, i + p->pos.y, j + p->pos.x + (COLS / 4), " ");
        attroff(COLOR_PAIR(p->map[i][j]));
    }
    return NULL;
}

/*
** EPITECH PROJECT, 2022
** graphique
** File description:
** ncurses
*/

#include "../inc/tetris.h"

int **malloc_for_trans(int x, int y)
{
    int **transp = malloc(sizeof(int *) * y);
    for (int i = 0; i < y; i++) {
        transp[i] = malloc(sizeof(int) * x);
    }
    return transp;
}

void check_in_range(piece_t *p, flags *f)
{
    if (p->pos.x + p->size.x > f->size.x) {
        p->pos.x -= p->pos.x + p->size.x - f->size.x;
    }
}

void transp(piece_t *p, flags *f)
{
    int **mat = malloc_for_trans(p->size.y, p->size.x);
    for (int i = 0; i < p->size.x; i++) {
        for (int j = p->size.y - 1, j2 = 0; j >= 0; j--, j2++) {
            mat[i][j2] = p->map[j][i];
        }
    }
    p->map = mat;
    p->rotate = p->rotate + 1;
    if (p->rotate > 3) p->rotate = 0;
    my_swap(&(p->size.x), &(p->size.y));
    check_in_range(p, f);
}

int check_coli(flags *f, piece_t *p, int ***map)
{
    if (p->pos.y + p->size.y == (f->size.y)) {
        *map = add_on_map(*map, p, f);
        p->pos.x = f->size.x / 2 - (p->size.x / 2);
        p->pos.y = 0;
        return 1;
    }
    int e = 0;
    for (int i = 0; i < p->size.y; i++) {
        for (int j = 0; j < p->size.x && e == 0; j++) {
            e = check_coli_cs(f, p, map, (vector) {i, j});
        }
    }
    if (e != 0) return 1;
    p->pos.y = p->pos.y + 1;
    return 0;
}

int check_coli_cs(flags *f, piece_t *p, int ***map, vector v)
{
    if (p->map[v.x][v.y] != 0) {
        if ((*map)[v.x + p->pos.y + 1][v.y + p->pos.x] != 0) {
            *map = add_on_map(*map, p, f);
            p->pos.x = f->size.x / 2 - (p->size.x / 2);
            p->pos.y = 0;
            return 1;
        }
    }
    return 0;
}

/*
** EPITECH PROJECT, 2022
** graphique
** File description:
** ncurses
*/

#include "../inc/tetris.h"

void my_swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int clear_line(flags * f, int ***map, int n)
{
    char c;
    for (int j = 0; j < f->size.x; j++) {
        (*map)[n][j] = 0;
    }
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < f->size.x; j++) {
            c = (*map)[i - 1][j];
            (*map)[i][j] = c;
        }
    }
    return 0;
}

void print_hud(flags *f, piece_t *p)
{
    f->time = time(NULL);
    mvwprintw(stdscr, 0, f->size.x + 5, "score = %i", f->score);
    mvwprintw(stdscr, 1, f->size.x + 5, "level = %i", f->level);
    mvwprintw(stdscr, 2, f->size.x + 5, "ligne = %i", f->line);
    mvwprintw(stdscr, 3, f->size.x + 5, "High score = %i", f->hs);
    mvwprintw(stdscr, 4, f->size.x + 5, "Timer : %i", f->time - f->timebase);
    refresh();
}

void add_score(flags *f, int combo)
{
    char mystr[10];
    if (combo == 1) f->score += 40;
    if (combo == 2) f->score += 100;
    if (combo == 3) f->score += 300;
    if (combo == 4) f->score += 1200;
    if (f->score > f->hs) {
        f->hs = f->score;
        int fc = open("High_score", O_RDWR);
        sprintf(mystr, "%d", f->hs);
        write(fc, mystr, my_strlen(mystr));
    }
}

int check_line(flags *f, piece_t *p, int **map)
{
    int cmp = 0;
    f->combo = 0;
    for (int i = 0; i < f->size.y; i++) {
        for (int j = 0; j < f->size.x; j++) {
            map[i][j] != 0 ? cmp++ : 0;
            cmp == f->size.x ? the_clear(f, p, map, i) : 0;
        }
        cmp = 0;
    }
    add_score(f, f->combo);
    return 0;
}

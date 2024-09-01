/*
** EPITECH PROJECT, 2022
** graphique
** File description:
** ncurses
*/

#include "../inc/tetris.h"
#include <sys/types.h>
#include <sys/stat.h>

int check_right_side(flags *f, piece_t *p, int **map)
{
    int j = p->size.x;
    for (int i = 0; i < p->size.y; i++) {
        if (map[p->pos.y + i][p->pos.x + j] != 0)
            return 0;
    }
    return 1;
}

int check_left_side(flags *f, piece_t *p, int **map)
{
    int j = p->pos.x;
    for (int i = 0; i < p->size.y; i++) {
        if (map[p->pos.y + i][j - 1] != 0)
            return 0;
    }
    return 1;
}

flags *pause_bone (flags *f, piece_t *p, int **map)
{
    usleep(100000);
    int act = getch();
    clear();
    int fd = open("I'M_LEANING_MOM!!", O_RDONLY);
    char i[667];
    int size = 10;
    while (size == 10) {
        size = read(fd, i, 10);
        write(1, i, size);
        printw("%s", i);
    }
    refresh();
    (act == f->pause) ? f->pause_id *= (-1) : 0;
    return NULL;
}

int move_side(flags *f, piece_t *p, int act, int **map)
{
    if (act == f->right && p->pos.x + p->size.x < f->size.x)
        (check_right_side(f, p, map)) ? p->pos.x = p->pos.x + 1 : 0;
    if (act == f->left && p->pos.x > 0)
        (check_left_side(f, p, map)) ? p->pos.x = p->pos.x - 1 : 0;
    if (act == f->quit) return 0;
    (act == f->pause) ? f->pause_id *= -1 : 0;
    while (f->pause_id == -1) {
        pause_bone(f, p, map);
    }
    printw_map(map, p, f);
    printw_pieces(p, map, f);
    print_hud(f, p);
    printw_next(p->next, map, f);
    refresh();
    usleep(100000);
    return 1;
}

void init_hs(flags *f, piece_t *p)
{
    struct stat buf1;
    int fd = open("High_score", O_RDONLY);
    stat("High_score", &buf1);
    int size = buf1.st_size;
    char *buf = malloc(sizeof(char) * (size + 1));
    read(fd, buf, size);
    f->hs = atoi(buf);
}

int **init_graph (flags *f, piece_t *p)
{
    f->line = 0;
    f->score = 0;
    init_hs(f, p);
    int **map = malloc(sizeof(int *) * (f->size.y + 1));
    map[f->size.y] = NULL;
    for (int i = 0; i < f->size.y; i++) {
        map[i] = malloc(sizeof(int) * (f->size.x + 1));
        for (int j = 0;j < f->size.x;j++) {
            map[i][j] = 0;
        }
    }
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);
    return map;
}

/*
** EPITECH PROJECT, 2022
** graphique
** File description:
** ncurses
*/

#include "../inc/tetris.h"
//time_t my_t, fire_t;

int printw_all (piece_t *p, flags *f, piece_t *tmp, int **map)
{
    printw_map(map, tmp, f);
    printw_pieces(tmp, map, f);
    printw_next(tmp->next, map, f);
    print_hud(f, p);
    check_line(f, p, map);
    flushinp();
    usleep(400000 / ((f->level) * 0.7));
    return 0;
}

piece_t *graph_cs (piece_t *p, piece_t *tmp, flags *f, int **map)
{
    clean_rotate(tmp, f);
    tmp = tmp->next;
    game_over(f, tmp, map);
    tmp->next = get_random_piece(p, tmp);
    return tmp;
}

int the_clear(flags *f, piece_t *p, int **map, int i)
{
    clear_line(f, &map, i);
    f->line += 1;
    f->level += 1;
    f->combo += 1;
    return 0;
}

int graph(flags *f, piece_t *p)
{
    int i = 1, act = 0, **map = init_graph(f, p);
    f->time = time(NULL);
    f->timebase = f->time;
    piece_t *tmp = NULL;
    tmp = get_random_piece(p, NULL);
    tmp->next = get_random_piece(p, tmp);
    if (LINES < 20) {
        endwin();
        printf("Le terminal est trop petit veuillez l'agrandir\n");
        return 0;
    }
    while (i) {
        act = getch();
        clear();
        i = move_side(f, tmp, act, map);
        (act == f->turn) ? transp(tmp, f) : 0;
        if (check_coli(f, tmp, &map))
            tmp = graph_cs(p, tmp, f, map);
        if (act == f->drop) {
            drop(f, map, tmp);
            tmp = graph_cs(p, tmp, f, map);
        }
        printw_all(p, f, tmp, map);
    }
    clear();
    refresh();
    endwin();
    return 0;
}

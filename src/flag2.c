/*
** EPITECH PROJECT, 2022
** flag
** File description:
** flag
*/

#include "../inc/tetris.h"

void set_flag3 (char opt, char *bin)
{
    if (opt == ':' || opt == '?')
        exit(84);
    if (opt == 'h') read_help(bin);
}

void set_flag2 (flags *f, char opt, char *val)
{
    if (val[0] == '\0') exit(84);
    (opt == 'L') ? f->level = my_getnbr(val) : 0;
    (opt == 'l') ? f->left = my_getnbr(val) : 0;
    (opt == 'r') ? f->right = my_getnbr(val) : 0;
    (opt == 't') ? f->turn = my_getnbr(val) : 0;
    (opt == 'd') ? f->drop = my_getnbr(val) : 0;
    (opt == 'q') ? f->quit = my_getnbr(val) : 0;
    (opt == 'p') ? f->pause = my_getnbr(val) : 0;
}

int display_part5 (flags *f, piece_t *p)
{
    for (piece_t *ptr = p;ptr != NULL;ptr = ptr->next) {
        if (ptr->error != 1)
            exit(0);
    }
    exit(84);
}

/*
** EPITECH PROJECT, 2022
** display
** File description:
** display
*/

#include "../inc/tetris.h"

int display_part1 (flags *f, piece_t *p)
{
    if (f->debug == 0)
        return 0;
    my_putstr("Key left: ");
    display_default_key(f->left);
    my_putstr("Key right: ");
    display_default_key(f->right);
    my_putstr("Key turn: ");
    display_default_key(f->turn);
    my_putstr("Key drop: ");
    display_default_key(f->drop);
    my_putstr("Key quit: ");
    display_default_key(f->quit);
    my_putstr("Key pause: ");
    display_default_key(f->pause);
    display_part2(f, p);
    return 0;
}

int display_part2 (flags *f, piece_t *p)
{
    my_putstr("Next: ");
    (f->next == true) ? my_putstr("Yes\n") : my_putstr("No\n");
    my_putstr("Level: ");
    my_put_nbr(f->level);
    my_putchar('\n');
    my_putstr("Size: ");
    my_put_nbr(f->size.y);
    my_putchar('*');
    my_put_nbr(f->size.x);
    my_putchar('\n');
    my_putchar('\n');
    int nbr = 0;
    for (piece_t *ptr = p;ptr != NULL;nbr++, ptr = ptr->next);
    my_putstr("Number of tetriminos: ");
    my_put_nbr(nbr);
    my_putchar('\n');
    display_part3(f, p);
    return 0;
}

int display_part3 (flags *f, piece_t *p)
{
    for (piece_t *ptr = p;ptr != NULL;ptr = ptr->next) {
        my_putstr("Tetriminos '");
        my_putstr(ptr->name);
        my_putstr("': ");
        if (ptr->error == 1) {
            my_putstr("error\n");
            continue;
        }
        my_putstr("size ");
        my_put_nbr(ptr->size.x);
        my_putstr("*");
        my_put_nbr(ptr->size.y);
        my_putstr(", color ");
        my_put_nbr(ptr->color);
        my_putstr("\n");
        display_part4 (f, ptr);
    }
    display_part5 (f, p);
    return 0;
}

int display_part4 (flags *f, piece_t *p)
{
    int j = 0;
    for (int i = 0;i < p->size.y;i++) {
        for (j = 0;j < p->size.x && !is_finished(p->map[i], p->size.x, j);j++)
            (p->map[i][j] != 0) ? my_putchar('*') : my_putchar(' ');
        my_putchar('\n');
    }
    return 0;
}

int is_finished (int *map, int len, int i)
{
    for (int j = i;j < len;j++) {
        if (map[j] != 0) return 0;
    }
    return 1;
}

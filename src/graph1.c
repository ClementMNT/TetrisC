/*
** EPITECH PROJECT, 2022
** graphique
** File description:
** ncurses
*/

#include "../inc/tetris.h"

void game_over(flags *f, piece_t *p, int **map)
{
    if (check_coli(f, p, &map)) {
        clear();
        int fd = open("GAME_OVER.txt", O_RDONLY);
        char i[667];
        int size = 10;
        while (size == 10) {
            size = read(fd, i, 10);
            write(1, i, size);
            printw("%s", i);
        }
        refresh();
        usleep(10000000);
        close(fd);
        exit(0);
    }
}

/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** tetris
*/

#include "../inc/tetris.h"

int main (int argc, char **argv)
{
    srand(time(NULL));
    return tetris(argc, argv);
}

int my_nbrcmp(char *str10, char *str20)
{
    int i = 0, result = 0;
    char *str1 = my_strdup(str10);
    char *str2 = my_strdup(str20);
    for (int j = 0;str1[j] != '\0';j++) {
        if (str1[j] >= 65 && str1[j] <= 90)
            str1[j] = str1[j] - 65 + 97;
    }
    for (int j = 0;str2[j] != '\0';j++) {
        if (str2[j] >= 65 && str2[j] <= 90)
            str2[j] = str2[j] - 65 + 97;
    }
    for (;str1[i] != '\0' && str1[i] == str2[i];i++);
    result = str1[i] - str2[i];
    free(str1);
    free(str2);
    return (result);
}

piece_t *alphabetical_sort (piece_t *p)
{
    piece_t *temp = NULL;
    int len = 0;
    if (p == NULL || p->next == NULL) return p;
    for (piece_t *ptr = p;ptr != NULL;len++, ptr = ptr->next);
    for (int i = 0;i < len;i++) {
        if (my_nbrcmp(p->name, p->next->name) > 0) {
            temp = p->next;
            p->next = p->next->next;
            temp->next = p;
            p = temp;
        }
        for (piece_t *ptr = p;ptr->next->next != NULL;ptr = ptr->next) {
            if (my_nbrcmp(ptr->next->name, ptr->next->next->name) < 0) continue;
            temp = ptr->next;
            ptr->next = ptr->next->next;
            temp->next = temp->next->next;
            ptr->next->next = temp;
        }
    }
    return p;
}

int tetris (int argc, char **argv)
{
    piece_t *p = link_all_piece(my_ls("tetriminos"));
    flags *f = setup_flags(argc, argv);
    display_part1(f, p);
    for (piece_t *ptr = p;ptr != NULL;ptr = ptr->next) {
        ptr->pos.x = f->size.x / 2 - (ptr->size.x / 2);
    }
    graph(f, p);
    return 0;
}

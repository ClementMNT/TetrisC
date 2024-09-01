/*
** EPITECH PROJECT, 2022
** get_piece
** File description:
** get_piece
*/

#include "../inc/tetris.h"

piece_t *get_piece (char **map)
{
    piece_t *new = malloc(sizeof(piece_t));
    (my_arraylen(map) < 2) ? new->error = 1 : 0;
    if (my_arraylen(map) < 2) return new;
    map[0][my_strlen(map[0]) - 1] = '\0';
    char **str = my_2d_array_str_split(map[0], ' ');
    (my_arraylen(str) != 3) ? new->error = 1 : 0;
    if (my_arraylen(str) != 3) return new;
    if (is_nbr(str[0]) != 1 || is_nbr(str[1]) != 1 || is_nbr(str[2]) != 1) {
        new->error = 1;
        return new;
    }
    new->size.x = my_getnbr(str[0]);
    new->size.y = my_getnbr(str[1]);
    int error = fill_map(new, &map[1], my_getnbr(str[2]));
    new->error = (error == 84) ? 1 : 0;
    new->color = my_getnbr(str[2]);
    (new->color < 0 || new->color > 7) ? new->error = 1 : 0;
    if (new->color < 0 || new->color > 7) return new;
    return new;
}

piece_t *link_all_piece (char **files)
{
    piece_t *root = NULL, *ptr = NULL;
    char *ext = NULL;
    for (int i = 0;files[i] != NULL;i++) {
        ext = my_strstr(files[i], ".tetrimino");
        if (ext == NULL)
            continue;
        ptr = get_piece(file_str(my_strcat("tetriminos/", files[i])));
        ext[0] = '\0';
        ptr->name = files[i];
        ptr->pos.x = 0;
        ptr->pos.y = 0;
        ptr->rotate = 0;
        ptr->next = root;
        root = ptr;
    }
    root = alphabetical_sort(root);
    return root;
}

int fill_map (piece_t *new, char **map, int nbr)
{
    int biggest = 0;
    new->map = malloc(sizeof(int *) * (my_arraylen(map) + 1));
    new->map[my_arraylen(map)] = NULL;
    for (int i = 0;map[i] != NULL;i++) {
        if (my_strlen2(map[i]) > biggest)
            biggest = my_strlen2(map[i]);
    }
    if (biggest - 1 != new->size.x) return 84;
    if (my_arraylen(map) != new->size.y) return 84;
    for (int i = 0;map[i] != NULL;i++) {
        new->map[i] = malloc(sizeof(int) * biggest);
        for (int j = 0;j < biggest; new->map[i][j] = 0, j++);
        for (int j = 0;map[i][j] != '\0';j++) {
            new->map[i][j] = (map[i][j] == '*') ? nbr : 0;
        }
    }
    return 0;
}

int nbr_of_files (char *dir_name)
{
    DIR *dir;
    int result = 0;
    struct dirent *entry;
    dir = opendir(dir_name);
    if (!dir)
        return 0;
    while (1) {
        entry = readdir(dir);
        if (!entry) break;
        (entry->d_name[0] != '.') ? result++ : 0;
    }
    closedir(dir);
    return (result);
}

char **my_ls (char *dir_name)
{
    DIR *dir;
    struct dirent *entry;
    int pars = 0, size = nbr_of_files(dir_name);
    char **files = malloc(sizeof(char *) * (size + 1));
    files[size] = NULL;
    dir = opendir(dir_name);
    if (!dir) return (files);
    while (1) {
        entry = readdir(dir);
        if (!entry) break;
        if (entry->d_name[0] != '.') {
            files[pars] = my_strdup(entry->d_name);
            pars++;
        }
    }
    closedir(dir);
    return (files);
}

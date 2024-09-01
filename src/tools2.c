/*
** EPITECH PROJECT, 2022
** tools2
** File description:
** tools2
*/

#include "../inc/tetris.h"

int is_nbr (char *str)
{
    for (int i = 0;str[i] != '\0';i++) {
        if (char_is_num(str[i]) == 0)
            return 0;
    }
    return 1;
}

void free_array (void **array)
{
    for (int i = 0;array[i] != NULL;i++) {
        free(array[i]);
    }
    free(array);
}

char **file_str (char *file_name)
{
    int size = 0, h = 0, return_val = 0;
    size_t len = 0;
    FILE *f = fopen(file_name, "r");
    if (f == NULL) return NULL;
    word *root = malloc(sizeof(word)), *p = root, *temp = root;
    for (;return_val != -1;h++, p->next = NULL) {
        p->str = NULL;
        return_val = getline(&(p->str), &len, f);
        if (return_val != -1) {
            p->next = malloc(sizeof(word));
            temp = p;
            p = p->next;
        }
    }
    temp->next = NULL;
    p = root;
    char **result = malloc(sizeof(char *) * h);
    for (int i = 0;p != NULL;result[i] = p->str, p = p->next, i++);
    result[h - 1] = NULL;
    return (result);
}

int is_in (char *str, char const *to_find, int i)
{
    int j = 0;
    while (str[i] == to_find[j]) {
        if (to_find[j + 1] == '\0')
            return (1);
        i = i + 1;
        j = j + 1;
    }
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    if (to_find[0] == '\0')
        return str;
    while (str[i] != '\0') {
        if (str[i] == to_find[0] && is_in(str, to_find, i) == 1) {
            return (&str[i]);
        }
        i = i + 1;
    }
    return NULL;
}

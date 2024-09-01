/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** str dup
*/

#include "my.h"

char *my_strdup (char const *src)
{
    int i = 0, j = 0, len = my_strlen(src);
    char *strd = malloc(sizeof(char) * (len) + 1);
    strd[len] = '\0';
    while (j < len) {
        strd[j] = src[j];
        j++;
    }
    return (strd);
}

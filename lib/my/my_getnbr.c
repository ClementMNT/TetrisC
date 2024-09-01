/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** getnbr
*/

#include "my.h"

int my_getnbr (char *str)
{
    long e = 1, pow = 1, result = 0, i = 0;
    if (str[0] == '-') {
        e = -1;
        str = &str[1];
    }
    i = my_strlen(str) - 1;
    for (;i >= 0;i--) {
        result = result + (str[i] - 48) * pow;
        pow = pow * 10;
    }
    result = result * e;
    return result;
}

long long my_getnbr2 (const char *str)
{
    if (str == NULL) return 0;
    int sign = 1, nbr_len = 0;
    long long nbr = 0;
    while ((*str == '-' || *str == '+')) {
        (*str == '-') ? sign *= -1 : 0;
        str++;
    }
    int exp = 1;
    for (int nbr_len = 0; char_is_num(str[nbr_len]); nbr_len++, exp *= 10);
    exp /= 10;
    if (nbr_len == 0) return 0;
    while (char_is_num(*str)) {
        nbr += (*str - '0') * exp;
        exp /= 10;
        str++;
    }
    return nbr * sign;
}

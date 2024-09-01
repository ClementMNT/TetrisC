/*
** EPITECH PROJECT, 2021
** my_h
** File description:
** prototypes libmy
*/

#ifndef MY_H
    #define MY_H
    #include <math.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>

typedef struct node node;
struct node {
    int nbr;
    node *next;
};

typedef struct word word;
struct word {
    char *str;
    word *next;
};

node *rotate (node *root, node **ptra);
node *push (node *l_a, node **l_b, node **ptrb, int *cat_nbr);
node *full_cat (node **l_a, node **l_b, node **ptra, node **ptrb);
node *push_swap (node *l);

int my_getnbr (char *str);
char *int_to_char (int nbr);

int my_put_nbr (int nb);
void my_putchar (char c);
int my_putstr (char const *str);
int my_putarray (char * const *tab);

int char_is_alpha (char c);
int my_str_isalpha (char const *str);
int char_is_num (char c);
int my_str_isnum (char const *str);

word *str_split (char *path, char *cutter);
int true_cmp (char *str1, char *str2);
int my_strncmp (char *str1, char *str2, int n);
char *my_strcat (char *s1, char const *s2);
char *my_setmem (char *str, int len);
char *my_strdup (char const *src);
char *my_revstr(char *str);

int my_strlen (char const *str);
int my_linklen (node *ptr);
int my_arraylen (char **str);
int char_in_str (char *str, char c);

#endif

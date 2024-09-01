/*
** EPITECH PROJECT, 2021
** operators1
** File description:
** operators
*/

#include "my.h"

node *rotate (node *root, node **ptra)
{
    node *new_root = root->next;
    if (root->next == NULL)
        return root;
    root->next = NULL;
    (*ptra)->next = root;
    (*ptra) = (*ptra)->next;
    return new_root;
}

node *push (node *l_a, node **l_b, node **ptrb, int *cat_nbr)
{
    node *ptr = l_a;
    *cat_nbr = *cat_nbr + 1;
    if ((*l_b) == NULL) {
        (*l_b) = l_a;
        (*ptrb) = l_a;
        l_a = l_a->next;
        (*l_b)->next = NULL;
        cat_nbr++;
        return l_a;
    }
    l_a = l_a->next;
    ptr->next = NULL;
    (*ptrb)->next = ptr;
    (*ptrb) = (*ptrb)->next;
    return l_a;
}

node *full_cat (node **l_a, node **l_b, node **ptra, node **ptrb)
{
    if ((*l_a) != NULL) {
        (*ptra)->next = (*l_b);
        ((*ptrb) != NULL) ? (*ptra) = (*ptrb) : 0;
        (*l_b) = NULL;
        (*ptrb) = (*l_b);
    } else {
        (*l_a) = (*l_b);
        (*l_b) = NULL;
        (*ptra) = (*ptrb);
        (*ptrb) = NULL;
    }
    return NULL;
}

int my_linklen (node *ptr)
{
    int i = 0;
    for (;ptr != NULL;ptr = ptr->next, i++);
    return i;
}

node *push_swap (node *l)
{
    node *l_b = NULL, *ptra = NULL, *ptrb = l_b;
    int len = my_linklen(l), c = 0;
    for (ptra = l;ptra->next != NULL;ptra = ptra->next);
    for (long two = 1;two < 2147483648;two *= 2) {
        for (int i = 0;i < len;i++)
            l = ((l->nbr & two) != 0) ? push(l, &l_b, &ptrb, &c) :
            rotate(l, &ptra);
        full_cat (&l, &l_b, &ptra, &ptrb);
    }
    for (int i = 0;i < len;i++)
        l = ((l->nbr & 2147483648) == 0) ? push(l, &l_b, &ptrb, &c) :
        rotate(l, &ptra);
    full_cat (&l, &l_b, &ptra, &ptrb);
    return l;
}

/*
** EPITECH PROJECT, 2023
** organized
** File description:
** my_strtablen
*/

#include "../../include/my.h"

int my_strtablen(char **tab)
{
    int i;

    for (i = 0; tab[i] != NULL; ++i);
    return (i);
}

/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** my_strdup
*/

#include "../../include/my.h"
#include <stdlib.h>
#include <string.h>

char *my_strdup(char *str)
{
    char *str2 = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (str == NULL)
        return str;
    for (int i = 0; i <= my_strlen(str); i++)
        str2[i] = str[i];
    return str2;
}

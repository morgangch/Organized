/*
** EPITECH PROJECT, 2023
** number_management
** File description:
** File to keep funcs to manage IDs
*/

#include "shell.h"
#include <stdio.h>

int highest_number(void *data)
{
    node_t *list = (node_t *)data;
    int highest = 0;

    if (list == NULL)
        return 0;
    while (list != NULL) {
        if (list->id > highest)
            highest = list->id;
        list = list->next;
    }
    return highest;
}

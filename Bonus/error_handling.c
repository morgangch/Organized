/*
** EPITECH PROJECT, 2023
** organized
** File description:
** error_handling
*/

#include "shell.h"
#include <stdio.h>

int del_errors(node_t *node_to_delete, node_t *list)
{
    if (node_to_delete == NULL)
        return my_put_err("del: ID; Not found.\n");
    if (list == NULL)
        return my_put_err("del: List is empty.\n");
    return 0;
}

int add_errors(char **args, node_t *data)
{
    node_t **pdata = (node_t **)data;

    if (args[0] == NULL || args[1] == NULL || my_strtablen(args) < 2)
        return my_put_err("add: Not enough arguments.\n");
    if (my_strtablen(args) % 2 != 0)
        return my_put_err("add: Invalid arguments.\n");
    if (!data || !pdata)
        return my_put_err("add: Malloc; Memory allocations failed.\n");
    return 0;
}

int multi_cmp(const char *s1, char **s)
{
    int i = 0;

    while (s[i] != NULL) {
        if (my_strcmp(s1, s[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}
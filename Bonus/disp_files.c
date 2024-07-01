/*
** EPITECH PROJECT, 2023
** organized
** File description:
** disp_files
*/

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

void print_list_type(node_t *list, char *type)
{
    for (; list != NULL; list = list->next)
        if (my_strcmp(list->type, type) == 0)
            my_printf("%s n°%d - \"%s\"\n", list->type, list->id, list->name);
}

void print_list_id(node_t *list, int id)
{
    for (; list != NULL; list = list->next)
        if (id == list->id)
            my_printf("%s n°%d - \"%s\"\n", list->type, list->id, list->name);
}

void print_list_name(node_t *list, char *name)
{
    for (; list != NULL; list = list->next)
        if (my_strcmp(list->name, name) == 0)
            my_printf("%s n°%d - \"%s\"\n", list->type, list->id, list->name);
}

void print_list(node_t *list)
{
    for (; list != NULL; list = list->next)
        my_printf("%s n°%d - \"%s\"\n", list->type, list->id, list->name);
}

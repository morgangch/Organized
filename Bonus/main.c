/*
** EPITECH PROJECT, 2023
** organized
** File description:
** main
*/

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

static int free_node(node_t *node)
{
    free(node->name);
    free(node->type);
    free(node);
    return 0;
}

static void free_list(node_t *list)
{
    node_t *temp = NULL;

    while (list != NULL) {
        temp = list;
        list = list->next;
        free_node(temp);
    }
}

static int add_node(node_t **list, char *type, char *name)
{
    node_t *new = malloc(sizeof(node_t));
    node_t *current = NULL;

    new->name = name;
    new->type = type;
    new->next = NULL;
    if (*list == NULL) {
        new->id = 0;
        *list = new;
    } else {
        current = *list;
        while (current->next != NULL)
            current = current->next;
        new->id = current->id + 1;
        current->next = new;
    }
    return my_printf("%s n°%d - \"%s\" added.\n", new->type,
    new->id, new->name);
}

int add(void *data, char **args)
{
    node_t **pdata = (node_t **)data;
    int err = 0;
    int args_length = 0;
    char *types[] = {"WIRE", "DEVICES", "ACTUATOR", "PROCESSORS",
    "SENSORS", NULL};

    if (add_errors(args, data) == 84)
        return 84;
    args_length = my_strtablen(args);
    for (int i = 0; i < args_length; i += 2) {
        if (multi_cmp(args[i], types) == 1)
            return my_put_err("add: Invalid args; Invalid type.\n");
        err = add_node(pdata, my_strdup(args[i]), my_strdup(args[i + 1]));
        if (err == 84)
            return err;
    }
    return 0;
}

static node_t *find_node_by_id(node_t *list, int id, node_t **prev)
{
    node_t *current = list;

    *prev = NULL;
    while (current != NULL) {
        if (id == current->id)
            return current;
        *prev = current;
        current = current->next;
    }
    return NULL;
}

static int del_part(node_t **list, int id)
{
    node_t *prev = NULL;
    node_t *nget = find_node_by_id(*list, id, &prev);

    if (del_errors(nget, *list) == 84)
        return 84;
    my_printf("%s n°%d - \"%s\" deleted.\n", nget->type, nget->id, nget->name);
    if (nget == *list && nget->next == NULL) {
        free_node(nget);
        *list = NULL;
    } else {
        if (prev != NULL)
            prev->next = nget->next;
        else
            *list = nget->next;
        free_node(nget);
    }
    return 0;
}

int del(void *data, char **args)
{
    node_t **list = (node_t **)data;
    int err = 0;
    int tablen = my_strtablen(args);

    if (!data || !list)
        return my_put_err("del: Memory allocations failed.\n");
    for (int i = 0; i < tablen; i++) {
        err = del_part(list, my_getnbr(args[i]));
        if (err == 84)
            return err;
    }
    return 0;
}

int sort(void *data, char **args)
{
    (void) data;
    (void) args;
    return (0);
}

int disp(void *data, char **args)
{
    node_t *list = *(node_t **)data;

    if (!data || !list || data == NULL)
        return my_put_err("disp: Memory allocations failed.\n");
    if (!args[0])
        print_list(list);
    if (args[0] && my_strcmp(args[0], "NAME") == 0) {
        print_list_name(list, args[1]);
        return 0;
    }
    if (args[0] && my_strcmp(args[0], "TYPE") == 0)
        print_list_type(list, args[1]);
    else if (args[0] && my_strcmp(args[0], "ID") == 0)
        print_list_id(list, my_getnbr(args[1]));
    return 0;
}

int main(void)
{
    node_t *list = NULL;

    workshop_shell(&list);
    free_list(list);
}

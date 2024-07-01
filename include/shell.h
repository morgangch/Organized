/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H

typedef struct Node_s {
    char *name;
    char *type;
    int id;
    struct Node_s *next;
} node_t;

// To be implemented
int add(void *data, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data, char **args);
int highest_number(void *data);
int my_put_err(char const *str);
int my_printf(char *s, ...);
char *my_strdup(const char *s);
int my_strtablen(char **tab);
int my_strcmp(char const *s1, char const *s2);
int my_getnbr(char const *str);
int del_errors(node_t *node_to_delete, node_t *list);
void print_list_type(node_t *list, char *type);
void print_list_name(node_t *list, char *name);
void print_list_id(node_t *list, int id);
void print_list(node_t *list);
int multi_cmp(const char *s1, char **s);
int add_errors(char **args, node_t *data);

// Already implemented
int workshop_shell(void *data);

#endif /* SHELL_H */

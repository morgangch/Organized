/*
** EPITECH PROJECT, 2023
** Lib header
** File description:
** header for lib
*/

#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

static const char *const error_codes[] = {"None",
    "Wrong parameter", "Unknown error"};

int my_putchar(char);
long int my_put_nbr(long int);
int my_putstr(char const *);
int my_put_err(char const *);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int char_checker(va_list ap, char c);
int char_checker2(va_list ap, char c);
int my_printf(char *s, ...);
int my_put_err(char const *str);
int my_error_handler(int code);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcpy(char *dest, char const *src);
int my_unsigned_nbr(unsigned long int nb);
int my_strlen(char const *str);
int my_array_len(int *array);

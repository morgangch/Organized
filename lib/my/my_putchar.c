/*
** EPITECH PROJECT, 2023
** day07 - my_putchar
** File description:
** func to print char by char
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

/*
** EPITECH PROJECT, 2023
** libmy
** File description:
** my_array_len
*/

int my_array_len(int *array)
{
    int i = 0;

    while (array[i] != '\0')
        i++;
    return i;
}

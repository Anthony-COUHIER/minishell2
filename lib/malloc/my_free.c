/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_free_2d
*/

#include "lib.h"

void my_free_2d(char **array)
{
    int i = 0;

    if (array == NULL)
        return;
    while (array[i]) {
        free(array[i]);
        i++;
    }
    free(array);
}

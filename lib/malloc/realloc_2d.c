/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** my_realloc_2d
*/

#include "lib.h"

char **my_realloc_2d(char **table)
{
    int i = 0;
    int size = count_args(table) + 1;
    char **new = NULL;

    if (table == NULL)
        return NULL;
    new = malloc(sizeof(char *) * (size + 1));
    if (new == NULL)
        return NULL;
    for (i = 0; table[i]; i++)
        new[i] = table[i];
    new[i] = NULL;
    new[i + 1] = NULL;
    free(table);
    return new;
}

/*
** EPITECH PROJECT, 2020
** lib/str
** File description:
** count_args
*/

#include "lib.h"

int count_args(char **args)
{
    int i = 0;

    while (args[i])
        i++;
    return i;
}

/*
** EPITECH PROJECT, 2020
** lib/str
** File description:
** check_carac_alphanum
*/

#include "lib.h"

int check_alphanum(char *args)
{
    int pos = 0;

    while (args[pos]) {
        if (!(args[pos] >= 'a' && args[pos] <= 'z') &&
        !(args[pos] >= 'A' && args[pos] <= 'Z') &&
        !(args[pos] >= '0' && args[pos] <= '9') && args[pos] != '_')
            return -1;
        else
            pos++;
    }
    return 1;
}

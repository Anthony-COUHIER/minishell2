/*
** EPITECH PROJECT, 2020
** lib/str
** File description:
** my_strcmp
*/

#include "lib.h"

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] == str2[i])
            i++;
        else
            break;
    }
    if (str1[i] > str2[i])
        return 2;
    else if (str1[i] < str2[i])
        return 1;
    else
        return 0;
}

int my_strncmp(char *str1, char *str2, int max)
{
    int i = 0;

    while (str1[i] && str2[i] && i < max) {
        if (str1[i] == str2[i])
            i++;
        else
            break;
    }
    if (i == max)
        return 1;
    else
        return 0;
}

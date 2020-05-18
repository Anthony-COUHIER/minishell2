/*
** EPITECH PROJECT, 2020
** lib/str
** File description:
** transform_str_to_2d
*/

#include "lib.h"

char **str_to_double_str(char *str, char c)
{
    int i = 0;
    int pos = 0;
    int size = 0;
    int number = count_word(str, c);
    char **tmp = malloc(sizeof(char *) * (number + 1));

    if (!str || !tmp)
        return NULL;
    for (i = 0; i != number && str[pos]; i++, pos++) {
        size = size_word(str + pos, c);
        tmp[i] = my_strtok(str + pos, c);
        pos += size;
        for (; str[pos] && str[pos + 1] && str[pos + 1] == c; pos++);
    }
    tmp[i] = NULL;
    return tmp;
}

/*
** EPITECH PROJECT, 2020
** lib/str
** File description:
** word_count
*/

#include "lib.h"

int count_word(char *str, char c)
{
    int count = 0;

    for (int pos = 0; str[pos];) {
        while (str[pos] && str[pos] == c)
            pos++;
        if (str[pos])
            ++count;
        while (str[pos] && str[pos] != c)
            pos++;
    }
    return count;
}

int count_cara(char *str, char c)
{
    int nbr = 0;
    int i = 0;

    while (str[i++]) {
        if (str[i] == c)
            nbr++;
    }
    return nbr;
}

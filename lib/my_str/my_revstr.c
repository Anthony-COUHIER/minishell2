/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_revstr
*/

#include "lib.h"

char *my_revstr(char *str)
{
    int i = 0;
    int end;
    char stock;

    end = my_strlen(str) - 1;
    while (i < (my_strlen(str) / 2)) {
        stock = str[i];
        str[i] = str[end];
        str[end] = stock;
        i++;
        end--;
    }
    return (str);
}

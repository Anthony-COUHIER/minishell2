/*
** EPITECH PROJECT, 2020
** new_shell
** File description:
** get_args
*/

#include "proto.h"

int element_number(char *str)
{
    int element = 0;

    for (int i = 0; str[i];) {
        while (str[i] == ' ' && str[i])
            i++;
        if (str[i] == '\'' || str[i] == '\"') {
            i++;
            while (str[i] != '\'' && str[i] != '\"')
                i++;
        }
        if (str[i])
            ++element;
        while (str[i] != ' ' && str[i])
            i++;
    }
    return element;
}

int size_args(char *str, int pos)
{
    int size = 0;

    if (str[pos] == '"') {
        while (str[++pos] != '"')
            size++;
    } else if (str[pos] == '\'') {
        while (str[++pos] != '\'')
            size++;
    } else {
        while (str[pos] && str[pos] != '\n' && str[pos] != ' ') {
            size++;
            pos++;
        }
    }
    return size;
}

char **get_args(char *input)
{
    int j = 0;
    int size = 0;
    int pos = 0;
    int element = element_number(input);
    char **args = malloc(sizeof(char *) * (element + 1));

    for (j = 0; j != element && input[pos]; j++) {
        while (input[pos] && input[pos] == ' ')
            pos++;
        size = size_args(input, pos);
        pos += (input[pos] == '\'' || input[pos] == '"') ? 1 : 0;
        args[j] = my_strndup(input + pos, size);
        pos += size;
        pos += (input[pos] == '\'' || input[pos] == '"') ? 1 : 0;
    }
    args[j] = '\0';
    return args;
}

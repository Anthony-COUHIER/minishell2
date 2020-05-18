/*
** EPITECH PROJECT, 2020
** new_shell
** File description:
** semicolons
*/

#include "proto.h"

int get_size_command(char *input, char c)
{
    int i = 0;

    for (i = 0; input[i] && input[i] != c; i++) {
        if (input[i] == '\'' || input[i] == '\"') {
            i++;
            while (input[i] && input[i] != '\'' && input[i] != '\"')
                i++;
        }
    }
    return i;
}

int check_after_redirection(char *input, char c)
{
    for (int i = 0; input[i]; i++)
        if (input[i] != ' ' && input[i] != '\n' && input[i] != c)
            return 1;
    return 0;
}

int get_nbr_command(char *input, char c)
{
    int count = 1;

    for (int i = 0; input[i]; i++) {
        if (input[i] == '\'' || input[i] == '\"') {
            i++;
            while (input[i] && input[i] != '\'' && input[i] != '\"')
                i++;
            i++;
        }
        if (input[i] == c && check_after_redirection(input + i, c) == 1)
            count += 2;
    }
    return count;
}

char **split_command(char *input, char c)
{
    int nbr_command = get_nbr_command(input, c);
    char **command = malloc(sizeof(char *) * (nbr_command + 1));
    char *tmp = input;
    int size = 0;
    int i;

    for (i = 0; *tmp; i++) {
        size = get_size_command(tmp, c);
        command[i] = my_strndup(tmp, size);
        tmp += size;
        while (*tmp && (*tmp == ' ' || *tmp == c))
            tmp++;
    }
    command[i] = NULL;
    return command;
}

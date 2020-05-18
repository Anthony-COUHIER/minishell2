/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** split_redirection
*/

#include "proto.h"

char *get_files(char *line, char get, char stop)
{
    char *tmp = line;
    char *files = NULL;
    int size = 0;

    while (tmp[size] == ' ' || tmp[size] == get)
        size++;
    while (tmp[size] && tmp[size] != ' ' && tmp[size] != stop &&
    tmp[size] != get) {
        if (tmp[size] == '\'' || tmp[size] == '\"') {
            size++;
            while (tmp[size] != '\'' && tmp[size] != '\"')
                size++;
        }
        size++;
    }
    files = my_strndup(line, size);
    return files;
}

void erase_redirection(char *line, char get, char stop)
{
    int space = 0;
    int i = 0;

    while (line[i] && line[i] == get)
        line[i++] = ' ';
    for (; line[i] && line[i] != stop && line[i] != get; i++) {
        if (line[i] == '\'' || line[i] == '\"') {
            line[i++] = ' ';
            while (line[i] != '\'' && line[i] != '\"') {
                line[i++] = ' ';
            }
        }
        if (line[i] == ' ')
            space++;
        line[i] = ' ';
    }
}

static char *my_strstr_redirection(char *line, char get, char stop)
{
    char *redirection = NULL;

    while (*line) {
        if (*line == '\'' || *line == '\"') {
            line++;
            while (*line != '\'' && *line != '\"')
                line++;
        }
        if (*line == get) {
            redirection = get_files(line, get, stop);
            erase_redirection(line, get, stop);
            return redirection;
        }
        line++;
    }
    return NULL;
}

char ***get_redirection(char *line)
{
    char **split_pipe = split_command(line, '|');
    int nbr_pipe = count_args(split_pipe);
    char ***all = malloc(sizeof(char *) * (nbr_pipe + 1));

    for (int i = 0; split_pipe[i]; i++) {
        all[i] = malloc(sizeof(char *) * (3 + 1));
        all[i][0] = split_pipe[i];
        all[i][1] = my_strstr_redirection(all[i][0], '<', '>');
        all[i][2] = my_strstr_redirection(all[i][0], '>', '<');
        all[i][3] = NULL;
    }
    all[nbr_pipe] = NULL;
    return all;
}

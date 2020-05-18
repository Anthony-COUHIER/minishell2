/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** error_synthax
*/

#include "proto.h"
#include "my_error.h"

static int remove_useless_char(char **args)
{
    char **new = get_args(*args);
    int value_return = 0;
    char *tmp = *args;

    if (!new)
        return 1;
    if (new[0] && new[1]) {
        *args = my_strcat(new[0], new[1]);
        free(tmp);
    } else {
        value_return = 1;
    }
    my_free_2d(new);
    return value_return;
}

static int check_redirection(char **args)
{
    int i = 0;

    if (!*args)
        return 0;
    if (my_strcmp(*args, ">>") || my_strcmp(*args, "<<"))
        i += 2;
    else if (my_strcmp(*args, ">") || my_strcmp(*args, "<"))
        i += 1;
    else
        return 1;
    while ((*args)[i]) {
        if ((*args)[i] == '<' || (*args)[i] == '>')
            return 1;
        i++;
    }
    if (remove_useless_char(args))
        return 1;
    return 0;
}

static int check_redirection_command(char *args)
{
    for (int i = 0; args[i]; i++) {
        if (args[i] == '\'' || args[i] == '\"') {
            i++;
            while (args[i] != '\'' && args[i] != '\"')
                i++;
        }
        if (args[i] == '>' || args[i] == '<')
            return 1;
    }
    return 0;
}

int check_synthax_redirection(char ***args)
{
    if (!args)
        return 1;
    for (int j = 0; args[j]; j++) {
        if ((args[j][1] || args[j][2]) && args[j + 1]) {
            my_putstr(AMBIGUOUS_REDIRECTION);
            return 1;
        } else if (check_redirection_command(args[j][0]) ||
        check_redirection(&args[j][1]) || check_redirection(&args[j][2])) {
            return 1;
        }
    }
    return 0;
}

/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** init
*/

#include "proto.h"

char **cpy_env(char **env)
{
    int size = count_args(env);
    char **new = malloc(sizeof(char *) * (size + 1));
    int i = 0;

    for (i = 0; env[i]; i++)
        new[i] = my_strdup(env[i]);
    new[i] = NULL;
    return new;
}

void init(shell_t *shell, char **env)
{
    shell->env = cpy_env(env);
    shell->command[0] = "cd";
    shell->command[1] = "setenv";
    shell->command[2] = "unsetenv";
    shell->command[3] = NULL;
    shell->func[0] = my_cd;
    shell->func[1] = my_setenv;
    shell->func[2] = my_unsetenv;
    signal(SIGTSTP, SIG_IGN);
    signal(SIGINT, SIG_IGN);
}

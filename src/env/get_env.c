/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** get_env
*/

#include "proto.h"

char **get_path(char **env)
{
    char *all_path = grep_env(env, "PATH=");
    char **path;

    if (!all_path)
        all_path = my_strdup("");
    path = str_to_double_str(all_path, ':');
    free(all_path);
    return path;
}

int get_env(char **env, shell_t *shell)
{
    char *tmp;

    shell->path = get_path(env);
    for (int i = 0; shell->path[i]; i++) {
        tmp = shell->path[i];
        shell->path[i] = my_strcat(shell->path[i], "/");
        free(tmp);
    }
    return (!shell->path) ? -1 : 1;
}

/*
** EPITECH PROJECT, 2020
** new_shell
** File description:
** my_unsetenv
*/

#include "proto.h"

char **rm_env(char **env, int pos)
{
    int j = 0;
    int i = 0;
    int size = count_args(env);
    char **tmp = malloc(sizeof(char *) * (size));

    while (env[i]) {
        if (i != pos) {
            tmp[j] = env[i];
            j++;
        }
        i++;
    }
    tmp[j] = NULL;
    return tmp;
}

char **find_element_env(char **env, char *args)
{
    char *argv;
    char **tmp;

    argv = my_strcat_c(args, '=');
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], args, my_strlen(args)) == 1) {
            tmp = env;
            env = rm_env(tmp, i);
            free(tmp);
            free(argv);
            return env;
        }
    }
    free(argv);
    return env;
}

int my_unsetenv(shell_t *shell)
{
    if (count_args(shell->args) < 2) {
        my_printf("%s", "unsetenv: Too few arguments.\n");
        return 1;
    }
    for (int pos = 1; shell->args[pos]; pos++) {
        if (check_alphanum(shell->args[pos]) == -1)
            continue;
        shell->env = find_element_env(shell->env, shell->args[pos]);
    }
    return 0;
}

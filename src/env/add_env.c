/*
** EPITECH PROJECT, 2020
** new_shell
** File description:
** add_env
*/

#include "proto.h"

int find_pos_in_env(char **env, char *tmp)
{
    int pos = 0;

    for (; env[pos]; pos++) {
        if (my_strncmp(env[pos], tmp, my_strlen(tmp)))
            return pos;
    }
    return pos;
}

char *add_value_to_var(char *value, char *var)
{
    char *tmp_with_value;

    if (value != NULL) {
        tmp_with_value = var;
        var = my_strcat(var, value);
        free(tmp_with_value);
    }
    return var;
}

char **add_env(char **env, char *var, char *value)
{
    char *tmp = my_strcat(var, "=");
    int pos = 0;

    pos = find_pos_in_env(env, tmp);
    tmp = add_value_to_var(value, tmp);
    if (env[pos]) {
        free(env[pos]);
        env[pos] = my_strdup(tmp);
    } else {
        env = my_realloc_2d(env);
        env[pos] = tmp;
    }
    return env;
}

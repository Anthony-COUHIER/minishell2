/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** grep_env
*/

#include "proto.h"

char *grep_env(char **env, char *str)
{
    char *tmp;

    if (str == NULL || env == NULL)
        return NULL;
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], str, my_strlen(str)) == 1) {
            tmp = my_strndup(env[i] + my_strlen(str), my_strlen(env[i]));
            return tmp;
        }
    }
    return NULL;
}

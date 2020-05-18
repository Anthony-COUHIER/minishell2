/*
** EPITECH PROJECT, 2020
** new_shell
** File description:
** my_env
*/

#include "proto.h"

void my_env(shell_t *shell)
{
    for (int i = 0; shell->env[i]; i++)
        my_printf("%s\n", shell->env[i]);
    exit(0);
}

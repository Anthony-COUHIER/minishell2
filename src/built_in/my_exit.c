/*
** EPITECH PROJECT, 2020
** new_shell
** File description:
** my_exit
*/

#include "proto.h"

void my_exit(shell_t *shell, redirection_t *redirect)
{
    if (my_strcmp(shell->args[0], "exit") != 0)
        return;
    my_free_2d(shell->args);
    my_free_2d(shell->env);
    my_free_2d(shell->path);
    my_free_2d(shell->semicolons);
    my_free_3d(redirect->args_redirection);
    free(redirect->pp);
    exit(0);
}

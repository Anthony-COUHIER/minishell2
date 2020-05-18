/*
** EPITECH PROJECT, 2020
** new_shell
** File description:
** parse_args
*/

#include "proto.h"

void swap_exit(char **input_user, int i)
{
    char *tmp;

    if (input_user[i + 1] && my_strncmp(input_user[i], "exit", 4) == 1) {
        tmp = input_user[i];
        input_user[i] = input_user[i + 1];
        input_user[i + 1] = tmp;
    }
}

void parse_args_semicolons(shell_t *shell, char *input)
{
    shell->semicolons = split_command(input, ';');

    free(input);
    for (int i = 0; shell->semicolons[i]; i++) {
        swap_exit(shell->semicolons, i);
        prepare_execution(shell, i);
    }
    my_free_2d(shell->semicolons);
}

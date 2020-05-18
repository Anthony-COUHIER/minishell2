/*
** EPITECH PROJECT, 2020
** aze
** File description:
** main
*/

#include "proto.h"

int main(UNUSED int argc, UNUSED char **argv, char **env)
{
    shell_t shell;
    char *input;

    init(&shell, env);
    while (1) {
        if (get_env(shell.env, &shell) == -1)
            return 84;
        (isatty(STDIN_FILENO)) ? prompt(&shell) : 0;
        input = my_input();
        if (check_input(input) == 1) {
            parse_args_semicolons(&shell, input);
        }
        my_free_2d(shell.path);
    }
    return 0;
}

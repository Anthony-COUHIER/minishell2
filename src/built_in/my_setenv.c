/*
** EPITECH PROJECT, 2020
** new_shell
** File description:
** my_setenv
*/

#include "proto.h"
#include "my_error.h"

void check_error_setenv(shell_t *shell)
{
    if (!(shell->args[1][0] >= 'a' && shell->args[1][0] <= 'z') &&
    !(shell->args[1][0] >= 'A' && shell->args[1][0] <= 'Z') &&
    shell->args[1][0] != '_') {
        my_printf("setenv: Variable name must begin with a letter.\n");
    } else if (check_alphanum(shell->args[1]) == -1) {
        my_printf("%s", "setenv: Variable name must contain alphanumeric"
        " characters.\n");
    } else {
        shell->env = add_env(shell->env, shell->args[1], shell->args[2]);
    }
}

int my_setenv(shell_t *shell)
{
    int args = count_args(shell->args);

    if (args > 3) {
        my_printf("%s", SETENV_TOO_MANY_ARGS);
        return 1;
    } else if (args == 1) {
        free(shell->args[0]);
        shell->args[0] = my_strdup("env");
        return -1;
    } else {
        check_error_setenv(shell);
        return 0;
    }
}

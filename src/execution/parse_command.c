/*
** EPITECH PROJECT, 2020
** new_shell
** File description:
** parse_command
*/

#include "proto.h"

int parse_built_in(shell_t *shell, redirection_t *redirect)
{
    for (int i = 0; shell->command[i]; ++i) {
        if (my_strcmp(shell->command[i], shell->args[0]) == 0) {
            if (shell->func[i](shell) == -1)
                return 1;
            return 0;
        }
    }
    if (my_strcmp(shell->args[0], "exit") == 0)
        my_exit(shell, redirect);
    return 1;
}

void parse_executable(shell_t *shell)
{
    if (my_strcmp(shell->args[0], "env") == 0) {
        my_env(shell);
    } else
        find_exec(shell);
}

void manage_child(shell_t *shell, redirection_t *pipe, int i)
{
    pid_t pid = fork();

    if (pid == -1) {
        my_printf("%s", FORK_FAIL);
        return;
    } else if (pid == 0) {
        signal(SIGINT, sig_action);
        manage_pipe(pipe, i);
        close_pipe(pipe);
        parse_executable(shell);
    }
}

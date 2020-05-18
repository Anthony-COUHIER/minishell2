/*
** EPITECH PROJECT, 2020
** new_shell
** File description:
** get_info_redirection
*/

#include "proto.h"
#include "my_error.h"

int *start_pipe(int nbr_pipe)
{
    int *pp = malloc(sizeof(int) * (nbr_pipe * 2));

    for (int i = 0; i < (2 * nbr_pipe);) {
        pipe(pp + i);
        i += 2;
    }
    return pp;
}

void parent_pipe(redirection_t *redirect)
{
    int status;

    close_pipe(redirect);
    for (int my_wait = 0; my_wait < redirect->nbr_pipe + 1; my_wait++) {
        if (wait(&status) == -1)
            perror("Perror ");
        my_signal(status);
        status = 0;
    }
    free(redirect->pp);
    my_free_3d(redirect->args_redirection);
}

redirection_t fill_struct_to_execution(shell_t *shell, int pos)
{
    redirection_t new;

    new.args_redirection = get_redirection(shell->semicolons[pos]);
    new.nbr_pipe = get_number_command(new.args_redirection);
    new.pp = start_pipe(new.nbr_pipe);
    return new;
}

void prepare_execution(shell_t *shell, int pos)
{
    redirection_t redirect = fill_struct_to_execution(shell, pos);
    int built_in = 0;

    if (check_synthax_redirection(redirect.args_redirection)) {
        return my_free_3d(redirect.args_redirection);
    }
    for (int i = 0; redirect.args_redirection[i]; i++) {
        shell->args = get_args(redirect.args_redirection[i][0]);
        if (parse_built_in(shell, &redirect)) {
            manage_child(shell, &redirect, i);
            built_in = 0;
        } else
            built_in = 1;
        my_free_2d(shell->args);
    }
    if (built_in == 0)
        parent_pipe(&redirect);
}

/*
** EPITECH PROJECT, 2020
** new_shell
** File description:
** manage_redirection
*/

#include "proto.h"
#include "my_error.h"

void close_pipe(redirection_t *redirect)
{
    for (int j = 0; j < (redirect->nbr_pipe * 2); j++)
        close(redirect->pp[j]);
}

static int check_redirection(char *args)
{
    if (my_strncmp(args, ">>", 2) || my_strncmp(args, "<<", 2)) {
        return 2;
    } else if (my_strncmp(args, ">", 1) || my_strncmp(args, "<", 1)) {
        return 1;
    } else
        return 0;
}

static void manage_redirection_right(char *args)
{
    int redirection = check_redirection(args);
    int fd = 0;

    args += redirection;
    if (redirection == 1) {
        fd = open(args, FLAG_RESET_FILES);
    } else if (redirection == 2) {
        fd = open(args, FLAG_END_FILES);
    }
    if (!fd)
        exit(0);
    dup2(fd, 1);
    close(fd);
}

static void manage_redirection_left(char *args)
{
    int redirection = check_redirection(args);
    int fd = 0;

    if (redirection == 1) {
        fd = open(args + redirection, O_RDONLY);
    } else {
        return;
    }
    dup2(fd, 0);
    close(fd);
}

void manage_pipe(redirection_t *pipe, int pos)
{
    if (pipe->args_redirection[pos + 1]) {
        dup2(pipe->pp[(pos * 2) + 1], 1);
    }
    if (pipe->args_redirection[pos][1]) {
        manage_redirection_left(pipe->args_redirection[pos][1]);
    }
    if (pipe->args_redirection[pos][2]) {
        manage_redirection_right(pipe->args_redirection[pos][2]);
    }
    if ((pos * 2) - 2 >= 0)
        dup2(pipe->pp[(pos * 2) - 2], 0);
}

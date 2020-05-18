/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** signal
*/

#include "proto.h"
#include "my_signal.h"

void sig_action(int sig)
{
    (void) sig;
    write(0, "\n", 1);
}

void my_signal(int status)
{
    int value;

    if (WIFSIGNALED(status)) {
        value = WTERMSIG(status);
        my_printf("%s", sign[value]);
        if (__WCOREDUMP(status)) {
            my_printf(" (core dumped)\n");
        } else
            my_putstr("\n");
    }
}

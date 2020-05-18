/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** get_number_command
*/

#include "proto.h"

int get_number_command(char ***line)
{
    int count = 0;

    while (line[count + 1])
        count++;
    return count;
}

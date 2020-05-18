/*
** EPITECH PROJECT, 2020
** new_shell
** File description:
** check_input
*/

#include "proto.h"

int check_input(char *input)
{
    for (int i = 0; input[i]; i++)
        if (input[i] != ' ' && input[i] != ';')
            return 1;
    return 0;
}

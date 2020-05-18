/*
** EPITECH PROJECT, 2020
** new_shell
** File description:
** check_formating
*/

#include "proto.h"

int check_formating(char *input)
{
    for (int i = 0; input[i]; i++) {
        if (input[i] == '"') {
            while (input[++i] && input[i] != '"');
            if (input[i] != '"') {
                my_printf("%s", "Unmatched '\"'\n");
                return -1;
            }
        } else if (input[i] == '\'') {
            while (input[++i] && input[i] != '\'');
            if (input[i] != '\'') {
                my_printf("%s", "Unmatched '\''\n");
                return -1;
            }
        }
    }
    for (int i = 0; input[i]; i++)
        if (input[i] != ' ' && input[i] != ';')
            return 0;
    return -1;
}

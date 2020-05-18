/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_free_3d
*/

#include "proto.h"

void my_free_3d(char ***array)
{
    for (int j = 0; array[j]; j++) {
        for (int i = 0; array[j][i]; i++)
            free(array[j][i]);
        free(array[j]);
    }
    free(array);
}

/*
** EPITECH PROJECT, 2020
** lib
** File description:
** input
*/

#include "lib.h"

char *my_input(void)
{
    char buff = 0;
    char *save = NULL;
    char *tmp = malloc(sizeof(char) * 1);

    tmp[0] = '\0';
    while (buff != 10) {
        if (read(0, &buff, 1) <= 0) {
            free(tmp);
            return my_strdup("exit\n");
        }
        if (buff == '\t')
            buff = ' ';
        if (buff != '\n') {
            save = tmp;
            tmp = my_strcat_c(tmp, buff);
            free(save);
        }
    }
    return tmp;
}

/*
** EPITECH PROJECT, 2019
** Lib/my_printf
** File description:
** putchar
*/

#include "lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

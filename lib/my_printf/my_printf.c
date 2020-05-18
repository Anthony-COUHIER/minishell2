/*
** EPITECH PROJECT, 2019
** lib/my_printf
** File description:
** my_printf
*/

#include "lib.h"

void my_printf(char *str, ...)
{
    va_list ap;
    va_start(ap, str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '%') {
            my_putchar(str[i]);
            continue;
        }
        i++;
        (str[i] == '%') ? write(1, "%%", 1) : 0;
        (str[i] == 'c') ? my_putchar(va_arg(ap, int)) : 0;
        (str[i] == 's') ? my_putstr(va_arg(ap, char *)) : 0;
        (str[i] == 'S') ? double_char(va_arg(ap, char **)) : 0;
        (str[i] == 'd' || str[i] == 'i') ? my_put_nbr_dec(va_arg(ap, int)) : 0;
        if (str[i] != '%' && str[i] != 'c' && str[i] != 's' &&
        str[i] != 'S' && str[i] != 'd' && str[i] != 'i') {
            my_putchar('%');
            my_putchar(str[i]);
        }
    }
    va_end(ap);
}

void my_putstr(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    write(1, str, i);
}

void double_char(char **str)
{
    for (int i = 0; str[i]; i++) {
        my_putstr(str[i]);
        write(1, "\n", 1);
    }
}

int is_neg(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    return (nb);
}

void my_put_nbr_dec(int nb)
{
    long long res = 0;
    long long div = 1;

    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return;
    }
    nb = is_neg(nb);
    if (nb == 0)
        my_putchar('0');
    for (; nb % div != nb; div = div * 10);
    div = div / 10;
    for (long long trop = 0; div >= 1; ) {
        res = nb / div - trop * 10;
        trop = nb / div;
        div = div / 10;
        my_putchar(res + '0');
    }
}

/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** number_colone
*/

int my_atoi(char *str)
{
    int res = 0;
    int count = 0;

    for (int i = 0; str[i] != '\n'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            res = res * 10;
            res = res + str[i] - '0';
        } else if (str[i] == '-')
            count++;
        else {
            (count % 2 == 1) ? res *= -1 : 0;
            return (res);
        }
    }
    (count % 2 == 1) ? res *= -1 : 0;
    return (res);
}

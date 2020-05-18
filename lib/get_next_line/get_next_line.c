/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** main
*/

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *str;
    char *tmp = NULL;
    static int pos = 0;
    int i = 0;

    if (fd < 0 || READ_SIZE < 1)
        return NULL;
    str = get_next_line_my_line(fd, pos);
    if (str == NULL || str[pos] == '\0') {
        free(str);
        return NULL;
    }
    for (int count = pos; str[count] != '\n' && str[count]; i++, count++);
    if (!(tmp = malloc(sizeof(char) * i + 1)))
        return NULL;
    for (int j = 0; str[pos] != '\n' && str[pos]; pos++, j++)
        tmp[j] = str[pos];
    pos++;
    tmp[i] = '\0';
    return tmp;
}

char *get_next_line_my_line(int fd, int pos)
{
    static char *str1;
    char *str2 = malloc(sizeof(char) * READ_SIZE + 1);

    if (str2 == NULL)
        return NULL;
    for (int i = 0; i < READ_SIZE; str2[i] = '\0', i++);
    if (str1 == NULL) {
        str1 = malloc(sizeof(char) * READ_SIZE + 1);
        str1[0] = '\0';
    }
    while (read(fd, str2, READ_SIZE)) {
        str1 = get_next_line_strcat(str1, str2);
        if (get_next_line_check_line(str1, pos) == 1)
            return str1;
        else if (get_next_line_check_line(str1, pos) == -1)
            return NULL;
        str2 = malloc(sizeof(char) * READ_SIZE + 1);
        for (int i = 0; i < READ_SIZE; i++, str2[i] = '\0');
    }
    free(str2);
    return str1;
}

int get_next_line_check_line(char *str, int pos)
{
    if (str == NULL || str[pos] == '\0')
        return -1;
    for (; str[pos] != '\n' && str[pos]; pos++);
    if (str[pos] == '\n')
        return 1;
    else
        return 0;
}

char *get_next_line_strcat(char *str1, char *str2)
{
    int pos = 0;
    int size1 = get_next_line_strlen(str1);
    char *tmp = malloc(sizeof(char) * (size1 + 1 + READ_SIZE));

    if (tmp == NULL)
        return NULL;
    for (int i = 0; i < size1; i++, pos++)
        tmp[pos] = str1[i];
    for (int i = 0; i < READ_SIZE; i++, pos++)
        tmp[pos] = str2[i];
    tmp[pos] = '\0';
    free(str2);
    free(str1);
    return tmp;
}

int get_next_line_strlen(char *str)
{
    int size = 0;

    while (str[size])
        size++;
    return size;
}

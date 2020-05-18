/*
** EPITECH PROJECT, 2020
** Lib
** File description:
** lib
*/

#ifndef LIB_H_
#define LIB_H_

#include "get_next_line.h"
#include "define.h"
#include "fcntl.h"
#include "stdlib.h"
#include "stdarg.h"
#include "unistd.h"
#include "color.h"

void my_printf(char *format, ...);
void my_put_nbr_dec(int nb);
int is_neg(int nb);
void my_putstr(char *str);
void my_putchar(char c);
void double_char(char **str);

void my_free_2d(char **str);
char **my_realloc_2d(char **table);

int my_strlen(char *str);
char *my_strcat(char *str1, char *str2);
int my_strcmp(char *str1, char *str2);
int my_strncmp(char *str1, char *str2, int max);
char *my_strdup(char *str);
char *my_strndup(char *str, int max);
char *my_strtok(char *str, char c);
char *my_strcat_c(char *str1, char c);
char **str_to_double_str(char *str, char c);
int count_word(char *str, char c);
int size_word(char *str, char c);
int count_args(char **args);
int check_alphanum(char *args);

char *my_input(void);
int my_atoi(char *str);
#endif /* !LIB_H_ */

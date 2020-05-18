/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_strlen
*/

#include "proto.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/types.h>

Test(test_grep_env_ok_value, test_opt)
{
    char *env[] = {"TERM=xterm-256color"};
    char *str = "TERM=";
    char *ok = "xterm-256color";

    cr_assert_str_eq(grep_env(env, str), ok);
}

Test(test_grep_str_bad_value, test_opt)
{
    char *env[] = {"TERM=xterm-256color"};
    char *str = "BAD=";

    cr_assert_eq(grep_env(env, str), NULL);
}

Test(test_grep_str_null, test_opt)
{
    char *env[] = {"TERM=xterm-256color"};
    char *str = NULL;

    cr_assert_eq(grep_env(env, str), NULL);
}

Test(test_grep_env_null_str_null, test_opt)
{
    char **env = 0;
    char *str = NULL;

    cr_assert_eq(grep_env(env, str), NULL);
}

Test(test_grep_env_null, test_opt)
{
    char **env = 0;
    char *str = "TERM=";

    cr_assert_eq(grep_env(env, str), NULL);
}

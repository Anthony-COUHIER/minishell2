/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** prompt
*/

#include "proto.h"

char *get_prompt(char *tmp, char *prompt, int j, int pos)
{
    char *cpy = my_strndup(prompt + j, my_strlen(prompt));
    char *new;

    tmp[pos] = '\0';
    new = my_strcat(tmp, cpy);
    free(prompt);
    free(tmp);
    free(cpy);
    return new;
}

char *change_prompt(char *prompt, char *home)
{
    int j = 0;
    int pos = 0;
    char *new;
    char *tmp;
    int word = count_word(prompt, '/');

    if (my_strncmp(prompt, home, my_strlen(home)) == 1 &&
    count_word(home, '/') != 0) {
        j = my_strlen(home);
        word = word - count_word(home, '/');
        tmp = malloc(sizeof(char) * (word + 3) + 1);
        tmp[pos++] = '~';
    } else
        tmp = malloc(sizeof(char) * (word * 2) + 1);
    for (int i = 1; prompt[j] && i < word; i++) {
        tmp[pos++] = prompt[j++];
        tmp[pos++] = prompt[j++];
        for (; prompt[j] != '/'; j++);
    }
    new = get_prompt(tmp, prompt, j, pos);
    return new;
}

void prompt(shell_t *info)
{
    char *prompt = NULL;
    char *home = grep_env(info->env, "HOME=");
    char *user = grep_env(info->env, "USER=");

    if (!home)
        home = my_strdup("");
    prompt = getcwd(prompt, 0);
    if (prompt == NULL)
        perror("");
    if (home[my_strlen(home) - 1] == '/')
        home = my_strndup(home, my_strlen(home));
    prompt = (home && prompt) ? change_prompt(prompt, home) : 0;
    (user) ? my_printf(NORMAL"%s ", user) : 0;
    (prompt) ? my_printf(GREEN"%s", prompt) : 0;
    my_printf(NORMAL"> ");
    free(prompt);
    free(home);
    free(user);
}

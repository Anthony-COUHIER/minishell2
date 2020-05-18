/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** exec
*/

#include "proto.h"
#include "my_error.h"

void error_exec(shell_t *shell)
{
    struct stat sts;

    if (stat(shell->args[0], &sts) == 0) {
        if ((sts.st_mode & __S_IFMT) == __S_IFDIR) {
            my_printf("%s%s", shell->args[0], NO_PERM);
        } else
            my_printf("%s%s", shell->args[0], WRONG_FORMAT);
    } else
        my_printf("%s%s", shell->args[0], NO_COMMAND);
}

int count_c(char *str, char c)
{
    int nbr = 0;
    int i = 0;

    while (str[i++]) {
        if (str[i] == c)
            nbr++;
    }
    return nbr;
}

void find_exec_with_path(shell_t *shell)
{
    if (count_c(shell->args[0], '/') != 0) {
        if (execve(shell->args[0], shell->args, shell->env) == -1) {
            error_exec(shell);
            exit(1);
        }
        return;
    }
    my_printf("%s%s", shell->args[0], NO_COMMAND);
    exit(1);
}

int check_path(char *path, char *exec)
{
    DIR *directory = opendir(path);
    struct dirent *RDIR;

    while ((RDIR = readdir(directory)) != NULL)
        if (my_strcmp(RDIR->d_name, exec) == 0) {
            closedir(directory);
            return 1;
        }
    closedir(directory);
    return -1;
}

void find_exec(shell_t *shell)
{
    char *path = NULL;

    for (int i = 0; shell->path[i]; i++) {
        if (check_path(shell->path[i], shell->args[0]) == 1) {
            path = my_strcat(shell->path[i], shell->args[0]);
            if ((execve(path, shell->args, shell->env)) == -1) {
                perror(shell->args[0]);
                exit(-1);
            }
            return;
        }
    }
    find_exec_with_path(shell);
}

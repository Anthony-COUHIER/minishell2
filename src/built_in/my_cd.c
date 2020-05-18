/*
** EPITECH PROJECT, 2020
** new_shell
** File description:
** my_cd
*/

#include "proto.h"
#include "my_error.h"

static char *move_to_new_directory(char **args, char **env, char *save)
{
    char *tmp;
    char *home;
    char *path = NULL;

    if (args[1][0] == '~') {
        path = my_strndup(args[1] + 1, my_strlen(args[1]));
        tmp = path;
        home = grep_env(env, "HOME=");
        path = my_strcat(home, path);
        free(home), free(tmp);
    } else if (my_strcmp(args[1], "-") == 0) {
        path = my_strdup(save);
    } else
        path = my_strdup(args[1]);
    return path;
}

static int check_files(char *path)
{
    struct stat sts;

    if (path && stat(path, &sts) == 0) {
        if ((sts.st_mode & __S_IFMT) != __S_IFDIR) {
            my_printf("%s%s", path, NO_DIR);
            return 1;
        } else if (!(sts.st_mode & S_IXUSR)) {
            my_printf("%s%s", path, BAD_PERM);
            return 1;
        }
    }
    return 0;
}

static int move_cd(shell_t *info, char *path, char *old_path, char *save)
{
    if (check_files(path))
        return 1;
    if (!save && !path && my_strcmp(info->args[1], "-") == 0) {
        write(1, ": No such file or directory.\n", 29);
        return 1;
    } else if (my_strlen(path) > 0 && chdir(path) != 0) {
        my_printf("%s%s", info->args[1], BAD_TARGET);
        return 1;
    } else {
        info->env = add_env(info->env, "OLDPWD", old_path);
        info->env = add_env(info->env, "PWD", getcwd(NULL, 0));
        return 0;
    }
    (save) ? free(save) : 0;
    (path) ? free(path) : 0;
    (old_path) ? free(old_path) : 0;
}

int my_cd(shell_t *info)
{
    int return_value = 0;
    int args = count_args(info->args);
    char *path = NULL;
    char *old_path = NULL;
    char *save = NULL;

    if (args > 2) {
        my_putstr(TOO_MANY_ARGS);
        return 1;
    }
    old_path = grep_env(info->env, "PWD=");
    save = grep_env(info->env, "OLDPWD=");
    if (args == 1)
        path = grep_env(info->env, "HOME=");
    else
        path = move_to_new_directory(info->args, info->env, save);
    return_value = move_cd(info, path, old_path, save);
    return return_value;
}

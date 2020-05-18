/*
** EPITECH PROJECT, 2020
** new_shell
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct shell_s
{
    char **env;
    char **args;
    char **path;
    int (*func[3])(struct shell_s *info);
    char *command[4];
    char **semicolons;
} shell_t;

typedef struct redirection_s
{
    char ***args_redirection;
    int *pp;
    int nbr_pipe;
} redirection_t;

#endif /* !STRUCT_H_ */

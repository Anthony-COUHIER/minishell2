/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** error
*/

#ifndef ERROR_H_
#define ERROR_H_

/*
** CD
*/
#define TOO_MANY_ARGS "cd: Too many arguments.\n"
#define NO_DIR ": Not a directory.\n"
#define BAD_TARGET ": No such file or directory.\n"
#define BAD_PERM ": Permission denied.\n"

/*
** SETENV
*/
#define SETENV_TOO_MANY_ARGS "setenv: Too many arguments.\n"
#define SETENV_BEGIN_LETTER "setenv: Variable name must begin with a letter.\n"
#define SETENV_WRONG_CHAR "setenv: Variable name must contain alphanumeric \
characters.\n"

/*
** EXECUTION
*/
#define FORK_FAIL "Failed forking child..\n"
#define NO_COMMAND ": Command not found.\n"
#define NO_PERM ": Permission denied.\n"
#define WRONG_FORMAT ": Exec format error. Wrong Architecture.\n"

/*
** REDIRECTION
*/
#define NO_LINKED_PIPE "Invalid null command.\n"
#define NO_REDIRECTION "Missing name for redirect.\n"
#define AMBIGUOUS_REDIRECTION "Ambiguous output redirect.\n"

#endif /* !ERROR_H_ */

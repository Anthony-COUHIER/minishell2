/*
** EPITECH PROJECT, 2020
** aze
** File description:
** proto
*/

#ifndef PROTO_H_
#define PROTO_H_

#include "my_error.h"
#include "struct.h"
#include "../lib/include/lib.h"

#include "sys/types.h"
#include "sys/stat.h"
#include "sys/wait.h"
#include "sys/resource.h"
#include "sys/time.h"
#include "string.h"
#include "signal.h"
#include "dirent.h"
#include "fcntl.h"
#include "stdio.h"
#include "errno.h"

#define FLAG_END_FILES O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IRGRP | \
S_IWGRP | S_IWUSR
#define FLAG_RESET_FILES O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | \
S_IWGRP | S_IWUSR

/*
** INIT
*/
void init(shell_t *shell, char **env);
// Get data to env
int get_env(char **env, shell_t *info);

/*
** CHECK
*/
// Check quotes and doubles quotes (" " and ' ')
int check_formating(char *input);
// Check if the command has caractere
int check_input(char *input);
// Check synthax redirection
int check_synthax_redirection(char ***argv);

/*
** PROMPT
*/
void prompt(shell_t *info);


/*
** ENV
*/
// Find something in end, value with '='
char *grep_env(char **env, char *value);
// Add something in end, value without '='
char **add_env(char **env, char *var, char *value);


/*
** PARSE ARGS
*/
// Split command with rules to (" " and ' ')
char **split_command(char *input, char value);
// Just a while for semicolons
void parse_args_semicolons(shell_t *shell, char *input);
// Execute in child (binary or env)
void manage_child(shell_t *shell, redirection_t *pipe, int i);
// Find build_in
int parse_built_in(shell_t *shell, redirection_t *redirect);
// Manage pipe
void manage_pipe(redirection_t *redirect, int pos_command);
// Close all pipe
void close_pipe(redirection_t *redirect);

/*
** EXECUTION
*/
// Split command to redirection and pipe
char ***get_redirection(char *line);
// Get data of redirection and pipe
void prepare_execution(shell_t *shell, int pos);
// Get Number of command
int get_number_command(char ***line);
// Get the command to execute and its args
char **get_args(char *input);
// Execution binary
void find_exec(shell_t *shell);


/*
** SIGNAL
*/
void sig_action(int sig);
// Print message error child
void my_signal(int status);

/*
** EXIT
*/
// Exit shell
void my_exit(shell_t *shell, redirection_t *redirect);


/*
** BUILT_IN
*/
// Change directory
int my_cd(shell_t *info);
// Print env
void my_env(shell_t *info);
// Add variable to env
int my_setenv(shell_t *info);
// Remove variable to env
int my_unsetenv(shell_t *info);

/*
** FREE
*/
// FREE 3D
void my_free_3d(char ***array);
#endif /* !PROTO_H_ */

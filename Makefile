##
## EPITECH PROJECT, 2020
## PSU_minishell2_2019
## File description:
## Makefile
##

NAME	= mysh

CC	= gcc

RM	= rm -f

SRCS	= ./src/main.c \
		./src/built_in/my_cd.c \
		./src/built_in/my_env.c \
		./src/built_in/my_exit.c \
		./src/built_in/my_setenv.c \
		./src/built_in/my_unsetenv.c \
		./src/check/check_formating.c \
		./src/check/check_input.c \
		./src/env/add_env.c \
		./src/env/get_env.c \
		./src/env/grep_env.c \
		./src/execution/redirection/error_synthax.c \
		./src/execution/redirection/get_redirection.c \
		./src/execution/redirection/get_number_command.c \
		./src/execution/redirection/manage_pipe.c \
		./src/execution/redirection/split_redirection.c \
		./src/execution/exec.c \
		./src/execution/get_args.c \
		./src/execution/parse_args.c \
		./src/execution/parse_command.c \
		./src/execution/semicolons.c \
		./src/execution/signal.c \
		./src/free/my_free_3d.c \
		./src/prompt/prompt.c \
		./src/init.c

TESTS	= ./src/env/grep_env.c \
		./tests/my_grep_env.c

NAME_UT	= unit_tests

LIB 	= ./lib/lib.a

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra
CFLAGS += -g3
LDFLAGS += -lncurses --coverage -lcriterion

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(LIB)

clean:
	make -C lib/ clean
	$(RM) $(OBJS) *.gcda *.gcno

fclean: clean
	make -C lib/ fclean
	$(RM) $(NAME) $(NAME_UT)

re: fclean all

tests_run :
	make -C ./lib/
	$(CC) -o $(NAME_UT) $(TESTS) $(CFLAGS) $(LIB) $(LDFLAGS)
	./unit_tests

.PHONY: all clean fclean re

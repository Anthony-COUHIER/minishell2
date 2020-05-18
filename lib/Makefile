##
## EPITECH PROJECT, 2020
## lib
## File description:
## Makefile
##

NAME	= lib.a

RM	= rm -f

SRCS	= ./my_printf/my_printf.c \
	  ./my_printf/my_write.c \
	  ./malloc/realloc_2d.c \
	  ./malloc/my_free.c \
	  ./get_next_line/get_next_line.c \
	  ./my_str/my_strcat.c \
	  ./my_str/my_strcmp.c \
	  ./my_str/my_strdup.c \
	  ./my_str/my_strlen.c \
	  ./my_str/str_to_double_str.c \
	  ./my_str/word_count.c \
	  ./my_str/count_args.c \
	  ./my_str/my_revstr.c \
	  ./my_str/size_word_str.c \
	  ./my_str/check_carac_alphanum.c \
	  ./input.c \
	  ./my_atoi.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -g3

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

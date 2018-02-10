##
## EPITECH PROJECT, 2018
## Malloc
## File description:
## Makefile compiling the library
##

CC	=	gcc

RM	=	rm -rf

CFLAGS	=	-I ../include/		\
		-W -Wall -Wextra

TUFLAGS	=	-lcriterion --coverage

NAME 	=	tests

SRCS	=	tests.c			\
		../src/show_alloc_mem.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(TUFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re

##
## EPITECH PROJECT, 2018
## Malloc
## File description:
## Makefile compiling the library
##

CC	=	gcc

RM	=	rm -rf

CP	=	cp -rf

ARCHV	=	ar cr

CFLAGS	=	-I ../include/	\
		-W -Werror -Wall -Wextra	\
		-fPIC

NAME 	=	libmy_malloc.so

SRCS	=	malloc.c	\
			malloc_align.c	\
			show_mem_alloc.c	\
			free.c	\
			block.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) -shared -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re

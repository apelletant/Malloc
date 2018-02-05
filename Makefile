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

CFLAGS	=	-I ./include/		\
		-W -Wall -Wextra	\
		-fPIC

NAME 	=	libmy_malloc.so

SRCS	=	main.c			\
		src/free.c		\
		src/malloc.c		\
		src/show_alloc_mem.c	\
		src/realloc.c		\

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

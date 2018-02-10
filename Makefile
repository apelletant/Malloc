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

MK	=	make

TESTS	=	tests

CFLAGS	=	-I include/		\
		-W -Wall -Wextra	\
		-fPIC

LDFLAGS =	-pthread

NAME 	=	libmy_malloc.so

SRCS	=	src/free.c		\
		src/malloc.c		\
		src/show_alloc_mem.c	\
		src/realloc.c		\

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -shared -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

tests_run: re
	$(MK) -C $(TESTS)
	LD_PRELOAD=$(NAME) ./$(TESTS)/$(TESTS)

re:	fclean all

.PHONY: all clean fclean re

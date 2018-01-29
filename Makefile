##
## EPITECH PROJECT, 2018
## Malloc
## File description:
## Makefile compiling the library
##

CC	= gcc -Wall -Wextra -W -c

RM	= rm -f

CP	= cp -r

CFLAGS	= -I ./include/

ARCHV	= ar rc

SRCS	= main.c		\
	  src/block.c		\
	  src/free.c		\
	  src/malloc.c		\
	  src/malloc_align.c	\
	  src/show_mem_alloc.c	\

OBJS	= $(SRCS:.c=.o)

NAME 	= libmy_malloc.so

all:	$(NAME)

$(NAME): $(OBJS)
	$(ARCHV) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re

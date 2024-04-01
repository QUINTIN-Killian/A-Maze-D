##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard src/*.c)

OBJS =	$(SRC:.c=.o)

NAME	=	amazed

LIB	=	-L lib/my/ -lmy

HSRC	=	include/amazed.h

CFLAGS	=	-g3

all: create

create: ${OBJS}
		make -C lib/my
		gcc -o $(NAME) $(OBJS) -I ${HSRC} ${LIB}

clean:
		rm -f lib/my/*.o
		rm -f src/*.o

fclean:clean
		rm -f lib/my/libmy.a
		rm -f $(NAME)

re: fclean all

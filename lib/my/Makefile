##
## EPITECH PROJECT, 2023
## undefined
## File description:
## Makefile for mylib
## Makefile
##

CC	=	gcc
SRC	=	$(wildcard *.c)
OBJ	=	$(SRC:.c=.o)
H_NAME	=	my.h
LIB_NAME	=	libmy.a

all:	$(LIB_NAME)

$(LIB_NAME):	$(OBJ)
	ar rc $(LIB_NAME) $(OBJ)
	cp $(LIB_NAME) ../..
	cp $(H_NAME) ../../include

%.o:	%.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(LIB_NAME) ../../$(LIB_NAME)

re:	fclean all

.PHONY:	all clean fclean re

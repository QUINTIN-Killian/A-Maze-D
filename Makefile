##
## EPITECH PROJECT, 2023
## undefined
## File description:
## Makefile to compile files with the lib.
## Makefile
##

CC	=	gcc
SRC	=	$(wildcard *.c)
OBJ	=	$(SRC:.c=.o)
CFLAGS	=	-g3 -W -Wall
EXEC	=	amazed

all:	compile_lib $(EXEC)

compile_lib:
	make -C lib/my

$(EXEC):	$(OBJ)
	$(CC) -o $(EXEC) $(OBJ) -L. -lmy $(CFLAGS)

%.o:	%.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean:	clean
	rm -f $(EXEC)
	make fclean -C lib/my

re:	fclean all

.PHONY:	all compile_lib clean fclean re
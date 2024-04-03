##
## EPITECH PROJECT, 2023
## undefined
## File description:
## Makefile to compile files with the lib.
## Makefile
##

CC	=	gcc

SRC	=	src/draw_robots.c	\
		src/draw_rooms.c	\
		src/file.c	\
		src/functions.c	\
		src/main.c	\
		src/my_scanf.c	\
		src/error_handling.c	\
		src/recognition.c	\
		src/end.c	\
		src/room.c	\
		src/robot.c

OBJ	=	$(SRC:src/%.c=bin/%.o)

CFLAGS	=	-g3 -W -Wall

EXEC	=	amazed

all:	compile_lib $(EXEC)

compile_lib:
	make -C lib/my

$(EXEC):	$(OBJ)
	$(CC) -o $(EXEC) $(OBJ) -L. -lmy $(CFLAGS)

bin/%.o:	src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean:	clean
	rm -f $(EXEC)
	make fclean -C lib/my

re:	fclean all

.PHONY:	all compile_lib clean fclean re

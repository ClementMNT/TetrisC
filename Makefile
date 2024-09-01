##
## EPITECH PROJECT, 2021
## tetris
## File description:
## Makefile
##

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

all:
	make -C lib/my
	$(MAKE)	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -Llib -lmy -g3 -W -Wall -Werror -Wextra -lncurses

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	make fclean -C	lib/my

re:	fclean all

##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## the makefile
##

SRC	=	pong.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra

NAME	=	101pong

CC	=	gcc

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lm

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

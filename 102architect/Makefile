##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## the makefile
##

SRC	=	architech.c	\
		operation.c	\
		del_zeros.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror

NAME	=	102architech

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

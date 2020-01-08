##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## the makefile
##

SRC	=	cipher.c	\
		print_matrix.c	\
		fill_matrix.c	\
		encryption.c	\
		decryption.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror

NAME	=	103cipher

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

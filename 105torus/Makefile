##
## EPITECH PROJECT, 2017
## Project 105torus
## File description:
## Build 105torus binary.
##

MAIN_SRC	=	src/main.c

SRC	=	src/utils/help.c	\
		src/utils/free.c	\
		src/utils/input.c	\
		src/utils/my_str_isnum.c	\
		src/bisection.c	\
		src/newton.c	\
		src/secant.c

UT_SRC	=	tests/inter_cone_test.c

OBJ	=	$(MAIN_SRC:.c=.o) $(SRC:.c=.o)

UT_OBJ	=	$(SRC:.c=.o) $(UT_SRC:.c=.o)

CFLAGS	=	-Werror -Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable -I ./include/

LDFLAGS	=	-lm

NAME	=	105torus

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(UT_OBJ)
	find . -name "*.gcda" -type f -delete
	find . -name "*.gcno" -type f -delete

fclean: clean
	rm -f $(NAME)
	rm -f units

re: fclean all

test_run:	$(UT_OBJ)
		gcc -o units $(UT_OBJ) $(LDFLAGS) $(CFLAGS)
		./units

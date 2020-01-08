##
## EPITECH PROJECT, 2017
## Project 104intersection
## File description:
## Build 104intersection binary.
##

MAIN_SRC	=	src/main.c

SRC	=	src/utils/input.c	\
		src/utils/help.c	\
		src/utils/free.c	\
		src/utils/my_str_isnum.c	\
		src/inter_cone.c	\
		src/inter_sphere.c	\
		src/inter_cylindre.c	\
		src/utils/print_result.c

UT_SRC	=	tests/inter_cone_test.c

OBJ	=	$(MAIN_SRC:.c=.o) $(SRC:.c=.o)

UT_OBJ	=	$(SRC:.c=.o) $(UT_SRC:.c=.o)

CFLAGS	=	-Werror -Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable -I ./include/ -lm

LDFLAGS	=	-lcriterion -lm

NAME	=	104intersection

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

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

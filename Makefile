##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile my lib
##

SRC =	src/my_printf.c			\
	src/my_put_nbr_pf.c		\
	src/my_putstr_pf.c		\
	src/my_putchar_pf.c		\
	src/my_putchar.c		\
	src/my_put_nbr_base.c		\
	src/my_put_nbr_hexadecimal.c	\
	src/my_put_nbr_hexadecimal_p.c	\
	src/my_strdup.c			\
	src/handle_formats.c		\
	src/main.c

SRC_TEST =	src/my_printf.c		\
	src/my_put_nbr_pf.c		\
	src/my_putstr_pf.c		\
	src/my_putchar_pf.c		\
	src/my_putchar.c		\
	src/my_put_nbr_base.c		\
	src/my_put_nbr_hexadecimal.c	\
	src/my_put_nbr_hexadecimal_p.c	\
	src/handle_formats.c		\
	src/my_strdup.c			\
	tests/test_my_printf.c

OBJ	=	$(SRC:.c=.o)

OBJ_TEST= 	$(SRC_TEST:.c=.o)

NAME	= libmy.a

NAME_TEST = unit_tests

NAME_CLASSIC = program

CFLAGS = -W -Wall -Wextra -I include

CC = gcc

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	rm src/*.o

classic:	$(OBJ)
	$(CC) -o $(NAME_CLASSIC) $(CFLAGS) $(OBJ)
	rm src/*.o

tests_run:	$(OBJ_TEST)
	$(CC) -o $(NAME_TEST) $(SRC_TEST) $(CFLAGS) -lcriterion --coverage
	rm src/*.o
	./unit_tests

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_TEST)
	rm -f $(NAME_CLASSIC)

re:	fclean all

auteur:
	echo $(USER) > auteur

.PHONY: all clean fclean re

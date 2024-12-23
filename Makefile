##
## EPITECH PROJECT, 2017
## evalexpr
## File description:
## Makefile
##

SRC	=	SRC/my_putchar.c		\
		SRC/my_putstr.c			\
		SRC/my_put_nbr.c		\
		SRC/my_strlen.c			\
		SRC/do_op_inf.c			\
		SRC/call_evalexpr.c		\
		SRC/call_infadd.c		\
		SRC/clean_str.c			\
		SRC/clean_result.c		\
		SRC/add_neg.c			\
		SRC/my_swap.c			\
		SRC/call_infmult.c		\
		SRC/my_getnbr.c			\
		SRC/my_find_longest.c		\
		SRC/my_strcpy.c			\
		SRC/check_error.c		\
		SRC/my_strdup.c			\
		SRC/translate.c			\
		SRC/evalexpr_fonction.c		\
		main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -W -Wall -Wextra -Werror

NAME	=	calc

$(NAME):	$(OBJ)
	gcc $(SRC) -o $(NAME) -g

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

all:	$(NAME)
re:	fclean all

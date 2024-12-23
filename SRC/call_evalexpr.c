/*
** EPITECH PROJECT, 2017
** evalexpr
** File description:
** main.c
*/
#include <stdlib.h>
#include "../include/evalexpr.h"
#include "../include/inf_add.h"
#include "../include/my.h"

char *my_find_number(char **parse, int len)
{
	int signe = 0;
	int lenght = 0;

	if (**parse == '+' || **parse == '-') {
		if (**parse == '-')
    			signe = -1;
    		*parse = *parse + 1;
	}
	if (**parse == '(')
		restart_evalexpr(parse, len, signe);
	while('0' <= **parse && **parse <= ('0' + len - 1)) {
		lenght++;
		*parse = *parse + 1;
	}
	*parse -= lenght;
	return (create_number(lenght, signe, parse, len));
}
char *eval_expr_start(char **parse, int len)
{
	char *left_nb = NULL;
	char *right_nb = NULL;
	char operator = 0;

	left_nb = my_find_number(parse, len);
	while (**parse != '\0' && **parse != ')') {
		operator = **parse;
		*parse = *parse + 1;
		if (operator == '+' || operator == '-')
			right_nb = eval_expr_complex(parse, len);
		else
			right_nb = my_find_number(parse, len);
		left_nb = do_op_inf(left_nb, right_nb, operator, len);
	}
	left_nb = kill_neg(left_nb);
	left_nb = clean_result(left_nb);
	left_nb = my_strdup(left_nb);
	return (left_nb);
}
char *eval_expr_complex(char **parse, int len)
{
	char *left_nb = NULL;
	char *right_nb = NULL;
	char operator;

	left_nb = my_find_number(parse, len);
	while (**parse == '*' || **parse == '/' || **parse == '%') {
		operator = **parse;
		*parse = *parse + 1;
		right_nb = my_find_number(parse, len);
		left_nb = do_op_inf(left_nb, right_nb, operator, len);
	}
	left_nb = my_strdup(left_nb);
	free(right_nb);
	return (left_nb);
}
char *call_evalexpr(char *str, char *base)
{
	int len = my_strlen(base);

	if (str[0] == '\0')
		return(NULL);
	else
		return (eval_expr_start(&str, len));
}

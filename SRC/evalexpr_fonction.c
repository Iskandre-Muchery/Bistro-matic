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

char *create_number(int lenght, int signe, char **parse, int len)
{
	char *number = NULL;

	number = malloc((sizeof(char) * lenght) + 2);
		if (number == NULL)
			return(NULL);
	*(number + lenght + 2) = '\0';
	*(number) = (signe > 0) ? '\0' : '-';
	number++;
	while('0' <= **parse && **parse <= ('0' + len - 1)) {
		*number = **parse;
		*parse = *parse + 1;
		number++;
	}
	number = number - lenght + signe;
	return (number);
}
char *restart_evalexpr(char **parse, int len, int signe)
{
	char *number = NULL;

	*parse = *parse + 1;
    	number = eval_expr_start(parse, len);
	if (**parse == ')')
		*parse = *parse + 1;
	if (signe < 0)
		number = add_neg(number);
    	return (number);
}
char *kill_neg(char *str)
{
	int neg = 0;
	int count = 0;
	char *copy = NULL; 

	while (str[count] == '-') {
		neg++;
		count++;
		if (neg == 2) {
			copy = malloc(my_strlen(str) + 1);
			copy[my_strlen(str)] = '\0';
			copy = my_strcpy(copy, str + count);
			str = copy;
			neg = 0;
		}
	}
	return(str);
}

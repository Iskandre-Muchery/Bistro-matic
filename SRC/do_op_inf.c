/*
** EPITECH PROJECT, 2017
** evalexpr
** File description:
** do_op.c
*/

#include <stdlib.h>
#include "../include/evalexpr.h"
#include "../include/inf_add.h"
#include "../include/my.h"
char *concat_str_char(char *str, char c)
{
	char *copy = NULL;
	int size = my_strlen(str);
	int count = 0;

	copy = malloc(sizeof(char) * size + 1);
	if (c == '-' && (str[0] == '-')) {
		copy[0] = '+';
	}
	else
		copy[0] = c;
	while (count <= size) {
		copy[count + 1] = str[count];
		count++;
	}
	copy[count] = '\0';
	return (copy);
}
char *do_op_inf(char *nb1, char *nb2, char operator, int len)
{
	switch (operator) {
        case '+':
		nb2 = concat_str_char(nb2, operator);
		return (call_infadd(nb1, nb2, len));
            break;
        case '-':
		nb2 = concat_str_char(nb2, operator);
		return (call_infadd(nb1, nb2, len));
            break;
       case '*':
		return (call_infmult(nb1, nb2, len));
            break;
/*
        case '/':
            return (nb1 / nb2);
            break;
        case '%':
            return (nb1 % nb2);
            break;*/
        default:
            return (0);
            break;
	}
	return (NULL);
}

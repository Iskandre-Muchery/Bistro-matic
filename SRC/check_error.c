/*
** EPITECH PROJECT, 2017
** evalexpr
** File description:
** main.c
*/

#include "../include/evalexpr.h"
#include "../include/inf_add.h"
#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>

void check_base (char const *b)
{
	if (my_strlen(b) < 2) {
		my_putstr("syntax error\n");
		exit(84);
	}
}
void check_ops (char const *ops)
{
	if (my_strlen(ops) != 7) {
	my_putstr("syntax error\n");
	exit (84);
	}
}
void check_error(int ac, char **av)
{
	if (ac != 4) {
		my_putstr("USAGE\n\t\t./calc base operators size_read\n\n");
		my_putstr("DESCRIPTION\n\t   base\t     all the symbole of");
		my_putstr(" the base\n\t   operators the symbols for the ");
		my_putstr("parentheses and the 5 operators\n\t   ");
		my_putstr("size_read number of characters to be read\n");
		exit(84);
	}
	check_base(av[1]);
	check_ops(av[2]);
}

/*
** EPITECH PROJECT, 2017
** evalexpr
** File description:
** main.c
*/

#include "include/evalexpr.h"
#include "include/inf_add.h"
#include "include/my.h"
#include "include/main.h"
#include <stdlib.h>
#include <unistd.h>

void catch_str(int sizeBuffer, char *str)
{
	char buffer[sizeBuffer];
	int count = 0;

	buffer[sizeBuffer] = '\0';
	while (count < sizeBuffer) {
		buffer[count] = '0';
		count++;
	}
	read(0, buffer, sizeBuffer);
	my_strcpy(str, buffer);
	str[sizeBuffer] = '\0';
}
void get_base(char *base, int size)
{
	int count = 0;

	while (count < size) {
		base[count] = count + '0';
		count++;
	}
	base[count] = '\0';
}
int	main(int ac, char **av)
{
	char base[my_strlen(av[1])];
	int sizeBuffer = my_getnbr(av[3]);
	char str[sizeBuffer];
	char *result = NULL;

	check_error(ac, av);
	get_base(base, my_strlen(av[1]));
	catch_str(sizeBuffer, str);
	translate_to_operators(str, av[2]);
	result = call_evalexpr(str, base);
	translate_to_base(result, av[1], base);
	my_putstr(result);
	my_putchar('\n');
	free(result);
	return (0);
}



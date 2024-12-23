
/*
** EPITECH PROJECT, 2017
** my_print_alpha.c
** File description:
** 
*/
#include <unistd.h>

void my_putchar(char c)
{
	write (1, &c, 1);
}

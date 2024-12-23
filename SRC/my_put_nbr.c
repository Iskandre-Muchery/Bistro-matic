/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** 
*/

#include "../include/my.h"

int my_put_nbr(int nb)
{
	int start_value;
	int end_value;
	
	if (nb < 0)
	{
		my_putchar('-');
		my_put_nbr(nb * -1);
	}
	else
	{
		end_value = nb % 10;
		start_value = nb / 10;
		if (start_value != 0)
		{
			my_put_nbr(start_value);
		}
		my_putchar(end_value + '0');
	}
	return (end_value);
}

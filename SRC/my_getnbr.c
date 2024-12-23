/*
** EPITECH PROJECT, 2017
** rush1
** File description:
** 
*/
#include "../include/my.h"

int my_compute_power_rec(int nb, int p)
{
	int result = 1;

	if (p == 0)
		return(1);
	if (p < 0)
		return(0);
	result = nb * my_compute_power_rec(nb, p-1);
	return(result);
}
int create_nb(char const *str, int power)
{
	int nb = 0;
	int i = 0;

	while (i<power) {
		nb = nb + (str[i] - 48) * my_compute_power_rec(10, power-1-i);
		i++;
	}
	return (nb);
}
int my_getnbr(char const *str)
{
	int nbr = 0;
	int i= 0;
	int n = 0;

	while (str[i] != '\0') {
		n = 0;
		while (str[i+n] >= 48 &&  str[i+n] <= 57) {
			n++;
		}
		if (n != 0) {
			nbr = create_nb(str+i, n);
			if (str[i-1] == 45)
				nbr = nbr * -1;
			return (nbr);
		}
	i++;
	}
	return (0);
}

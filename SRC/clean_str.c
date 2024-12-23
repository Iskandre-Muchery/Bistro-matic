/*
** EPITECH PROJECT, 2017
** my_compute_power_rec.c
** File description:
** 
*/
#include "../include/inf_add.h"
#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

int replace_neg(char *str)
{
	int count = 0;

	while (str[count] == '-' || str[count] == '+') {
		str[count] = '0';
		count++;
	}
	return (0);
}
char *change_size(char *str, int size)
{
	char *copy;
	int count = 0;
	int diff = 0;

	copy = malloc((sizeof(char) * size) + 1);
	if (copy == NULL)
		return (NULL);
	diff = size - my_strlen(str);
		while (count < diff) {
			copy[count] = '0';
			count++;
		}
		count = 0;
		while (str[count] != '\0') {
			copy[diff + count] = str[count];
			count++;
		}
	copy[count + diff + 2] = '\0';
	return (copy);
}
char *balance_size(int size, char *str)
{
	if (my_strlen(str) < size)
		str = change_size(str, size);
	return (str);
}
char *clean_str(char *str, int size)
{
	replace_neg(str);
	str = balance_size(size, str);

	return (str);
}

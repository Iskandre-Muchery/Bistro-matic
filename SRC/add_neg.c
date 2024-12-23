/*
** EPITECH PROJECT, 2017
** my_compute_power_rec.c
** File description:
** 
*/
#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

char *add_neg(char *str)
{
	char *copy;
	int i = 1;
	int n = my_strlen(str);

	copy = malloc( n + 2 );
	while (str[i - 1] != '\0') {
		copy[i] = str[i-1];
		i++;
	}
	copy[0] = '-';
	copy[i] = '\0';
	return (copy);	
}

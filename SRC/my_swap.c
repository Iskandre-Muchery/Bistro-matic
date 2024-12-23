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

char *find_longest(char *s1, char *s2)
{
	if (my_strlen(s1) > my_strlen(s2))
		return (s1);
	else
		return (s2);
}
int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;

	while(s1[i] != '\0' || s2[i] != '\0' ){
		if(s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		else
			i++;
	}
	return (0);
}
int my_swap(char **ptr_1, char **ptr_2)
{
	char *save;
	int max = 1;

	if (my_strcmp(*ptr_1, *ptr_2) < 0) {
		save = *ptr_1;
		*ptr_1 = *ptr_2;
		*ptr_2 = save;
		max = 2;
	}
	return (max);
}

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

char *clean_result(char *result)
{
	int size = my_strlen(result);
	int count = 0;
	int zero = 0;
	char *copy = NULL;

	if (result[0] == '-') {
		copy = clean_result(result + 1);
		copy = add_neg(copy);
		return (copy);
	} else {
		while(result[count] == '0' && result[count + 1] != '\0') {
			count++;
			zero++;
		}
		copy = malloc(sizeof(char) * (size - count));
		if (copy == NULL)
			return (NULL);
		count = 0;
		while ( result[count] != '\0' ) {
			copy[count] = result[count + zero];
			count++;
		}
	}
	return (copy);
}

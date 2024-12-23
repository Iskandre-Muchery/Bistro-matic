/*
** EPITECH PROJECT, 2017
** rush1
** File description:
** 
*/
#include <string.h>
#include <stdlib.h>
#include "../include/my.h"

char *my_strdup(char *src)
{
	char *copy = NULL;
	int i = 0;

	copy = malloc(my_strlen(src) + 1);
	while (src[i] != '\0' ) {
		copy[i] = src[i];
		i++;
	}
	return (src);
}

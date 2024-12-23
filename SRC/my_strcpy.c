/*
** EPITECH PROJECT, 2017
** evalexpr
** File description:
** do_op.c
*/

#include <stdlib.h>
#include "../include/evalexpr.h"
#include "../include/inf_add.h"
#include "../include/my.h"
char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	while (*(src+i) != '\0') {
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

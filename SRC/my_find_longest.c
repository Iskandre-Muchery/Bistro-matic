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

char *my_find_longest(char *s1, char *s2)
{
	if (my_strlen(s1) > my_strlen(s2))
		return (s1);
	else
		return (s2);
}

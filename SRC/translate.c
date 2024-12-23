/*
** EPITECH PROJECT, 2017
** evalexpr
** File description:
** main.c
*/

#include "include/evalexpr.h"
#include "include/inf_add.h"
#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>

void translate_to_operators(char *str, char *oldOperators)
{
	int count = 0;
	char operators[7] = "()+-*/%";

	while (*str != '\0') {
		count = 0;
		while (count < 6) {
			if (*str == oldOperators[count])
				*str = operators[count];
			count++;
		}		
		str++;
	}
}
void translate_to_base(char *str, char *base, char *Tbase)
{
	int size = my_strlen(str);
	int count = 0;
	int incr = 0;

	while (count < size) {
		incr = 0;
		while (Tbase[incr] != '\0') {
			if (str[count] == Tbase[incr]) {
				str[count] = base[incr];
			}
			incr++;
		}
		count++;
	}
}

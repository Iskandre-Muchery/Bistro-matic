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

int scan_neg(char *s1, char *s2)
{
	int cpt = 0;
	int neg = 0;
	int size1 = my_strlen(s1);
	int size2 = my_strlen(s2);

	while (cpt < size1) {
		if (s1[cpt] == '-')
			neg = 1;
		cpt++;
	}
	cpt = 0;
	while (cpt < size2) {
		if (s2[cpt] == '-' && (neg > 0))
			return (3);
		if (s2[cpt] == '-' && (neg == 0))
			return (2);
		cpt++;
	}
	return (neg);
}
char *addition(char *s1, char *s2, int len)
{
	int size = my_strlen(s1);
	int count = size;
	int retenue = 0;
	char *result = NULL;

	result = malloc(sizeof(char) * size + 2);
	if (result == NULL)
		return (NULL);
	result[size + 1] = '\0';
	while (count > 0) {
		if (s1[count - 1] + s2[count - 1] + retenue - '0' > '0' + len - 1) {
			result[count] = s1[count - 1] + s2[count - 1] + retenue - ('0' + len);
			retenue = 1;
		} else {
			result[count] = s1[count - 1] + s2[count - 1] + retenue - '0';
			retenue = 0;
		}
		count--;
	}
	result[0] = retenue + '0';
	return (result);
}
char *soustraction(char *max, char *min, int len)
{
	int size = my_strlen(max);
	int count = size - 1;
	int retenue = 0;
	char *result = NULL;

	result = malloc(sizeof(char) * size + 1);
	if (result == NULL)
		return (NULL);
	result[size] = '\0';
	while (count >= 0) {
		if ((max[count] - min[count] - retenue + '0') < '0') {
			result[count] = max[count] - min[count] - retenue + '0' + len;
			retenue = 1;
		} else {
			result[count] = max[count] - min[count] - retenue + '0';
			retenue = 0;
		}
		count--;
	}
	return (result);
}

char *call_infadd(char *s1, char *s2, int len)
{
	int neg = scan_neg(s1, s2);
	char *result = NULL;
	int size = my_strlen(my_find_longest(s1, s2));
	int max = 1;

	s1 = clean_str(s1, size);
	s2 = clean_str(s2, size);
	max = my_swap(&s1, &s2);

	if (neg == 3 || neg == 0) {
		result = addition(s1, s2, len);
	}
	else {
		result = soustraction(s1, s2, len);
	}
	result = clean_result(result);
	if ((neg == max || neg == 3) && (result[0] != '0'))
		result = add_neg(result);
	return (result);
}

/*
** EPITECH PROJECT, 2017
** my_compute_power_rec.c
** File description:
** 
*/
#include "../include/my.h"
#include "../include/inf_add.h"
#include <stdlib.h>

int reset_to_next_addition(char *s2, int *cnt2, char **result, int *reset)
{

		if (s2[(*cnt2)] == '0') {
			*result = *result - 1;
			*cnt2 = *cnt2 - 1;
		} else if ((*cnt2 - 1) >= 0) {
			*result = *result + (*reset) - 1;
			*cnt2 = *cnt2 - 1;
		} else
			return (84);
		*reset = 0;
		return (0);
}
char *do_infmult (char *s1, char *s2, char *result, int len)
{
	int size = my_strlen(my_find_longest(s1, s2));
	int cnt1 = size - 1;
	int cnt2 = size  - 1;
	int reset = 0;

	while (cnt2 >= 0 && s2[cnt2] != 0) {
		cnt1 = size - 1;
		while (cnt1 >= 0 && s2[cnt2] != '0') {
			if(((s1[cnt1] - '0') * (s2[cnt2] - '0') + (*result - '0') + '0') > '0' + len - 1) {
				*(result - 1) = ((*result - '0') + (s1[cnt1] - '0') * (s2[cnt2] - '0')) / len + '0'  + (*(result - 1) - '0') ;
				*result = ((*result - '0') + (s1[cnt1] - '0') * (s2[cnt2] - '0')) % len + '0';
			} else
				*result = (*result - '0') + (s1[cnt1] - '0') * (s2[cnt2] - '0') + '0';
			reset++;
			result--;
			cnt1--;
		}
		if(reset_to_next_addition(s2, &cnt2, &result, &reset) == 84)
			break;
	}
	return (result);
}
int scan_neg_mult(char *s1, char *s2)
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
		if (s2[cpt] == '-' && (neg == 0))
			neg = 1;
		else if (s2[cpt] == '-' && (neg == 1))
			neg = 2;
		if(s2[cpt] == '-' && neg > 1)
			return (84);
		cpt++;
	}
	return (neg);
}
char *create_result(int size, char *result)
{
	int count = size * 2;

	result = malloc((size * 2) + 1);
	if (result == NULL)
		return (NULL);
	result[count] = '\0';
	while (count > 0) {
		result[count - 1] = '0';
		count--;
	}
	result += size * 2 - 1;
	return (result);
}
char *call_infmult(char *s1, char *s2, int len)
{
	char *result = NULL;
	int size = my_strlen(my_find_longest(s1, s2));;
	int neg = 0;
	
	neg = scan_neg_mult(s1, s2);
	s1 = clean_str(s1, size);
	s2 = clean_str(s2, size);
	result = create_result(size, result);
	result = do_infmult(s1, s2, result, len);
	result = clean_result(result);
	if ((neg % 2) != 0 && (result[0] != '0'))
		result = add_neg(result);
	return (result);
}

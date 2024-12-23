/*
** EPITECH PROJECT, 2017
** my_print_alpha.c
** File description:
** 
*/

int my_strlen(char *str)
{
	int i = 0;

	while((str[i]) != '\0') {
		i = i + 1;
	}
	return(i);
}

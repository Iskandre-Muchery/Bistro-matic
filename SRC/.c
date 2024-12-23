/*
** EPITECH PROJECT, 2017
** get base
** File description:
** func that get the base for calc
**/

void get_base(char *str)
{
	int base_long = 0;
	
	while (*str != '\0') {
		while (*str >= '0' && *str <= '9') {
			base_long++;
		}
		*str++;
	}
}

int base_Decimal(char *str)
{
	int nbr = 0;

	while ()
}
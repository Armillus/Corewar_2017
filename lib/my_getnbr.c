/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** basic function
*/

#include <stdlib.h>

int my_getnbr(char *str)
{
	int i = 0;
	int b = 0;

	while (str[i] != '\0') {
		if (str[i] < '0' || str[i] > '9')
			exit(84);
		if (str[i] >= '0' && str[i] <= '9') {
			b = b * 10 + (str[i] - 48);
			i++;
		} else
			i++;
	}
	return (b);
}

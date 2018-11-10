/*
** EPITECH PROJECT, 2018
** my_isdigit.c
** File description:
** my_isdigit.c
*/

#include "../include/my.h"
#include "../op/op.h"

int my_isdigit(char *str, int j)
{
	for (int i = j; i < my_strlen(str); i++) {
		if (str[i] < '0' || str[i] > '9')
			return (1);
	}
	return (0);
}

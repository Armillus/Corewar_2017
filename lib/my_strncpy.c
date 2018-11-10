/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** basic function
*/

#include "../include/asm.h"

char *my_strncpy(char *str, int p)
{
	if (!str || p >= my_strlen(str))
		return (str);
	str[p] = 0;
	return (str);
}

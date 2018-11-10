/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** task01 Day06
*/

#include "../include/vm.h"
#include <stdlib.h>

char *my_strcpy(char *src)
{
	char *cpy = NULL;
	int i = 0;

	if (!src)
		return (NULL);
	cpy = malloc(sizeof(char) * (my_strlen(src) + 1));
	if (!cpy)
		return (NULL);
	for (i = 0; src[i] != 0; i++)
		cpy[i] = src[i];
	cpy[i] = 0;
	return (cpy);
}

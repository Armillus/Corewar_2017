/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** basic function
*/

#include "../include/asm.h"

char *my_strdup(char *src)
{
	char *dest = NULL;
	int i = 0;

	if (!src)
		return (NULL);
	dest = malloc(sizeof(char) * (my_strlen(src) + 1));
	if (!dest)
		return (NULL);
	for (i = 0; src[i]; dest[i] = src[i], i++);
	dest[i] = '\0';
	return (dest);
}

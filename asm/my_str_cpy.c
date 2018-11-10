/*
** EPITECH PROJECT, 2018
** my_str_cpy
** File description:
** basic function
*/

#include "../include/asm.h"

char *my_str_cpy(char *dest, char *str)
{
	int i = 0;
	char *tmp = NULL;

	if (!str) {
		free(dest);
		return (NULL);
	}
	tmp = my_clean_str(my_strdup(str));
	dest = malloc(sizeof(char) * (my_strlen(tmp) + 1));
	if (!dest)
		return (NULL);
	for (i = 0; tmp[i]; i++)
		dest[i] = tmp[i];
	dest[i] = '\0';
	free(tmp);
	return (dest);
}

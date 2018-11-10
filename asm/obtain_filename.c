/*
** EPITECH PROJECT, 2018
** useful_functions
** File description:
** useful functions for the asm
*/

#include "../include/asm.h"

char *obtain_my_filename(char *name)
{
	char *dest = NULL;
	char *tmp = ".cor";
	int i = 0;
	int count = 0;
	int j = 0;

	for (i = 0; name[i]; i++) {
		if (name[i] == '/')
			count = i + 1;
	}
	dest = malloc(sizeof(char) * (my_strlen(name) - count + 3));
	for (i = count; name[i] != '.'; dest[j] = name[i], j++, i++);
	for (i = 0; tmp[i]; dest[j] = tmp[i], i++, j++);
	dest[j] = '\0';
	return (dest);
}

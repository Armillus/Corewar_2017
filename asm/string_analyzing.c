/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** Analyze and sometimes, modify a string
*/

#include "../include/asm.h"

int is_empty(char *str)
{
	unsigned int i = 0;

	if (!str)
		return (0);
	if (my_strcmp(str, "") == 0 || my_strcmp(str, " ") == 0)
		return (0);
	while (str[i]) {
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

char *analyze_my_token_str(char *str)
{
	char *dest = NULL;

	if (!str)
		return (NULL);
	dest = my_strdup(str);
	free(str);
	str = my_str_char_cat(dest, LABEL_CHAR);
	return (str);
}

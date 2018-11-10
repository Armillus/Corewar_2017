/*
** EPITECH PROJECT, 2018
** my_clean_str
** File description:
** main function
*/

#include "../include/asm.h"

char *my_str_char_cat(char *str, char c)
{
	int len = 0;
	char *dest = NULL;
	int i = 0;

	if (str == NULL) {
		dest = malloc(sizeof(char) * 2);
		dest[0] = c;
		dest[1] = '\0';
		free(str);
		return (dest);
	}
	len = my_strlen(str) + 1;
	if ((dest = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	dest[len] = '\0';
	for (i = 0; str[i] != '\0'; dest[i] = str[i], i++);
	dest[i] = c;
	free(str);
	return (dest);
}

int find_my_last_char(char *str)
{
	int len = 0;

	if (!str)
		return (0);
	len = my_strlen(str);
	for (; len > 0; len--) {
		if (str[len] != ' ' && str[len] != '\t')
			return (len + 1 > 0 ? len + 1 : 1);
	}
	return (len);
}

char *my_clean_str(char *str)
{
	int count = 0;
	int end = find_my_last_char(str);

	if (!str)
		return (NULL);
	for (int i = 0; str[count] && str[i] && i < end; i++, count++) {
		if ((str[i] == ' ' || str[i] == '\t') &&
		(count == 0 || str[i + 1] == 0))
			count--;
		else if (str[i] == ' ' || str[i] == '\t') {
			str[count] = ' ';
			for (; str[i] == ' ' || str[i] == '\t'; i++);
			i--;
		}
		else
			str[count] = str[i];
	}
	str[count] = 0;
	return (str);
}

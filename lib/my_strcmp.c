/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** basic function
*/

#include "../include/asm.h"

int my_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++);
	return (i);
}

void my_putstr(char *str)
{
	if (!str)
		return;
	write(1, str, my_strlen(str));
}

int my_strcmp(char *str, char *str2)
{
	int i = 0;

	if (!str || !str2)
		return (-1);
	for (i = 0; str[i] && str[i] == str2[i]; i++);
	return (str[i] - str2[i]);
}

int my_strncmp(char *str, char *str2, int n)
{
	unsigned int i = 0;

	if (!str || !str2)
		return (-1);
	for (i = 0; str[i] && str[i] == str2[i] && i < n - 1; i++);
	return (str[i] - str2[i]);
}

char *my_str_ncut(char *str, int n)
{
	int i = 0;

	if (!str)
		return (NULL);
	for (i = 0; str[n]; str[i] = str[n], i++, n++);
	str[i] = 0;
	return (str);
}

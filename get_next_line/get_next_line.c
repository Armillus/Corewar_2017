/*
** EPITECH PROJECT, 2018
** main function
** File description:
** get_next_line
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/asm.h"
#include "get_next_line.h"

int my_strnlen(char *str, int j)
{
	int i = 0;

	if (j == -1)
		return (my_loop(str));
	else if (j == -2)
		return (my_second_loop(str));
	else
		for (i = 0; str[i] != '\0'; i++);
	return (i);
}

char *my_str_ncpy(char *str, int p)
{
	int i = 0;
	char *str2 = "";

	if (p == -2 && (str[0] == '\n' && my_strnlen(str, 0) <= 2)) {
		free(str);
		return (my_strdup(str2));
	}
	else if (p == -1)
		i = my_strnlen(str, 0);
	else if (p == -2)
		for (i = 0; str[i] != '\n' && str[i] != '\0'; i++);
	str[i] = '\0';
	return (str);
}

char *my_strcat(char *str, char *str2)
{
	int i = 0;
	int len1 = 0;
	int len2 = 0;
	char *dest = NULL;
	int j = 0;

	if (str == NULL)
		return (my_strdup(str2));
	if (str2 == NULL)
		return (my_strdup(str));
	len1 = my_strnlen(str, 0);
	len2 = my_strnlen(str2, 0);
	len1 = len1 + len2;
	dest = malloc(sizeof(char) * (len1 + 1));
	dest[len1] = '\0';
	for (j = 0; str[i] != '\0'; dest[j] = str[i], i++, j++);
	for (i = 0; str2[i] != '\0'; dest[j] = str2[i], i++, j++);
	free(str);
	return (dest);
}

char *my_str_nsuppr(char *str)
{
	int i = 0;
	int j = 0;

	if (my_strnlen(str, -1) == 0 && my_strnlen(str, 0) >= 1) {
		free(str);
		return (NULL);
	}
	j = my_strnlen(str, -2);
	for (i = 0; str[j] != '\0'; str[i] = str[j], i++, j++);
	str[i] = 0;
	return (str);
}

char *get_next_line(int fd)
{
	static char *s = NULL;
	char *b = malloc(sizeof(char) * (SIZE + 1));
	int i = 1;

	if (fd < 0 || SIZE <= 0 || b == NULL)
		return (NULL);
	if (s == NULL && (i = read(fd, b, SIZE)) > 0)
		s = get_my_line(s, b, 1, i);
	else if (s && (my_strnlen(s, -1) == 1 || my_strnlen(s, 0) >= 1))
		s = my_str_nsuppr(s);
	while (s && my_strnlen(s, -1) == 0 && (i = read(fd, b, SIZE)) > 0)
		s = get_my_line(s, b, 0, i);
	free(b);
	if (s == NULL || (i <= 0 && my_strnlen(s, 0) < 1)) {
		if (s)
			free(s);
		return (NULL);
	}
	return (my_str_ncpy(my_strdup(s), -2));
}

/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utils functions to avoid coding style's epitech faults
*/

#include "../include/asm.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int my_loop(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == '\n')
			return (1);
	}
	return (0);
}

int my_second_loop(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\n'; i++) {
		if (str[i + 1] == '\0' && str[i] != '\n')
			return (0);
	}
	i++;
	return (i);
}

char *get_my_line(char *s, char *b, int fct, int i)
{
	b[i] = '\0';
	if (fct == 0)
		s = my_strcat(s, b);
	else
		s = my_strdup(b);
	return (s);
}

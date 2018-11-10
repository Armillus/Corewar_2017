/*
** EPITECH PROJECT, 2018
** useful_functions2
** File description:
** useful functions for the asm
*/

#include "../include/asm.h"

int find_characters(const char *str)
{
	int b = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] == ' ')
			b++;
		else if (str[i] == DIRECT_CHAR)
			b++;
		else if (str[i] == LABEL_CHAR)
			b++;
	}
	return (b);
}

int my_swap(int n)
{
	help_t help;
	int tmp = 0;
	char t[sizeof(int)];

	help.val = n;
	for (int i = sizeof(int) - 1; i >= 0; i--) {
		t[tmp] = help.tab[i];
		tmp++;
	}
	for (size_t i = 0; i < sizeof(int); i++)
		help.tab[i] = t[i];
	return (help.val);
}

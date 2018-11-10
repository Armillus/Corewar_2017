/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** detect malloc error and errors in the label tab
*/

#include "../include/asm.h"

void my_writing_err(char *path)
{
	char *src = "Erreur : impossible d'écrire dans le fichier '";
	char *end = "' !\n";

	write(2, src, my_strlen(src));
	write(2, path, my_strlen(path));
	write(2, end, my_strlen(end));
	exit(84);
}

int find_the_same_labels(char *str, asm_t *a)
{
	int count = 0;

	for (int j = 0; a->lab[j].pos != -2; j++) {
		if (my_strcmp(str, a->lab[j].name) == 0)
			count++;
	}
	return (count);
}

int analyze_labels(asm_t *a)
{
	char *tmp = NULL;

	if (!a || !a->lab)
		return (0);
	for (int i = 0; a->lab[i].pos != -2; i++) {
		tmp = a->lab[i].name;
		if (find_the_same_labels(tmp, a) > 1)
			return (0);
	}
	return (1);
}

int check_length(char *str, int size, int good_len)
{
	int count = 0;
	int len = my_strlen(str);

	if (len > size)
		return (0);
	if (str[len - 1] != '"')
		return (0);
	for (int i = good_len + 1; str[i]; i++) {
		if ((str[i] != ' ' && str[i] != '"') && count == 0)
			return (0);
		if (str[i] == '"')
			count++;
	}
	if (count != 2)
		return (0);
	return (1);
}

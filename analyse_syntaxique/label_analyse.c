/*
** EPITECH PROJECT, 2018
** asm
** File description:
** label_analyse.c
*/

#include "../include/analyse_syntax.h"
#include "../include/my.h"

void check_char_of_label(char c, token_t *token, int index)
{
	int a = 1;

	for (int i = 0; i < my_strlen(LABEL_CHARS); i++) {
		if (c == LABEL_CHARS[i])
			a = 0;
	}
	if (a)
		my_puterr("label composed of non allowed characters ",
		token, index);
}

void label_analyse(token_t *token, int index)
{
	char *tmp = my_strdup(token[index].str);
	int len = my_strlen(tmp);

	if (tmp[len - 1] == LABEL_CHAR)
		tmp[len - 1] = 0;
	else {
		free(tmp);
		my_puterr("not valid label ", token, index);
	}
	for (int i = 0; tmp[i]; i++) {
		check_char_of_label(tmp[i], token, index);
	}
	free(tmp);
}

/*
** EPITECH PROJECT, 2018
** asm
** File description:
** label_param.c
*/

#include "../include/analyse_syntax.h"
#include "../include/my.h"

int check_label(char *label1, char *label2)
{
	int i = 0;

	for (i = 0; label2[i] && label2[i] != LABEL_CHAR; i++);
	for (int j = 0; label1[j] && label1[j] != LABEL_CHAR; j++)
		if (!(label1[j] - label2[i]))
			return (0);
	return (1);
}

void check_all_labels(token_t *token, char *label)
{
	int a = 0;

	for (int i = 0; token[i].type != CHAR_EOF; i++) {
		if (token[i].type == LABEL && a == 0) {
			a = check_label(token[i].str, label);
		}
	}
	if (a == 0)
		exit(84);
}

void check_labelparam_direct(token_t *token, int index)
{
	if (token[index].str[1] != LABEL_CHAR)
		exit(84);
	for (int i = 2; token[index].str[i]; i++) {
		check_char_of_label(token[index].str[i], token, index);
	}
	check_all_labels(token, token[index].str);
}

void check_labelparam_indirect(token_t *token, int index)
{
	for (int i = 1; token[index].str[i]; i++) {
		check_char_of_label(token[index].str[i], token, index);
	}
	check_all_labels(token, token[index].str);
}

void labelparam_analyse(token_t *token, int index)
{
	if (token[index].str[0] == SEPARATOR_CHAR)
		token[index].str += 1;
	if (token[index].str[0] == LABEL_CHAR)
		check_labelparam_indirect(token, index);
	else if (token[index].str[0] == DIRECT_CHAR)
		check_labelparam_direct(token, index);
	else
		exit(84);
}

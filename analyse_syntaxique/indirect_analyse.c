/*
** EPITECH PROJECT, 2018
** asm
** File description:
** indirect_analyse.c
*/

#include "../include/analyse_syntax.h"
#include "../include/my.h"

void indirect_analyse(token_t *token, int index)
{
	int i = 0;

	(token[index].str[i] == SEPARATOR_CHAR ? i++ : 0);
	(token[index].str[i] == '-' ? i++ : 0);
	if (my_isdigit(token[index].str, i))
		my_puterr("indirect argument not composed only of digit ",
		token, index);
}

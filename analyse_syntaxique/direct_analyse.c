/*
** EPITECH PROJECT, 2018
** asm
** File description:
** direct_analyse.c
*/

#include "../include/analyse_syntax.h"
#include "../include/my.h"

void direct_analyse(token_t *token, int index)
{
	int len = 0;
	int i = 0;

	if (token[index].str[i] == SEPARATOR_CHAR)
		i++;
	(token[index].str[i] != DIRECT_CHAR ?
	my_puterr("no direct char at ", token, index) : i++);
	(token[index].str[i] == '-' ? i++ : 0);
	len = my_strlen(token[index].str);
	if (token[index].str[len] == SEPARATOR_CHAR)
		token[index].str[len] = 0;
	if (token[index].str[i] == 0 || my_isdigit(token[index].str, i))
		my_puterr("direct argument is not composed only of digits ",
		token, index);
}
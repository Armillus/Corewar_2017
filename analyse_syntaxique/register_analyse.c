/*
** EPITECH PROJECT, 2018
** asm
** File description:
** register_analyse.c
*/

#include "../include/analyse_syntax.h"
#include "../include/my.h"

void register_analyse(token_t *token, int index)
{
	int nb = 0;

	if (token[index].str[0] == SEPARATOR_CHAR)
		token[index].str += 1;
	if (token[index].str[0] != 'r')
		exit(84);
	nb = my_getnbr(token[index].str + 1);
	if (nb <= 0 || nb > REG_NUMBER)
		exit(84);
}

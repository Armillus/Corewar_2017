/*
** EPITECH PROJECT, 2018
** asm
** File description:
** analyse_syntaxe.c
*/

#include "../include/analyse_syntax.h"

int analyze_the_champion(token_t *token)
{
	int count = 0;

	for (int i = 0; token[i].type != CHAR_EOF; i++) {
		if (token[i].type == INSTRUCTION)
			count++;
	}
	return (count > 0 ? 1 : 0);
}

void syntax_analysis(token_t *token)
{
	void (*analyse_token[6])(token_t *, int) = {
		instruction_analyse,
		label_analyse,
		register_analyse,
		direct_analyse,
		indirect_analyse,
		labelparam_analyse
	};
	int i = 0;

	if (!token)
		return;
	if (!analyze_the_champion(token))
		my_puterr("Invalid instruction ", token, 0);
	for (i = 0; token[i].type != CHAR_EOF; i++)
		analyse_token[token[i].type](token, i);
}

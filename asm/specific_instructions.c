/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** functions relative to special operators
*/

#include "../include/asm.h"

int check_instruction(token_t token)
{
	for (int k = 0; spe_tab[k].name; k++) {
		if (my_strcmp(spe_tab[k].name, token.str) == 0)
			return (k + 1);
	}
	return (0);
}

int special_operator(token_t *t, token_t last, int i)
{
	int j = 0;
	int val = check_instruction(last);

	if (val == 0)
		return (1);
	for (j = i; t[j].type != last.type; j--);
	i -= j;
	if (val == 1 && (i == 2 || i == 3))
		return (0);
	else if ((val == 2 || val == 6) && (i == 1 || i == 2))
		return (0);
	else if (val == 3 && i == 1)
		return (0);
	else if ((val == 4 || val == 5) && i == 1)
		return (0);
	return (1);
}

int bad_instruction(token_t t)
{
	char *tab[4] = {"live", "fork", "lfork", "zjmp"};

	for (int i = 0; i < 4; i++)
		if (my_strcmp(t.str, tab[i]) == 0)
			return (1);
	return (0);
}

token_t my_last_inst(token_t *t, int i)
{
	for (; t[i].type != INSTRUCTION && i > 0; i--);
	return (t[i]);
}
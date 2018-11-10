/*
** EPITECH PROJECT, 2018
** asm
** File description:
** instruction_analyse.c
*/

#include "../include/analyse_syntax.h"
#include "../include/my.h"

int compare_argument(int arg_give, int arg_tab)
{
	if (arg_tab == 7)
		return (1);
	if (arg_give == T_REG && (arg_tab == 1 || arg_tab == 3 || arg_tab == 5))
		return (1);
	if (arg_give == T_DIR && (arg_tab == 2 || arg_tab == 3 || arg_tab == 6))
		return (1);
	return (arg_give == T_IND &&
	(arg_tab == 4 || arg_tab == 5 || arg_tab == 6) ? 1 : 0);
}

char set_arg_type(token_t *token, int index_token_tab)
{
	char c = 0;

	if (token[index_token_tab].type == LABEL_PARAM) {
		if (token[index_token_tab].str[0] == SEPARATOR_CHAR)
			token[index_token_tab].str += 1;
		if (token[index_token_tab].str[0] == DIRECT_CHAR &&
		token[index_token_tab].str[1] == LABEL_CHAR)
			c = T_DIR;
		else if (token[index_token_tab].str[0] == LABEL_CHAR)
			c = T_IND;
	}
	if (c == 0) {
		if (token[index_token_tab].type == REGISTER)
			c = T_REG;
		else if (token[index_token_tab].type == DIRECT)
			c = T_DIR;
		else
			c = T_IND;
	}
	return (c);
}

void check_valid_arguments(token_t *token, int index_token_tab, int index_optab)
{
	char c = 0;
	int i = 0;

	index_token_tab++;
	for (i = 0; token[index_token_tab].type != INSTRUCTION &&
	token[index_token_tab].type != LABEL &&
	token[index_token_tab].type != CHAR_EOF; i++) {
		if (i > MAX_ARGS_NUMBER || i > op_tab[index_optab].nbr_args)
			my_puterr("too much arguments", token, index_token_tab);
		c = set_arg_type(token, index_token_tab);
		if (!compare_argument(c, op_tab[index_optab].type[i]))
			my_puterr("not good argument type ", token,
			index_token_tab);
		index_token_tab++;
	}
	if (i < op_tab[index_optab].nbr_args)
		my_puterr("not enough arguments ", token, index_token_tab - 1);
}

void instruction_analyse(token_t *token, int index)
{
	int valid_instruction = 1;
	int isave = 0;

	for (int i = 0; op_tab[i].mnemonique != 0; i++) {
		if (!my_strcmp(op_tab[i].mnemonique, token[index].str)) {
			valid_instruction = 0;
			isave = i;
		}
	}
	if (valid_instruction == 1)
		my_puterr("not a valid instruction ", token, index);
	check_valid_arguments(token, index, isave);
}

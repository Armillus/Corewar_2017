/*
** EPITECH PROJECT, 2018
** labels
** File description:
** init the label tab
*/

#include "../include/asm.h"

int label_bytes(token_t *token, int j, int count)
{
	token_t t = my_last_inst(token, j);

	for (int i = 0; spe_tab[i].name; i++) {
		if (my_strcmp(t.str, spe_tab[i].name) == 0 &&
			!bad_instruction(token[j])) {
			count += spe_tab[i].pos;
			return (count);
		}
	}
	if (token[j].str[0] == DIRECT_CHAR || token[j].str[1] == DIRECT_CHAR)
		count += DIR_SIZE;
	else
		count += IND_SIZE;
	return (count);
}

int parameter_bytes(token_t *t, int j, int count)
{
	token_t last = my_last_inst(t, j);

	if (is_empty(t[j].str) == 0)
		return (count);
	if (t[j].type == REGISTER) {
		count++;
		return (count);
	}
	for (int i = 0; spe_tab[i].name; i++) {
		if (my_strcmp(last.str, spe_tab[i].name) == 0 &&
			!bad_instruction(t[j])) {
			count += spe_tab[i].pos;
			return (count);
		}
	}
	count += (t[j].type == DIRECT) ? DIR_SIZE : IND_SIZE;
	return (count);
}

int count_bytes(token_t *lexer, int j, int count)
{
	if (lexer[j].type == INSTRUCTION) {
		if (bad_instruction(lexer[j]) == 0)
			count += 2;
		else
			count++;
	}
	else if (lexer[j].type == LABEL || lexer[j].type == LABEL_PARAM) {
		if (lexer[j].type == LABEL_PARAM)
			count = label_bytes(lexer, j, count);
	}
	else
		count = parameter_bytes(lexer, j, count);
	return (count);
}

int count_labels(token_t *t)
{
	int labels_counter = 0;

	if (!t)
		return (0);
	for (int j = 0; t[j].type != CHAR_EOF; j++) {
		if (t[j].type == LABEL)
			labels_counter++;
	}
	return (labels_counter);
}

asm_t *find_my_labels(token_t *t, asm_t *a)
{
	int nb_labels = count_labels(t);
	int bytes_counter = 0;

	if (!t)
		return (a);
	if ((a->lab = malloc(sizeof(label_t) * (nb_labels + 1))) == NULL)
		return (NULL);
	a->lab[nb_labels].pos = -2;
	for (int j = 0, k = 0; t[j].type != CHAR_EOF; j++) {
		bytes_counter = count_bytes(t, j, bytes_counter);
		if (t[j].type == LABEL) {
			a->lab[k].name = my_str_cpy(a->lab[k].name, t[j].str);
			a->lab[k].pos = bytes_counter;
			k++;
		}
	}
	a->h->prog_size = bytes_counter;
	return (a);
}

/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** init the lexer of the asm
*/

#include "../include/asm.h"
#include "../include/lexer.h"
#include "../op/op.h"

lexer_t find_my_type(char *str)
{
	int len = my_strlen(str);

	if (str[len - 1] == LABEL_CHAR)
		return (LABEL);
	for (int k = 0; str[k]; k++)
		if (str[k] == LABEL_CHAR)
			return (LABEL_PARAM);
	for (int j = 0; str[0] != SEPARATOR_CHAR && op_tab[j].code != 0; j++)
		if (my_strcmp(op_tab[j].mnemonique, str) == 0)
			return (INSTRUCTION);
	for (int k = 0; par_tab[k].c != -1; k++)
		if (par_tab[k].c == str[0] || par_tab[k].c == str[1])
			return (par_tab[k].type);
	if (!my_str_isnum(str))
		return (INDIRECT);
	return (INSTRUCTION);
}

char *find_my_token_str(char *src, int pos)
{
	char *dest = NULL;
	int i = 0;
	int j = 0;

	if (!src)
		return (NULL);
	for (i = pos + 1; src[i] && src[i] != ' ' &&
		src[i] != SEPARATOR_CHAR; i++);
	dest = malloc(sizeof(char) * (i - pos + 1));
	if (!dest)
		return (NULL);
	for (j = 0; pos < i; pos++) {
		if (src[pos] != SEPARATOR_CHAR && src[pos] != ' ') {
			dest[j] = src[pos];
			j++;
		}
	}
	dest[j] = '\0';
	return (my_clean_str(dest));
}

int count_champion_words(char *src)
{
	int count = 1;

	for (int i = 1; src[i]; i++) {
		if ((src[i] != ' ' && src[i] != SEPARATOR_CHAR) &&
		(src[i - 1] == ' ' || src[i - 1] == SEPARATOR_CHAR))
			count++;
	}
	return (count);
}

token_t *fill_my_lexer(asm_t *a)
{
	token_t *t = NULL;
	int i = 0;

	if (!a)
		return (NULL);
	i = count_champion_words(a->buf);
	if ((t = malloc(sizeof(token_t) * (i + 1))) == NULL)
		return (NULL);
	t[i].type = CHAR_EOF;
	for (int j = 0, pos = 0; j < i; j++) {
		t[j].str = find_my_token_str(a->buf, pos);
		pos += my_strlen(t[j].str) + 1;
		for (; a->buf[pos] && (a->buf[pos] == ' ' ||
		a->buf[pos] == SEPARATOR_CHAR); pos++);
		t[j].type = find_my_type(t[j].str);
	}
	return (t);
}

int create_my_cor_file(asm_t *a)
{
	token_t *lexer = NULL;

	if (!a->buf) {
		write_in_file(lexer, a);
		return (1);
	}
	lexer = fill_my_lexer(a);
	free(a->buf);
	if (!lexer)
		return (0);
	syntax_analysis(lexer);
	a = find_my_labels(lexer, a);
	if (!analyze_labels(a))
		return (0);
	if (!write_in_file(lexer, a))
		return (0);
	return (1);
}

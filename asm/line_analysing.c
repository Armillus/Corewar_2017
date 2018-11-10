/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** Functions which analyse line by line a .s file
*/

#include "../include/asm.h"

char *cpy_informations(int size, char *dest, const char *src)
{
	int i = 0;
	int j = 0;

	for (i = 0; src[i] && src[i] != '"'; i++);
	for (j = 0, i += 1; j < size && (src[i] && src[i] != '"'); i++, j++)
		dest[j] = src[i];
	dest[j] = '\0';
	return (dest);
}

asm_t *cut_comment(asm_t *a)
{
	for (int i = 0; a->s[i]; i++) {
		if (a->s[i] == COMMENT_CHAR) {
			a->s[i] = 0;
			return (a);
		}
	}
	return (a);
}

int find_first_word_len(asm_t *a, int value)
{
	for (int i = 0; a->s[i]; i++) {
		if (a->s[i] == ' ')
			return (i);
	}
	return (value == 1 ? a->cmd_len : a->cmt_len);
}

asm_t *find_champion_name(asm_t *a)
{
	char *tmp = NULL;
	int len = find_first_word_len(a, 1);

	tmp = my_strncpy(my_strdup(a->s), len);
	if (my_strcmp(tmp, NAME_CMD_STRING) == 0) {
		if (!check_length(a->s, PROG_NAME_LENGTH, a->cmd_len))
			return (NULL);
		a->header_value.name++;
		cpy_informations(PROG_NAME_LENGTH, a->h->prog_name, a->s);
		free(tmp);
		return (a);
	}
	free(tmp);
	return (a);
}

asm_t *find_champion_comment(asm_t *a)
{
	char *tmp = NULL;
	int len = find_first_word_len(a, 0);

	tmp = my_strncpy(my_strdup(a->s), len);
	if (my_strcmp(tmp, COMMENT_CMD_STRING) == 0) {
		if (!check_length(a->s, COMMENT_LENGTH, a->cmt_len))
			return (NULL);
		a->header_value.com++;
		cpy_informations(COMMENT_LENGTH, a->h->comment, a->s);
		free(tmp);
		return (a);
	}
	free(tmp);
	return (a);
}

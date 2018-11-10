/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** allow to free different structures of the asm
*/

#include "../include/asm.h"

void free_asm(asm_t *a, token_t *lexer)
{
	if (a->s)
		free(a->s);
	if (a->lab) {
		for (int i = 0; a->lab[i].pos != -2; i++)
			free(a->lab[i].name);
		free(a->lab);
	}
	if (a->h)
		free(a->h);
	free(a);
	if (lexer) {
		for (int i = 0; lexer[i].type != CHAR_EOF; i++) {
			free(lexer[i].str);
		}
		free(lexer);
	}
}

int close_and_free(int fd, asm_t *a, token_t *lexer, char *src)
{
	close(fd);
	free_asm(a, lexer);
	free(src);
	return (1);
}

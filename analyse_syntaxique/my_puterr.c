/*
** EPITECH PROJECT, 2018
** asm
** File description:
** my_puterr.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/analyse_syntax.h"
#include "../include/my.h"
#include "../include/lexer.h"

void my_puterr(char *str, token_t *token, int index)
{
	write(2, str, my_strlen(str));
	write(2, token[index].str, my_strlen(token[index].str));
	write(2, ", index : ", 10);
	my_put_nbr_err(index);
	write(2, "\n", 1);
	exit(84);
}

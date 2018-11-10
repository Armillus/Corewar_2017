/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** printing anthill data
*/

#include "../include/asm.h"

void print_my_error(char *error)
{
	my_strerr(RED);
	my_strerr("[Error]");
	my_strerr(RESET);
	if (!error)
		return;
	my_strerr(CYAN);
	my_strerr(error);
	my_strerr(RESET);
}

void print_my_warning(char *warning)
{
	my_strerr(MAGENTA);
	my_strerr("[Warning]");
	my_strerr(RESET);
	if (!warning)
		return;
	my_strerr(CYAN);
	my_strerr(warning);
	my_strerr(RESET);
}
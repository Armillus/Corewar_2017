/*
** EPITECH PROJECT, 2018
** vm
** File description:
** aff_c.c
*/

#include <unistd.h>
#include "../include/arena.h"

void aff_c(process_t *pro, unsigned char *arena)
{
	char c = pro->reg[pro->args.arg[0]] % 256;
	char n = '\n';

	write(1, &c, 1);
	write(1, &n, 1);
}

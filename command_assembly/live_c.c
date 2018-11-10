/*
** EPITECH PROJECT, 2018
** vm
** File description:
** live_c.c
*/

#include "../include/arena.h"

void live_c(process_t *pro, unsigned char *arena)
{
	if (pro->args.type[0] != 0)
		return;
	pro->live = pro->args.arg[0];
}

/*
** EPITECH PROJECT, 2018
** vm
** File description:
** sti_c.c
*/

#include "../include/arena.h"

void sti_c(process_t *pro, unsigned char *arena)
{
	int t1 = pro->args.arg[0];
	int t2 = 0;
	int offset = 0;

	t2 = pro->args.arg[1];
	offset = pro->PC + (t1 + t2) % IDX_MOD;
	offset = MEM_SIZE - offset;
	if (offset >= 0) {
		arena[pro->PC + (t1 + t2) % IDX_MOD] =
		pro->reg[pro->args.arg[3]];
	} else if (offset < 0)
		arena[offset * -1] = pro->reg[pro->args.arg[0]];
}
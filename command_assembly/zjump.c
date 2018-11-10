/*
** EPITECH PROJECT, 2018
** vm
** File description:
** zjump.c
*/

#include "../include/arena.h"

void zjmp_c(process_t *pro, __attribute__((unused)) unsigned char *arena)
{
	int offset = 0;

	pro->args.arg[0] = (arena[pro->PC - 2] == 255 ?
	((254 + arena[pro->PC - 1] - 1) - 512) : pro->args.arg[0]);
	offset = pro->PC + pro->args.arg[0];
	if (pro->carry == 1) {
		if (offset < 0)
			pro->PC = MEM_SIZE + offset;
		else if (offset >= 0)
			pro->PC = offset;
	}
}

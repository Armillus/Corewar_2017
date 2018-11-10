/*
** EPITECH PROJECT, 2018
** vm
** File description:
** ld_c.c
*/

#include "../include/arena.h"

void ld_c(process_t *pro, unsigned char *arena)
{
	unsigned char reg_n = 0;
	int offset = 0;

	pro->carry = 0;
	if (pro->args.type[1] < 2 || pro->args.type[0] == 2)
		return;
	reg_n = pro->args.arg[1];
	if (pro->args.type[0] == 0) {
		pro->reg[reg_n] = pro->args.arg[0];
	} else if (pro->args.type[0] == 1) {
		offset = pro->PC + pro->args.arg[0] % IDX_MOD;
		offset = MEM_SIZE - offset;
		if (offset < 0)
			pro->reg[reg_n] = arena[offset * -1];
		else if (offset >= 0)
			pro->reg[reg_n] =
			arena[pro->PC + pro->args.arg[0] % IDX_MOD];
	}
	pro->carry = 1;
}

void lld_c(process_t *pro, unsigned char *arena)
{
	unsigned char reg_n = 0;
	int offset = 0;

	pro->carry = 0;
	if (pro->args.type[1] < 2 || pro->args.type[0] == 2)
		return;
	reg_n = pro->args.arg[1];
	if (pro->args.type[0] == 0) {
		pro->reg[reg_n] = pro->args.arg[0];
	} else if (pro->args.type[0] == 1) {
		offset = pro->PC + pro->args.arg[0];
		offset = MEM_SIZE - offset;
		if (offset < 0)
			pro->reg[reg_n] = arena[offset * -1];
		else if (offset >= 0)
			pro->reg[reg_n] = arena[pro->PC + pro->args.arg[0]];
	}
	pro->carry = 1;
}

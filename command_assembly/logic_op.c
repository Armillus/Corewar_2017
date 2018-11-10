/*
** EPITECH PROJECT, 2018
** vm
** File description:
** logic_op.c
*/

#include "../include/arena.h"

void and_c(process_t *pro, unsigned char *arena)
{
	int t1 = 0;
	int t2 = 0;

	pro->carry = 0;
	if (pro->args.type[0] == 2)
		t1 = pro->reg[pro->args.arg[0]];
	else if (pro->args.type[0] == 1)
		t1 = arena[pro->PC + pro->args.arg[0] % IDX_MOD];
	else
		t1 = pro->args.arg[0];
	if (pro->args.type[1] == 2)
		t2 = pro->reg[pro->args.arg[1]];
	else if (pro->args.type[1] == 1)
		t2 = arena[pro->PC + pro->args.arg[1] % IDX_MOD];
	else
		t2 = pro->args.arg[1];
	if (pro->args.type[2] < 2)
		return;
	pro->reg[pro->args.arg[2]] = t1 & t2;
	pro->carry = 1;
}

void or_c(process_t *pro, unsigned char *arena)
{
	int t1 = 0;
	int t2 = 0;

	pro->carry = 0;
	if (pro->args.type[0] == 2)
		t1 = pro->reg[pro->args.arg[0]];
	else if (pro->args.type[0] == 1)
		t1 = arena[pro->PC + pro->args.arg[0] % IDX_MOD];
	else
		t1 = pro->args.arg[0];
	if (pro->args.type[1] == 2)
		t2 = pro->reg[pro->args.arg[1]];
	else if (pro->args.type[1] == 1)
		t2 = arena[pro->PC + pro->args.arg[1] % IDX_MOD];
	else
		t2 = pro->args.arg[1];
	if (pro->args.type[2] < 2)
		return;
	pro->reg[pro->args.arg[2]] = t1 | t2;
	pro->carry = 1;
}

void xor_c(process_t *pro, unsigned char *arena)
{
	int t1 = 0;
	int t2 = 0;

	pro->carry = 0;
	if (pro->args.type[0] == 2)
		t1 = pro->reg[pro->args.arg[0]];
	else if (pro->args.type[0] == 1)
		t1 = arena[pro->PC + pro->args.arg[0] % IDX_MOD];
	else
		t1 = pro->args.arg[0];
	if (pro->args.type[1] == 2)
		t2 = pro->reg[pro->args.arg[1]];
	else if (pro->args.type[1] == 1)
		t2 = arena[pro->PC + pro->args.arg[1] % IDX_MOD];
	else
		t2 = pro->args.arg[1];
	if (pro->args.type[2] < 2)
		return;
	pro->reg[pro->args.arg[2]] = t1 ^ t2;
	pro->carry = 1;
}
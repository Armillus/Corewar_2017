/*
** EPITECH PROJECT, 2018
** vm
** File description:
** add_c.c
*/

#include "../include/arena.h"

void add_c(process_t *pro, __attribute__((unused)) unsigned char *arena)
{
	int reg_t1 = 0;
	int reg_t2 = 0;
	int reg_res = 0;

	pro->carry = 0;
	if (pro->args.type[0] != 2 || pro->args.type[1] != 2 ||
	pro->args.type[2] != 2)
		return;
	reg_t1 = pro->args.arg[0];
	reg_t2 = pro->args.arg[1];
	reg_res = pro->args.arg[2];
	pro->reg[reg_res] = pro->reg[reg_t1] + pro->reg[reg_t2];
	pro->carry = 1;
}

void sub_c(process_t *pro, __attribute__((unused)) unsigned char *arena)
{
	int reg_t1 = 0;
	int reg_t2 = 0;
	int reg_res = 0;

	pro->carry = 0;
	if (pro->args.type[0] != 2 || pro->args.type[1] != 2 ||
	pro->args.type[2] != 2)
		return;
	reg_t1 = pro->args.arg[0];
	reg_t2 = pro->args.arg[1];
	reg_res = pro->args.arg[2];
	pro->reg[reg_res] = pro->reg[reg_t1] - pro->reg[reg_t2];
	pro->carry = 1;
}

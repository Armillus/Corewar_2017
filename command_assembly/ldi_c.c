/*
** EPITECH PROJECT, 2018
** vm
** File description:
** ldi_c.c
*/

#include "../include/arena.h"

int get_value(process_t *pro, int nb_arg, unsigned char *arena)
{
	int term = 0;
	int offset = pro->PC + pro->args.arg[nb_arg] % IDX_MOD;

	offset = MEM_SIZE - offset;
	offset *= (offset < 0 ? -1 : 1);
	if (pro->args.type[nb_arg] == 1) {
		for (int i = offset, j = 0; j < IND_SIZE; i++, j++)
			term += arena[i];
	} else if (pro->args.type[nb_arg] == 0)
		term = pro->args.arg[nb_arg];
	return (term);
}

void ldi_c(process_t *pro, unsigned char *arena)
{
	int t1 = get_value(pro, 0, arena);
	int t2 = 0;
	int s = 0;
	int offset = 0;

	pro->carry = 0;
	if (pro->args.type[0] > 1 || pro->args.type[1] > 1 ||
	pro->args.type[2] < 2)
		return;
	t2 = get_value(pro, 1, arena);
	offset = pro->PC + (t1 + t2) % IDX_MOD;
	offset = MEM_SIZE - offset;
	if (offset >= 0) {
		s = arena[pro->PC + (t1 + t2) % IDX_MOD];
	} else if (offset < 0)
		s = arena[offset * -1];
	pro->reg[pro->args.arg[2]] = s;
	pro->carry = 1;
}

void lldi_c(process_t *pro, unsigned char *arena)
{
	int t1 = get_value(pro, 0, arena);
	int t2 = 0;
	int s = 0;
	int offset = 0;

	pro->carry = 0;
	if (pro->args.type[0] > 1 || pro->args.type[1] > 1 ||
	pro->args.type[2] < 2)
		return;
	t2 = get_value(pro, 1, arena);
	offset = pro->PC + (t1 + t2);
	offset = MEM_SIZE - offset;
	if (offset >= 0) {
		s = arena[pro->PC + (t1 + t2)];
	} else if (offset < 0)
		s = arena[offset * -1];
	pro->reg[pro->args.arg[2]] = s;
	pro->carry = 1;
}

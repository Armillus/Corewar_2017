/*
** EPITECH PROJECT, 2018
** vm
** File description:
** fork_c.c
*/

#include <stdlib.h>
#include "../include/arena.h"
#include "../include/asm.h"

arg_t create_args(arg_t args)
{
	arg_t new = {NULL, NULL};

	new.arg = malloc(sizeof(int) * 4);
	new.type = malloc(sizeof(char) * 4);
	if (!new.arg || !new.type)
		exit(84);
	for (int i = 0; i < 4; i++) {
		new.arg[i] = 0;
		new.type[i] = -1;
	}
	return (new);
}

process_t *create_new_process(process_t *pro)
{
	process_t *new = malloc(sizeof(process_t));

	if (!new)
		exit(84);
	new->args = create_args(pro->args);
	new->name = my_strdup(pro->name);
	new->carry = 0;
	new->live = 0;
	new->PC = pro->PC;
	new->time_instruct = -1;
	new->instruct = -1;
	new->reg = malloc(sizeof(long int) * REG_NUMBER);
	new->reg[0] = pro->reg[0];
	for (unsigned int i = 1; i < REG_NUMBER; i++)
		new->reg[i] = pro->reg[i];
	new->next = pro->next;
	return (new);
}

void fork_c(process_t *pro, unsigned char *arena)
{
	process_t *new = create_new_process(pro);
	int offset = 0;

	if (pro->args.type[0] != 0) {
		pro->carry = 0;
		return;
	}
	offset = pro->PC + pro->args.arg[0] % IDX_MOD;
	offset = MEM_SIZE - offset;
	pro->next = new;
	pro = pro->next;
	if (offset >= 0)
		pro->PC = pro->PC + pro->args.arg[0] % IDX_MOD;
	else if (offset < 0)
		pro->PC = offset * -1;
}

void lfork_c(process_t *pro, unsigned char *arena)
{
	process_t *new = create_new_process(pro);
	int offset = 0;

	if (pro->args.type[0] != 0) {
		pro->carry = 0;
		return;
	}
	offset = pro->PC + pro->args.arg[0];
	offset = MEM_SIZE - offset;
	pro->next = new;
	pro = pro->next;
	if (offset >= 0)
		pro->PC = pro->PC + pro->args.arg[0];
	else if (offset < 0)
		pro->PC = offset * -1;
}

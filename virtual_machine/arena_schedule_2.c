/*
** EPITECH PROJECT, 2018
** arena_schedule_2.c
** File description:
** another scheduling file for the vm
*/
#include <unistd.h>
#include <stdlib.h>
#include "../include/arena.h"
#include "../include/my.h"
#include "../op/op.h"

void add_args_value(process_t *proc, unsigned char *arena)
{
	void (*choose_type[3])(process_t *, char *, int, int) =
		{
			assign_direct,
			assign_indirect,
			assign_register,
		};

	for (unsigned int i = 0; i < 4 && proc->instruct != 0 &&
	(proc->instruct < 8 || proc->instruct > 11) &&
	proc->instruct != 13 && proc->instruct != 14; i++) 
		change_type_nbr(proc, i);
	for (unsigned int i = 0, j = 0; j < 4 && proc->instruct != 0 &&
	(proc->instruct < 8 || proc->instruct > 11) &&
	proc->instruct != 13 && proc->instruct != 14; j++) {
		if (proc->args.type[j] != -1) {
			(*choose_type[proc->args.type[j]])(proc, arena, i, j);
			i++;
		} else
			proc->args.arg[j] = -1;
	}
}

void change_type_nbr(process_t *proc, unsigned int i)
{
	if (proc->args.type[i] == 0)
		proc->args.type[i] = -1;
	else if (proc->args.type[i] == 1)
		proc->args.type[i] = 2;
	else if (proc->args.type[i] == 2)
		proc->args.type[i] = 0;
	else if (proc->args.type[i] == 3)
		proc->args.type[i] = 1;
}

void assign_direct(process_t *proc, char *arena,
	int decal, __attribute__((unused)) int reg)
{
	int value = 0;

	for (unsigned int i = 0; i < DIR_SIZE; i++, proc->PC++)
		value += arena[proc->PC];
	proc->args.arg[decal] = value;
}

void assign_indirect(process_t *proc, char *arena,
	int decal, __attribute__((unused)) int reg)
{
	int value = 0;

	for (unsigned int i = 0; i < IND_SIZE; i++, proc->PC++)
		value += arena[proc->PC];
	proc->args.arg[decal] = value;
}

void assign_register(process_t *proc, char *arena, int decal, int reg)
{
	proc->args.arg[decal] = 0;
	proc->args.arg[decal] += arena[proc->PC++];
	proc->args.arg[decal] -= 1;
}
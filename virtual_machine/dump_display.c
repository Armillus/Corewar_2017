/*
** EPITECH PROJECT, 2018
** dump_display.c
** File description:
** display the memory if a dump cycle have been specified
*/

#include "../op/op.h"
#include "../include/my.h"
#include "../include/vm.h"
#include "../include/arena.h"
#include <stdlib.h>
#include <unistd.h>

void display_memory(unsigned char *arena)
{
	for (unsigned int i = 0; i < MEM_SIZE; i++) {
		(i % 32 == 0 ? write(1, "\n", 1) : 0);
		decimal_to_exadecimal(arena[i]);
	}
}

int decimal_to_exadecimal(unsigned char bin)
{
	char binary[] = "00000000";
	char *hex = "0123456789ABCDEF";
	char result1 = 0;
	char result2 = 0;

	for (unsigned int i = 7; bin > 0; i--, bin /= 2)
		binary[i] = bin % 2 + 48;
	for (unsigned int i = 0, mul = 8; i < 4; i++, mul /= 2)
		result1 += ((binary[i] - 48) * mul);
	for (unsigned int i = 4, mul = 8; i < 8; i++, mul /= 2)
		result2 += ((binary[i] - 48) * mul);
	result1 = hex[result1];
	result2 = hex[result2];
	write(1, "0x", 2);
	write(1, &result1, 1);
	write(1, &result2, 1);
	write(1, " ", 1);
	return (0);
}

char *find_code_byte(unsigned char bin)
{
	char *binary = malloc(sizeof(char) * (MAX_ARGS_NUMBER * 2 + 1));

	if (!binary)
		exit(84);
	for (unsigned int i = 0; i < MAX_ARGS_NUMBER * 2; i++)
		binary[i] = '0';
	binary[MAX_ARGS_NUMBER * 2] = 0;
	for (unsigned int i = MAX_ARGS_NUMBER * 2 - 1; bin > 0; i--, bin /= 2)
		binary[i] = bin % 2 + 48;
	return (binary);
}

char *copy_name(char *name)
{
	char *name_cpy = my_strcpy(name);
	char *new_name = my_strcpy(name);

	for (; name[0] != '.' && name[0]; name++);
	if (my_strcmp(name, ".cor") == 0) {
		free(name_cpy);
		return (new_name);
	} else
		new_name = my_strcat(new_name, ".cor");
	free(name_cpy);
	return (new_name);
}

void load_params_for_index_instruction(process_t *proc, unsigned char *arena)
{
	proc->PC++;
	proc->args.type[0] = 0;
	proc->args.arg[0] = 0;
	proc->args.type[1] = 0;
	proc->args.arg[1] = 0;
	if (proc->instruct == 9 || proc->instruct == 13) {
		for (unsigned int i = 0; i < IND_SIZE; i++)
			proc->args.arg[0] += arena[proc->PC++];
		for (unsigned int i = 0; i < IND_SIZE; i++)
			proc->args.arg[1] += arena[proc->PC++];
		proc->args.type[2] = 2;
		proc->args.arg[2] = arena[proc->PC++] - 1;
	} else if (proc->instruct == 10) {
		proc->args.type[2] = 2;
		proc->args.arg[2] = arena[proc->PC++] - 1;
		for (unsigned int i = 0; i < IND_SIZE; i++)
			proc->args.arg[0] += arena[proc->PC++];
		for (unsigned int i = 0; i < IND_SIZE; i++)
			proc->args.arg[1] += arena[proc->PC++];
	}
}
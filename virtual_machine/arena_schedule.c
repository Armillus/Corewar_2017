/*
** EPITECH PROJECT, 2018
** arena_schedule.c
** File description:
** schedunling of the vm
*/
#include <unistd.h>
#include <stdlib.h>
#include "../include/mem_writing.h"
#include "../include/arena.h"
#include "../include/my.h"
#include "../op/op.h"

void compute_virtual_machine(process_t *proc, char *arena,
	int dump, players_t *save)
{
	int cycle_to_die = CYCLE_TO_DIE;
	int dmp_stp = 0;
	header_t *players = init_headers(proc);
	int nbr_lv = 0;

	write_bytecode_in_mem(arena, proc, players);
	for (int i = 0; proc && cycle_to_die > 0 &&
	dmp_stp == 0 && nbr_lv != -1; i++) {
		(dump != -1 && i == dump ? dmp_stp = 1 : 0);
		execute_or_wait_for_instruction(arena, proc, save);
		if (i == cycle_to_die) {
			proc = check_player_is_alive(proc, &nbr_lv, save);
			cycle_to_die -= (nbr_lv >= NBR_LIVE ? CYCLE_DELTA : 0);
			i = 0;
		}
	}
	(nbr_lv == -1 ? display_winner(proc, save) : 0);
	(dmp_stp != 0 && dump != -1 ? display_memory(arena) : 0);
	clean_up_memory(arena, proc, players, save);
}

void execute_or_wait_for_instruction(unsigned char *arena,
	process_t *lst, players_t *players)
{
	for (int stop = 0; lst && stop != 1;) {
		stop = (lst->next ? 0 : 1);
		if (lst->time_instruct == -1 &&
		arena[lst->PC] >= 1 && arena[lst->PC] <= 16)
			search_for_params(arena, lst);
		if (lst->time_instruct != -1 &&
		lst->time_instruct == op_tab[lst->instruct].nbr_cycles) {
			browse_command(lst, arena, players);
			lst->time_instruct = -1;
			lst->instruct = -1;
		} else if (lst->time_instruct != -1)
			lst->time_instruct++;
		else {
			(lst->PC >= MEM_SIZE - 1 ? lst->PC = 0 : 0);
			lst->PC++;
		}
		lst = (stop != 1 ? lst->next : lst);
	}
}

void search_for_params(unsigned char *arena, process_t *lst)
{
	char *binary = NULL;

	lst->instruct = arena[lst->PC++] - 1;
	lst->time_instruct = 0;
	if (lst->instruct != 0 && (lst->instruct < 8 || lst->instruct > 11) &&
	lst->instruct != 13 && lst->instruct != 14) {
		binary = find_code_byte(arena[lst->PC]);
		add_args_types(lst, binary);
		lst->PC++;
	}
	for (unsigned int i = 0; i < 4; i++)
		lst->args.arg[i] = -1;
	lst->args.arg[3] = -1;
	add_args_value(lst, arena);
	check_instruction_with_no_type(lst, arena);
}

void add_args_types(process_t *proc, char *binary)
{
	char *ptr = NULL;
	char *bin_cpy = binary;
	int stop = 1;
	char bytecode[] = "011011";

	if (!proc->args.type)
		exit(84);
	for (unsigned int decal = 0; binary[0] != 0 &&
	proc->instruct != 0; decal++) {
		ptr = bytecode;
		for (stop = 1; stop != 0 && ptr[0]; ptr += 2)
			stop = my_strncmp(binary, ptr, 2);
		proc->args.type[decal] =
		(stop == 0 ? 2 * (binary[0] - 48) + (binary[1] - 48) : 0);
		binary += 2;
	}
	free(bin_cpy);
}
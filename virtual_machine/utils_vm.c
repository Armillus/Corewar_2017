/*
** EPITECH PROJECT, 2018
** utils_vm.c
** File description:
** usefull functions for the vm
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/vm.h"
#include "../include/arena.h"

void display_vm_usage(void)
{
	write(1, "USAGE\n", 6);
	write(1, "./corewar [-dump nbr_cycle] ", 28);
	write(1, "[[-n prog_number] [-a load_address] prog_name] ...\n\n", 53);
	write(1, "DESCRIPTION\n", 12);
	write(1, "-dump nbr_cycle dumps the memory after the nbr_cycle ", 53);
	write(1, "execution (if the round isn't\n", 30);
	write(1, "already over) with the following format: ", 41);
	write(1, "32 bytes/line in\n", 17);
	write(1, "hexadecimal (A0BCDEFE1DD3...)\n", 30);
	write(1, "-n prog_number sets the next program's number.  ", 48);
	write(1, "By default, the first free number\n", 34);
	write(1, "in the parameter order\n", 23);
	write(1, "-a load_address sets the next program's ", 40);
	write(1, "loading address.  When no address is\n", 37);
	write(1, "specified, optimize the addresses so that ", 42);
	write(1, "the processes are as far\n", 25);
	write(1, "away from each other as possible. ", 34);
	write(1, "The addresses are MEM_SIZE modulo.\n", 35);
	exit(0);
}

int *malloc_tmp_players(int addr_cnt)
{
	int *tmp_mem_address = NULL;

	if (addr_cnt != 0)
		tmp_mem_address = malloc(sizeof(int) * (addr_cnt + 1));
	return (tmp_mem_address);
}

process_t *search_for_player_live(process_t *proc,
	players_t *players, int *nbr_live)
{
	for (unsigned int i = 0; players[i].nbr != -2; i++)
		if (proc->live == players[i].nbr)
			players[i].nbr_of_lives += 1;
	proc->live = 0;
	if (proc->next)
		proc = proc->next;
	(*nbr_live)++;
	return (proc);
}

void check_instruction_with_no_type(process_t *proc, unsigned char *arena)
{
	if (proc->instruct == 0) {
		proc->args.type[0] = 0;
		proc->args.arg[0] = 0;
		for (unsigned int i = 0; i < 4; i++, proc->PC++)
			proc->args.arg[0] += arena[proc->PC];
	} else if (proc->instruct == 8 ||
	proc->instruct == 11 || proc->instruct == 14) {
		proc->args.type[0] = 0;
		proc->args.arg[0] = 0;
		for (unsigned int i = 0; i < 2; i++, proc->PC++)
			proc->args.arg[0] += arena[proc->PC];
	} else if (proc->instruct == 9 || proc->instruct == 10 ||
	proc->instruct == 13)
		load_params_for_index_instruction(proc, arena);
}

void alloc_all_players(header_t *player, unsigned int nbr_pl)
{
	for (unsigned int i = 0; i < nbr_pl; i++) {
		player[i].magic = 0;
		for (unsigned int j = 0; j < PROG_NAME_LENGTH + 1; j++)
			player[i].prog_name[j] = 0;
		player[i].prog_size = 0;
		for (unsigned int j = 0; j < COMMENT_LENGTH + 1; j++)
			player[i].comment[j] = 0;
	}
}
/*
** EPITECH PROJECT, 2018
** arena_processing.c
** File description:
** arena processing
*/

#include "../include/arena.h"
#include "../include/vm.h"
#include "../op/op.h"
#include <stdlib.h>

int construct_arena(players_t *players, int dump)
{
	unsigned char *arena = malloc(sizeof(unsigned char) * MEM_SIZE);
	process_t *proc_list = NULL;
	unsigned int pl_nbr = count_players(players);
	int lim = find_biggest_nbr(players, -1);

	if (!arena)
		exit(84);
	for (unsigned int i = 0; i < MEM_SIZE; i++)
		arena[i] = 0;
	for (unsigned int i = 0, j = 0; i < pl_nbr; i++) {
		for (j = 0; players[j].nbr != lim && players[j].nbr != -2; j++);
		add_player_to_chained_list(&proc_list, players[j], arena);
		lim = find_biggest_nbr(players, lim);
	}
	compute_virtual_machine(proc_list, arena, dump, players);
	return (0);
}

void add_player_to_chained_list(process_t **proc_list,
	players_t players, unsigned char *arena)
{
	process_t *new_player = malloc(sizeof(process_t));

	new_player->reg = malloc(sizeof(long int) * REG_NUMBER);
	new_player->args.arg = malloc(sizeof(int) * 4);
	new_player->args.type = malloc(sizeof(char) * 4);
	if (!new_player || !new_player->reg ||
	!new_player->args.arg || !new_player->args.type)
		exit(84);
	new_player->reg[0] = players.nbr;
	for (unsigned int i = 1; i < REG_NUMBER; i++)
		new_player->reg[i] = 0;
	new_player->name = copy_name(players.name);
	new_player->live = 0;
	new_player->PC = players.address - 1;
	new_player->carry = 0;
	new_player->time_instruct = -1;
	new_player->instruct = -1;
	new_player->next = *proc_list;
	*proc_list = new_player;
}

unsigned int count_players(players_t *players)
{
	unsigned int count = 0;

	for (; players[count].nbr != -2; count++);
	return (count);
}

int find_biggest_nbr(players_t *players, int lim)
{
	int biggest_nbr = 0;

	for (unsigned int i = 0; players[i].nbr != -2 && lim == -1; i++)
		if (biggest_nbr < players[i].nbr)
			biggest_nbr = players[i].nbr;
	if (lim == -1)
		return (biggest_nbr);
	for (unsigned int i = 0; players[i].nbr != -2; i++)
		if (biggest_nbr < players[i].nbr && players[i].nbr < lim)
			biggest_nbr = players[i].nbr;
	return (biggest_nbr);
}

void check_address_and_number(players_t *players)
{
	for (unsigned int i = 0, decal = 0; players[decal].nbr != -2; decal++) {
		for (i = decal + 1; players[i].nbr != -2 &&
		players[decal].nbr != players[i].nbr &&
		players[decal].address != players[i].address; i++);
		if (players[i].nbr != -2)
			exit(84);
	}
}

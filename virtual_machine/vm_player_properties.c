/*
** EPITECH PROJECT, 2018
** vm_player_properties.c
** File description:
** player properties functions
*/

#include "../include/vm.h"
#include "../get_next_line/get_next_line.h"
#include "../op/op.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int assigne_player_values(char *nbr, char type)
{
	int player_number = my_getnbr(nbr);

	if (player_number < 1 || (player_number > MEM_SIZE && type == 2))
		exit(84);
	return (player_number);
}

void fill_remaining_characteristics(players_t *players)
{
	for (unsigned int i = 0; players[i].nbr != -2; i++) {
		if (players[i].nbr == -1)
			change_player_nbr(players, i);
		if (players[i].name == NULL)
			exit(84);
	}
}

void change_player_nbr(players_t *players, unsigned int i)
{
	int nbr = 1;

	for (unsigned int j = 0; players[j].nbr != -2; j++) {
		if (players[j].nbr == nbr) {
			j = 0;
			nbr++;
		}
	}
	players[i].nbr = nbr;
}

void change_player_address(players_t *players)
{
	unsigned int addr_cnt = 0;
	unsigned int no_addr_cnt = 0;
	int *tmp_mem_address = NULL;

	for (unsigned int i = 0; players[i].nbr != -2; i++)
		(players[i].address != -1 ? addr_cnt++ : no_addr_cnt++);
	tmp_mem_address = malloc_tmp_players(addr_cnt);
	for (unsigned int i = 0, j = 0; players[i].nbr != -2 &&
	addr_cnt > 0; i++)
		if (players[i].address != -1)
			tmp_mem_address[j++] = players[i].address;
	if (tmp_mem_address)
		tmp_mem_address[addr_cnt] = -1;
	if (addr_cnt > 0 && no_addr_cnt > 0 && tmp_mem_address)
		sorting_existing_memory_zone(players,
		tmp_mem_address, no_addr_cnt);
	else if (no_addr_cnt > 0)
		assign_unitialised_memory_zone(players, no_addr_cnt);
	free(tmp_mem_address);
}

void check_if_file_exist(players_t *players)
{
	int fd = 0;

	for (unsigned int i = 0; players[i].nbr != -2; i++) {
		fd = open(players[i].name, O_RDONLY);
		if (fd == -1) {
			players[i].name = my_strcat(players[i].name, ".cor");
			fd = open(players[i].name, O_RDONLY);
		}
		if (fd == -1) {
			write(2, "Player file doesn't exist\n", 27);
			exit(84);
		}
	}
}

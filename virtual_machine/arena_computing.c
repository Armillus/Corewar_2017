/*
** EPITECH PROJECT, 2018
** arena_computing.c
** File description:
** main loop for the arena
*/
#include "../include/arena.h"
#include "../include/vm.h"
#include "../op/op.h"
#include <stdlib.h>

void sorting_existing_memory_zone(players_t *players, int *tmp, int no_addr_cnt)
{
	unsigned int i = 0;

	for (unsigned int j = 0, trig = 0; trig != 1;) {
		for (j = 0; tmp[j + 1] != -1 && tmp[j] < tmp[j + 1]; j++);
		trig = (tmp[j + 1] == -1 ? 1 : 0);
		for (i = 0; tmp[i + 1] != -1; i++)
			swap_address(tmp, i);
	}
	tmp[i] = -1;
	if (tmp[1] != -1)
		compare_memory_zones(players, tmp, no_addr_cnt);
	else
		assign_memory_when_one_assigned(players, tmp, no_addr_cnt);
}

void compare_memory_zones(players_t *players, int *tmp, int no_addr_cnt)
{
	int biggest_memory_size = 0;
	int biggest_actual_size = 0;
	int biggest_memory_decal = 0;
	unsigned int i = 0;

	for (; tmp[i + 1] != -1; i++)
		if (biggest_memory_size < tmp[i + 1] - tmp[i]) {
			biggest_memory_size = tmp[i + 1] - tmp[i];
			biggest_memory_decal = i;
	}
	if (biggest_memory_size < MEM_SIZE - tmp[i])
		biggest_memory_size = MEM_SIZE - tmp[i];
	biggest_memory_size = biggest_memory_size / (no_addr_cnt + 2);
	biggest_actual_size = biggest_memory_size + biggest_memory_decal;
	for (unsigned int j = 0; players[j].nbr != -2; j++) {
		if (players[j].address == -1) {
			players[j].address = biggest_actual_size;
			biggest_actual_size += biggest_memory_size;
		}
	}
}

void assign_memory_when_one_assigned(players_t *players, int *tmp,
int no_addr_cnt)
{
	int biggest_memory_size = 0;
	int biggest_actual_size = 0;
	int biggest_memory_decal = 0;
	unsigned int i = 0;

	biggest_memory_decal = (tmp[0] < MEM_SIZE - tmp[0] ? 0 : tmp[0]);
	biggest_memory_size = (tmp[0] < MEM_SIZE - tmp[0] ?
	MEM_SIZE - tmp[0] : tmp[0]);
	biggest_memory_size = biggest_memory_size / (no_addr_cnt + 2);
	biggest_actual_size = biggest_memory_size + biggest_memory_decal;
	for (unsigned int j = 0; players[j].nbr != -2; j++) {
		if (players[j].address == -1) {
			players[j].address = biggest_actual_size;
			biggest_actual_size += biggest_memory_size;
		}
	}
}

void assign_unitialised_memory_zone(players_t *players, int no_addr_cnt)
{
	int biggest_memory_size = MEM_SIZE / (no_addr_cnt + 2);
	int biggest_actual_size = biggest_memory_size;

	for (unsigned int i = 0; players[i].nbr != -2; i++) {
		players[i].address = biggest_actual_size;
		biggest_actual_size += biggest_memory_size;
	}
}

void swap_address(int *tmp, unsigned int i)
{
	int tmp_val = 0;

	if (tmp[i] > tmp[i + 1]) {
		tmp_val = tmp[i];
		tmp[i] = tmp[i + 1];
		tmp[i + 1] = tmp_val;
	}
}

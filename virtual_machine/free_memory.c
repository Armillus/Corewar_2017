/*
** EPITECH PROJECT, 2018
** free_memory.c
** File description:
** free memory
*/

#include "../include/arena.h"
#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>

void clean_up_memory(char *arena, process_t *proc,
header_t *headers, players_t *save)
{
	for (process_t *ptr = NULL; proc && proc->next;) {
		ptr = proc;
		free(ptr->name);
		free(ptr->reg);
		if (proc->next)
			proc = proc->next;
		free(ptr);
	}
	if (headers)
		free(headers);
	if (proc)
		free_struct(proc);
	if (arena)
		free(arena);
	clean_up_tmp_players(save);
}

void clean_up_tmp_players(players_t *players)
{
	for (unsigned int i = 0; players[i].nbr != -2; i++)
		free(players[i].name);
	free(players);
}

header_t *init_headers(process_t *proc)
{
	header_t *players = NULL;
	process_t *tmp = proc;
	unsigned int pl_count = 0;

	if (!tmp)
		return (NULL);
	for (; tmp->next; tmp = tmp->next, pl_count++);
	players = malloc(sizeof(header_t) * (pl_count + 2));
	alloc_all_players(players, pl_count + 2);
	players[pl_count + 1].magic = -1;
	return (players);
}

void free_struct(process_t *proc)
{
	free(proc->name);
	free(proc->reg);
	free(proc);
}

void display_player_still_alive(process_t *proc, players_t *players)
{
	unsigned int i = 0;

	for (char stop = 0; players[i].nbr != -2 && stop != 1;) {
		if (proc->live == players[i].nbr)
			stop = 1;
		else
			i++;
	}
	if (players[i].nbr != -2) {
		my_putstr("A process says that the player ");
		my_put_nbr(players[i].nbr);
		write(1, "(", 1);
		my_putstr(players[i].name);
		my_putstr(") is still alive !\n");
	}
}

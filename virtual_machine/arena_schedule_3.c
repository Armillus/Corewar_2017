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
#include "../include/vm.h"
#include "../op/op.h"

process_t *check_player_is_alive(process_t *proc,
	int *nbr_live, players_t *players)
{
	process_t *start = proc;
	unsigned int j = 0;

	for (unsigned int i = 0; players[i].nbr != -2; i++)
		players[i].nbr_of_lives = 0;
	for (unsigned int i = 0, stop = 0; stop != 1 && proc;) {
		stop = (!proc->next ? 1 : 0);
		if (proc->live == 0) {
			proc = delete_dead_player(proc, &start, &i);
		} else {
			i++;
			j++;
			proc = search_for_player_live(proc, players, nbr_live);
		}
	}
	*nbr_live = (j == 1 ? -1 : *nbr_live);
	return (proc ? start : proc);
}

process_t *delete_dead_player(process_t *proc,
	process_t **start, unsigned int *i)
{
	process_t *tmp = *start;

	if (*i == 0 && proc->next != 0) {
		*start = proc;
		proc = proc->next;
		free_struct(*start);
		*start = proc;
		return (proc);
	} else if (proc->next == 0 && *i != 0) {
		proc = delete_player_end_of_list(proc, start, i, tmp);
		return (proc);
	} else if (proc->next != 0 && *i != 0) {
		proc = delete_player_middle_of_list(proc, start, i, tmp);
		return (proc);
	}
	my_putstr("There isn't anyone left in the arena\n");
	return (NULL);
}

process_t *delete_player_end_of_list(process_t *proc,
	process_t **start, unsigned int *i, process_t *tmp)
{
	for (; (*start)->next != proc; *start = (*start)->next);
	proc = *start;
	free_struct((*start)->next);
	(*start)->next = 0;
	*start = tmp;
	(*i)++;
	return (proc);
}

process_t *delete_player_middle_of_list(process_t *proc,
	process_t **start, unsigned int *i, process_t *tmp)
{
	for (; (*start)->next != proc; *start = (*start)->next);
	(*start)->next = proc->next;
	free_struct(proc);
	proc = (*start)->next;
	*start = tmp;
	(*i)++;
	return (proc);
}

void display_winner(process_t *proc, players_t *players)
{
	if (proc) {
		my_putstr("The player ");
		my_put_nbr(proc->reg[0]);
		write(1, "(", 1);
		my_putstr(proc->name);
		my_putstr(") has won the game !\nWell done soldier, ");
		my_putstr("your fruit killing skills are outstanding 0_o\n");
	} else
		my_putstr("What a massacre, everyone is dead ...\n");
}
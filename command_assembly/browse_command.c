/*
** EPITECH PROJECT, 2018
** vm
** File description:
** browse_command.c
*/

#include "../include/arena.h"
#include "../include/command.h"

void browse_command(process_t *pro, unsigned char *arena, players_t *players)
{
	void (*command[16])(process_t *, unsigned char *) = {live_c, ld_c,
	st_c, add_c, sub_c, and_c, or_c, xor_c, zjmp_c, ldi_c, sti_c, fork_c,
	lld_c, lldi_c, lfork_c, aff_c};

	(*command[pro->instruct])(pro, arena);
	if (pro->instruct == 0)
		display_player_still_alive(pro, players);
}
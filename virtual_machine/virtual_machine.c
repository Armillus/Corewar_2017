/*
** EPITECH PROJECT, 2018
** virtual_machine.c
** File description:
** virtual machine main filee
*/

#include "../include/vm.h"
#include <stdlib.h>

int main(int ac, char **av, char **env)
{
	players_t *players;
	int dump = 0;

	if (ac > 1 && av[1][0] == '-' &&
	av[1][1] == 'h' && my_strlen(av[1]) == 2)
		display_vm_usage();
	if (ac > 1)
		players = check_valid_players(ac, av, &dump);
	else {
		players = malloc(sizeof(players_t));
		if (!players)
			return (84);
		players[0].nbr = -2;
	}
	check_address_and_number(players);
	if (construct_arena(players, dump) == -1)
		return (84);
	return (0);
}

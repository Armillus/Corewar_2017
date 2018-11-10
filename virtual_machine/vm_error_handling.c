/*
** EPITECH PROJECT, 2018
** vm_error_handling.c 
** File description:
** error handling for the vm
*/

#include "../include/vm.h"
#include "../include/my.h"
#include "../op/op.h"
#include <stdlib.h>
#include <unistd.h>

players_t *check_valid_players(int ac, char **av, int *dump)
{
	unsigned int nbr_of_players = count_nbr_of_players(av);
	players_t *players = malloc(sizeof(players_t) * (nbr_of_players + 1));

	if (!players)
		exit(84);
	players[0].nbr = -1;
	*dump = -1;
	if (my_strcmp("-dump", av[1]) == 0 && my_strlen(av[1]) == 5) {
		if (check_dump_cycle(av[2]) == -1) {
			write(2, "Invalid dump cycle\n", 20);
			exit(84);
		}
		*dump = my_getnbr(av[2]);
		players[0].nbr = 0;
	}
	fill_players_characteristics(nbr_of_players, av, players, ac);
	check_if_file_exist(players);
	return (players);
}

int check_dump_cycle(char *input)
{
	const char *valid = "0123456789";

	for (int i = 0, j = 0; valid[i] != 0; i++) {
		if (input[j] == valid[i]) {
			j++;
			i = -1;
		}
		if (input[j] == 0 && i == -1)
			return (0);
	}
	return (-1);
}

unsigned int count_nbr_of_players(char **av)
{
	unsigned int players = 0;
	unsigned int i = 1;

	i =  (my_strcmp(av[1], "-dump") == 0 ? 3 : 1);
	for (; av[i] != 0; i++) {
		if (!(av[i][0] == '-' && (av[i][1] == 'n' ||
		av[i][1] == 'a') && av[i][2] == 0))
			players++;
		else
			i++;
	}
	return (players);
}

void fill_players_characteristics(unsigned int nbr_of_players,
char **av, players_t *players, int ac)
{
	unsigned int pl_pos = 0;
	int i = 0;

	i = (players[0].nbr == -1 ? 1 : 3);
	for (; i < ac; i++, pl_pos++) {
		players[pl_pos].nbr_of_lives = 0;
		players[pl_pos].nbr = -1;
		players[pl_pos].address = -1;
		players[pl_pos].name = NULL;
		for (; i < ac && av[i][0] == '-' && (av[i][1] == 'n' ||
		av[i][1] == 'a') && av[i][2] == 0; i += 2)
			select_options(players, pl_pos, av[i], av[i + 1]);
		if (i < ac && !(av[i][0] == '-' && (av[i][1] == 'n' ||
		av[i][1] == 'a') && av[i][2] == 0))
			players[pl_pos].name = my_strcpy(av[i]);
		players[pl_pos + 1].nbr = -2;
	}
	fill_remaining_characteristics(players);
	change_player_address(players);
	players[pl_pos].nbr = -2;
}

void select_options(players_t *players,
	unsigned int pl_pos, char *opt, char *param)
{
	if (opt[1] == 'n')
		players[pl_pos].nbr = assigne_player_values(param, 1);
	else if (opt[1] == 'a')
		players[pl_pos].address = assigne_player_values(param, 2);
}

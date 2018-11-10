/*
** EPITECH PROJECT, 2017
** unit_test_corewar.c
** File description:
** unti tests for the corewar
*/

#include <criterion/criterion.h>
#include "../include/vm.h"
#include "../include/arena.h"

Test(corewar_tests, test_check_alloc)
{
	int *board_int = malloc_tmp_players(4);

	cr_assert_neq(board_int, NULL);
}

Test(corewar_tests, test_dump_cycle_check)
{
	int res = check_dump_cycle("1234");

	cr_assert_eq(res, 0);
	res = check_dump_cycle("not working");
	cr_assert_eq(res, -1);
}

Test(corewar_tests, test_player_counting)
{
	char *test[] = {"./corewar", "-a", "1", "-n", "2", "player"};
	unsigned int nbr_pl = count_nbr_of_players(test);

	cr_assert_eq(nbr_pl, 1);
}

Test(corewar_tests, test_counting_players_chained_list)
{
	process_t *proc_list = malloc(sizeof(process_t));
	unsigned char *arena = malloc(sizeof(unsigned char) * 10);
	unsigned int player_count = 0;
	players_t *players = malloc(sizeof(players_t) * 2);

	players[0].nbr = 1;
	players[0].address = 2;
	players[0].name = "zork.cor";
	players[1].nbr = -2;
	proc_list->next = NULL;
	add_player_to_chained_list(&proc_list, players[0], arena);
	player_count = count_players(players);
	cr_assert_eq(player_count, 1);
	cr_assert_eq(proc_list->live, 0);
	cr_assert_eq(proc_list->PC, 1);
	cr_assert_eq(proc_list->carry, 0);
	cr_assert_eq(proc_list->time_instruct, -1);
	cr_assert_eq(proc_list->instruct, -1);
	cr_assert_eq(proc_list->reg[0], 1);
	free(proc_list);
}

Test(corewar_tests, test_swap_two_addresses)
{
	int arr[] = {2, 1};

	swap_address(arr, 0);
	cr_assert_eq(arr[0], 1);
	cr_assert_eq(arr[1], 2);
}

/*
** EPITECH PROJECT, 2018
** arena.h
** File description:
** arena function prototypes
*/

#include "../op/op.h"
#include "vm.h"

#ifndef ARENA_H_
#define ARENA_H_

typedef struct arguments_s {
	int *arg;
	char *type;
} arg_t;

typedef struct process_s {
	arg_t args;
	char *name;
	char carry;
	int live;
	unsigned int PC;
	int time_instruct;
	int instruct;
	long int *reg;
	struct process_s *next;
} process_t;

void load_params_for_index_instruction(process_t *, unsigned char *);
void alloc_all_players(header_t *, unsigned int);
void check_instruction_with_no_type(process_t *, unsigned char *);
void browse_command(process_t *, unsigned char *, players_t *);
int get_value(process_t *pro, int nb_arg, unsigned char *);
header_t *init_headers(process_t *);
void add_args_types(process_t *, char *);
void add_args_value(process_t *, unsigned char *);
void change_type_nbr(process_t *, unsigned int);
process_t *search_for_player_live(process_t *, players_t *, int *);
void display_player_still_alive(process_t *, players_t *);
void assign_direct(process_t *, char *, int, int);
void assign_indirect(process_t *, char *, int, int);
void assign_register(process_t *, char *, int, int);
process_t *check_player_is_alive(process_t *, int *, players_t *);
process_t *delete_dead_player(process_t *, process_t **, unsigned int *);
process_t *delete_player_end_of_list(process_t *,
	process_t **, unsigned int *, process_t *);
process_t *delete_player_middle_of_list(process_t *,
	process_t **, unsigned int *, process_t *);
void search_for_params(unsigned char *, process_t *);
char *find_code_byte(unsigned char);
void display_memory(unsigned char *);
void add_player_to_chained_list(process_t **, players_t, unsigned char *);
unsigned int count_players(players_t *);
int find_biggest_nbr(players_t *, int);
void compute_virtual_machine(process_t *, char *, int, players_t *);
void assign_memory_when_one_assigned(players_t *, int *, int);
void swap_address(int *, unsigned int);
void execute_or_wait_for_instruction(unsigned char *,
	process_t *, players_t *);
char *copy_name(char *);
void clean_up_memory(char *, process_t *, header_t *, players_t *);
void clean_up_tmp_players(players_t *);
void free_struct(process_t *);
void display_winner(process_t *, players_t *);

#endif /* !ARENA_H_ */

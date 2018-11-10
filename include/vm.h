/*
** EPITECH PROJECT, 2018
** vm.h
** File description:
** vm prototypes
*/

#ifndef VM_H_
#define VM_H_

typedef struct players_s {
	int nbr_of_lives;
	int nbr;
	int address;
	char *name;
} players_t;

int decimal_to_exadecimal(unsigned char);
void display_vm_usage(void);
int my_strlen(char *);
int my_getnbr(char *);
char *my_strcpy(char *);
char *my_strcpy(char *);
players_t *check_valid_players(int, char **, int *);
int check_dump_cycle(char *);
int assigne_player_values(char *, char);
unsigned int count_nbr_of_players(char **);
void fill_players_characteristics(unsigned int, char **, players_t *, int);
void fill_remaining_characteristics(players_t *);
void change_player_nbr(players_t *, unsigned int);
void change_player_address(players_t *);
void select_options(players_t *, unsigned int, char *, char *);
void check_if_file_exist(players_t *);
char *my_strcat(char *, char *);
int construct_arena(players_t *, int);
void check_address_and_number(players_t *);
void sorting_existing_memory_zone(players_t *, int *, int);
int *malloc_tmp_players(int);
void compare_memory_zones(players_t *, int *, int);
void assign_unitialised_memory_zone(players_t *, int);

#endif /* !VM_H_ */

/*
** EPITECH PROJECT, 2018
** Virtual Machine
** File description:
** Allow to free memory before quit
*/

#include <unistd.h>
#include "../include/mem_writing.h"
#include "../include/arena.h"
#include "../op/op.h"
#include "../include/asm.h"

void free_and_quit(char *arena, process_t *proc_list,
champion_t *champ, int option)
{
	if (option == 1) {
		my_strerr("Error : \"");
		my_strerr(proc_list->name);
		my_strerr("\" is an invalid file. Please retry with a "\
		"valid \".cor\" file.\n.");
	} else
		my_strerr("Error : Overlap : problem encountered during"\
		" the memory writing.\n");
	free(arena);
	while (proc_list->next != NULL) {
		proc_list->name ? free(proc_list->name) : 0;
		proc_list->reg ? free(proc_list->reg) : 0;
		proc_list = proc_list->next;
	}
	free(proc_list);
	champ->buffer ? free(champ->buffer) : 0;
	champ->intervals ? free(champ->intervals) : 0;
	free(champ);
	exit(84);
}

/*
** EPITECH PROJECT, 2018
** mem_writing.h
** File description:
** memory writing prototypes
*/

#ifndef MEM_WRITING_H_
#define MEM_WRITING_H_

#include "../op/op.h"
#include "vm.h"
#include "arena.h"
#include "lexer.h"

#define BUFF_SIZE 4096

typedef struct champion_s {
	unsigned int nb_bytes;
	unsigned char *buffer;
	unsigned int *intervals;
	unsigned int malloc_size;
} champion_t;

typedef union swap_s {
	int val;
	char tab[sizeof(int)];
} swap_t;

void write_bytecode_in_mem(unsigned char *, process_t *, header_t *);
void my_strerr(char *);
unsigned char *my_binary_strdup(unsigned char *, int);
unsigned char *my_binary_strcat(unsigned char *, unsigned char*, int, int);
void free_and_quit(char *, process_t *, champion_t *, int);

#endif /* !MEM_WRITING_H_ */

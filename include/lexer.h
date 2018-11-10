/*
** EPITECH PROJECT, 2018
** lexer.h
** File description:
** lexer of the asm
*/

#ifndef LEXER_H_
#define LEXER_H_
#include "../op/op.h"

typedef enum s_lexer {
	INSTRUCTION,
	LABEL,
	REGISTER,
	DIRECT,
	INDIRECT,
	LABEL_PARAM,
	CHAR_EOF,
} lexer_t;

typedef struct s_param {
	char c;
	lexer_t type;
	char *str;
} param_t;

typedef union s_special {
	int a;
	char live[4];
	char index[IND_SIZE];
} special_t;

typedef union s_help {
	int val;
	char tab[sizeof(int)];
} help_t;

typedef union s_bytes {
	int a;
	char reg_size;
	char dir_size[DIR_SIZE];
	char ind_size[IND_SIZE];
} bytes_t;

typedef struct s_infos {
	char *name;
	char c;
} infos_t;

typedef struct s_token {
	char *str;
	lexer_t type;
} token_t;

typedef struct s_label {
	char *name;
	int pos;
} label_t;

extern param_t par_tab[];

extern param_t byte_tab[];

extern label_t spe_tab[];

#endif

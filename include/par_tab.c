/*
** EPITECH PROJECT, 2018
** par_tab
** File description:
** tab of params for the .h file
*/

#include "lexer.h"
#include "asm.h"

param_t par_tab[] = {
	{'r', REGISTER, NULL},
	{DIRECT_CHAR, DIRECT, NULL},
	{-1, -1, NULL}
};

param_t byte_tab[] = {
	{1, REGISTER, "01"},
	{2, DIRECT, "10"},
	{3, INDIRECT, "11"}
};

label_t spe_tab[] = {
	{"sti", IND_SIZE},
	{"ldi", IND_SIZE},
	{"zjmp", IND_SIZE},
	{"fork", IND_SIZE},
	{"lfork", IND_SIZE},
	{"lldi", IND_SIZE},
	{NULL, 0}
};
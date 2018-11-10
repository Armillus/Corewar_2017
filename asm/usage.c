/*
** EPITECH PROJECT, 2018
** usage.c
** File description:
** print the usage of the asm
*/

#include "../include/asm.h"

int print_usage(void)
{
	my_putstr("USAGE\n\t\t./asm file_name[.s]\n\n"\
	"DESCRIPTION\n\t\tfile_name\t"\
	"file in assembly language to be converted "\
	"into file_name.cor, an\n\t\t\t\texecutable"\
	" in the Virtual Machine.\n");
	return (0);
}

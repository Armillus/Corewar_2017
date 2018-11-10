/*
** EPITECH PROJECT, 2018
** vm
** File description:
** st.c
*/

#include "../include/arena.h"

void st_c(process_t *pro, unsigned char *arena)
{
	if (pro->args.type[0] == 2) {
		if (pro->args.type[1] == 2) {
			pro->reg[pro->args.arg[1]] =
			pro->reg[pro->args.arg[0]];
		} else if (pro->args.type[1] == 1) {
			arena[pro->PC + pro->args.arg[1] % IDX_MOD] =
			pro->reg[pro->args.arg[0]];
		}
	}
}

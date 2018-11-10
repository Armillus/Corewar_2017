/*
** EPITECH PROJECT, 2018
** free_allocs
** File description:
** allow to free different types of variables
*/

#include "../include/asm.h"

void free_my_tab(char **tab)
{
	for (int i = 0; tab[i]; i++) {
		free(tab[i]);
	}
	free(tab);
}

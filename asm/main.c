/*
** EPITECH PROJECT, 2018
** main
** File description:
** main function
*/

#include "../include/asm.h"

int main(int ac, char **av)
{
	if (ac == 2 && !my_strcmp(av[1], "-h"))
		return (print_usage());
	else if (!check_my_arg(ac, av) || !my_asm(av[1]))
		return (84);
	return (0);
}

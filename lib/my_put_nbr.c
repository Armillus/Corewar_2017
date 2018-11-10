/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** display a number
*/
#include "../include/my.h"
#include <unistd.h>

void my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
		my_put_nbr(nb / 10);
	my_putchar(nb % 10 + 48);
}

void my_putchar(int c)
{
	write(1, &c, 1);
}

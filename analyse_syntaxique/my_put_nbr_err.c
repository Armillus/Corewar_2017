/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** put_nbr, put_nnbr, put_xnbr, put_ptr
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"

int my_put_nbr_err(long long int nb)
{
	long long int fact = 1;
	char c = 0;

	if (nb < 0) {
		c = '-';
		write(2, &c, 1);
		nb *= -1;
	}
	while ((nb / fact) >= 10)
		fact *= 10;
	while (fact > 0) {
		c = (nb / fact) + '0';
		write(2, &c, 1);
		nb -= nb - nb % fact;
		fact /= 10;
	}
	return (0);
}

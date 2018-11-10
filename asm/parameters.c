/*
** EPITECH PROJECT, 2018
** parameters
** File description:
** complementary functions to write parameters
*/

#include "../include/asm.h"

int write_array(char *str, int size, int fd)
{
	char c = 0;

	for (int i = size - 1; i >= 0; i--) {
		c = str[i];
		if (write(fd, &c, 1) == -1)
			my_writing_err(".cor");
	}
	return (size);
}

int write_basic_parameter(token_t token, int fd, int count)
{
	bytes_t byte;

	my_memset(byte.dir_size, DIR_SIZE, 0);
	my_memset(byte.ind_size, IND_SIZE, 0);
	byte.a = my_atoi(token.str);
	if (token.type == REGISTER) {
		if (write(fd, &byte.reg_size, 1) == -1)
			my_writing_err(".cor");
		count++;
	}
	else if (token.type == DIRECT)
		count += write_array(byte.dir_size, DIR_SIZE, fd);
	else
		count += write_array(byte.ind_size, IND_SIZE, fd);
	return (count);
}

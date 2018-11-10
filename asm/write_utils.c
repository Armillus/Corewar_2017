/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** Functions which write in the .cor file
*/

#include "../include/asm.h"

int write_and_quit(char *str, int fd)
{
	unsigned char c = 0;

	c = my_convert_bin(str);
	write(fd, &c, 1);
	free(str);
	return (1);
}

int write_decal(bytes_t *s, token_t *t, int i, int fd)
{
	token_t last = my_last_inst(t, i);

	for (int j = 0; spe_tab[j].name; j++) {
		if (my_strcmp(last.str, spe_tab[j].name) == 0 &&
		special_operator(t, last, i) == 0) {
			write_array(s->ind_size, spe_tab[j].pos, fd);
			return (spe_tab[j].pos);
		}
	}
	if (t[i].str[0] == DIRECT_CHAR || t[i].str[1] == DIRECT_CHAR) {
		write_array(s->dir_size, DIR_SIZE, fd);
		return (DIR_SIZE);
	}
	write_array(s->ind_size, IND_SIZE, fd);
	return (IND_SIZE);
}

int write_live(token_t token, int fd)
{
	special_t s;

	my_memset(s.index, IND_SIZE, 0);
	my_memset(s.live, 4, 0);
	s.a = my_atoi(token.str);
	write_array(s.live, 4, fd);
	return (4);
}

int write_special_op(token_t *t, int i, int fd)
{
	special_t s;
	int count = 0;

	my_memset(s.index, IND_SIZE, 0);
	my_memset(s.live, 4, 0);
	s.a = my_atoi(t[i].str);
	count += write_array(s.index, IND_SIZE, fd);
	return (count);
}

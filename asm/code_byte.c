/*
** EPITECH PROJECT, 2018
** code_byte
** File description:
** find and write the byte code
*/

#include "../include/asm.h"

unsigned char my_convert_bin(char *byte)
{
	unsigned char decimal_res = 0;
	int i = 0;

	while (byte[i]) {
		decimal_res = decimal_res * 2 + (byte[i] - 48);
		i++;
	}
	return (decimal_res);
}

char *fill_my_byte(char *byte, int pos, token_t t)
{
	for (int j = 0; j < 3; j++) {
		if (byte_tab[j].type == t.type) {
			byte[pos] = byte_tab[j].str[0];
			byte[pos + 1] = byte_tab[j].str[1];
		}
	}
	if (t.type == LABEL_PARAM) {
		if (t.str[0] == DIRECT_CHAR || t.str[1] == DIRECT_CHAR) {
			byte[pos] = byte_tab[1].str[0];
			byte[pos + 1] = byte_tab[1].str[1];
		} else {
			byte[pos] = byte_tab[2].str[0];
			byte[pos + 1] = byte_tab[2].str[1];
		}
	}
	return (byte);
}

char *write_and_replace(char *byte, int fd)
{
	unsigned char c = my_convert_bin(byte);

	if (write(fd, &c, 1) == -1)
		my_writing_err(".cor");
	for (int i = 0; byte[i]; i++)
		byte[i] = '0';
	return (byte);
}

char *init_my_byte(int n)
{
	char *byte = malloc(sizeof(char) * (n + 1));

	if (!byte)
		return (NULL);
	my_memset(byte, n, '0');
	byte[n] = '\0';
	return (byte);
}

int write_code_byte(token_t *t, int i, int fd)
{
	char *byte = init_my_byte(8);
	int pos = 0;

	if (bad_instruction(t[i]) == 1) {
		free(byte);
		return (0);
	}
	for (i += 1; byte && t[i].type != CHAR_EOF; i++, pos += 2) {
		if (pos != 0 && pos % 8 == 0) {
			byte = write_and_replace(byte, fd);
			pos = 0;
		}
		byte = fill_my_byte(byte, pos, t[i]);
		if (t[i].type == LABEL || t[i].type == INSTRUCTION ||
		t[i + 1].type == CHAR_EOF) {
			return (write_and_quit(byte, fd));
		}
	}
	return (0);
}

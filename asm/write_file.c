/*
** EPITECH PROJECT, 2018
** write_file
** File description:
** write in a .cor file
*/

#include "../include/asm.h"

int write_instruction(char *str, int fd)
{
	for (int i = 0; op_tab[i].code != 0; i++) {
		if (my_strcmp(op_tab[i].mnemonique, str) == 0) {
			write(fd, &(op_tab[i].code), 1);
			return (1);
		}
	}
	return (0);
}

int write_parameter(token_t *t, int i, int fd, int count)
{
	token_t last = my_last_inst(t, i);

	if (is_empty(t[i].str) == 0)
		return (count);
	if (my_strcmp(last.str, "live") == 0)
		count += write_live(t[i], fd);
	else if (special_operator(t, last, i) == 0 && t[i].type != REGISTER)
		count += write_special_op(t, i, fd);
	else
		count = write_basic_parameter(t[i], fd, count);
	return (count);
}

int write_label(token_t *t, int fd, int i, asm_t *a)
{
	int b = 0;
	bytes_t s;
	char *tmp = NULL;

	if (t[i].type == LABEL)
		return (0);
	my_memset(s.ind_size, IND_SIZE, 0);
	my_memset(s.dir_size, DIR_SIZE, 0);
	b = find_characters(t[i].str);
	t[i].str = analyze_my_token_str(t[i].str);
	for (int j = 0; a->lab[j].pos != -2; j++) {
		tmp = my_str_ncut(my_strdup(t[i].str), b);
		if (my_strcmp(a->lab[j].name, tmp) == 0) {
			s.a = a->lab[j].pos - a->instr_counter;
			free(tmp);
			return (write_decal(&s, t, i, fd));
		}
		free(tmp);
	}
	return (0);
}

void write_header(header_t *h, int fd, char *path)
{
	h->magic = my_swap(COREWAR_EXEC_MAGIC);
	h->prog_size = my_swap(h->prog_size);
	if ((write(fd, h, sizeof(header_t))) == -1)
		my_writing_err(path);
}

int write_in_file(token_t *lex, asm_t *a)
{
	char *path = obtain_my_filename(a->file_name);
	int fd = open(path, O_CREAT | O_WRONLY, 0644);

	if (!path || fd == -1)
		return (0);
	write_header(a->h, fd, path);
	if (!lex)
		return (close_and_free(fd, a, lex, path));
	for (int i = 0; lex[i].type != CHAR_EOF; i++) {
		if (lex[i].type == INSTRUCTION) {
			a->instr_counter = a->byte_counter;
			a->byte_counter += write_instruction(lex[i].str, fd);
			a->byte_counter += write_code_byte(lex, i, fd);
		} else if (lex[i].type == LABEL || lex[i].type == LABEL_PARAM)
			a->byte_counter += write_label(lex, fd, i, a);
		else
			a->byte_counter =
			write_parameter(lex, i, fd, a->byte_counter);
	}
	return (close_and_free(fd, a, lex, path));
}

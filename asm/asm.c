/*
** EPITECH PROJECT, 2018
** asm.c
** File description:
** main function
*/

#include "../include/asm.h"

void fill_my_header(asm_t *a)
{
	int name = a->header_value.name;
	int com = a->header_value.com;

	if (!(a = find_champion_name(a)) || a->header_value.name > name)
		return (a);
	if (!(a = find_champion_comment(a)) || a->header_value.com > com)
		return (a);
	return (a);
}

void analyze_my_line(asm_t *a)
{
	int name = a->header_value.name;
	int com = a->header_value.com;

	a = cut_comment(a);
	if (!is_empty(a->s))
		return (a);
	a->s = my_clean_str(a->s);
	a = fill_my_header(a);
	if (!a || name < a->header_value.name || com < a->header_value.com)
		return (a);
	a->s = my_strcat(a->s, " ");
	a->buf = my_strcat(a->buf, a->s);
	return (a);
}

asm_t *get_my_champion(asm_t *assm, int fd)
{
	while (assm->s) {
		if (assm->s[0] != COMMENT_CHAR && is_empty(assm->s))
			analyze_my_line(assm);
		if (!assm || assm->header_value.com > 1 ||
		assm->header_value.name > 1)
			return (NULL);
		free(assm->s);
		assm->s = get_next_line(fd);
	}
	close(fd);
	if (!assm->buf && assm->header_value.name == 0) {
		print_my_error(" : The champion has not nay name.\n");
		exit(0);
	}
	if (is_empty(assm->buf) == 0) {
		print_my_warning(" : The champion is empty.\n");
		free(assm->buf);
	}
	return (assm);
}

int my_asm(char *str)
{
	int fd = open(str, O_RDONLY);
	asm_t *assm = init_my_struct(str);

	if (!assm || fd == -1 || !(assm->s = get_next_line(fd))) {
		if (!assm)
			print_my_error(" : Malloc exception.\n");
		else if (fd == -1)
			print_my_error(" : File given as parameter"\
			" is invalid.\n");
		else
			print_my_error("The file is empty.\n");
		return (0);
	}
	if (!(assm = get_my_champion(assm, fd)) || assm->header_value.name == 0)
		return (0);
	if (!create_my_cor_file(assm))
		return (0);
	return (1);
}

int check_my_arg(int ac, char **av)
{
	int len = 0;

	if (ac != 2) {
		print_my_error("Invalid number of arguments."\
		" Retry with \"-h\" to see usage.\n");
		return (0);
	}
	len = my_strlen(av[1]);
	if (av[1][len - 2] != '.' && av[1][len - 1] != 's') {
		print_my_error("Please launch with a \".s\" file.\n");
		return (0);
	}
	return (1);
}

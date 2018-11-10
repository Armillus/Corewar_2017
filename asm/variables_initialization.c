/*
** EPITECH PROJECT, 2018
** ASM
** File description:
** Init the main structure of the asm
*/

#include "../include/asm.h"

asm_t *init_my_struct_var(asm_t *assm, char *filename)
{
	assm->cmd_len = my_strlen(NAME_CMD_STRING);
	assm->cmt_len = my_strlen(COMMENT_CMD_STRING);
	assm->h->magic = COREWAR_EXEC_MAGIC;
	assm->h->prog_size = 0;
	assm->byte_counter = 0;
	assm->instr_counter = 0;
	assm->header_value.com = 0;
	assm->header_value.name = 0;
	assm->buf = NULL;
	assm->s = NULL;
	assm->file_name = filename;
	assm->lab = NULL;
	return (assm);
}

asm_t *init_my_struct(char *filename)
{
	asm_t *assm = NULL;

	if ((assm = malloc(sizeof(asm_t))) == NULL)
		return (NULL);
	if ((assm->h = malloc(sizeof(header_t))) == NULL)
		return (NULL);
	my_memset(assm->h, sizeof(header_t), 0);
	my_memset(assm->h->prog_name, PROG_NAME_LENGTH, 0);
	my_memset(assm->h->comment, COMMENT_LENGTH, 0);
	assm = init_my_struct_var(assm, filename);
	return (assm);
}
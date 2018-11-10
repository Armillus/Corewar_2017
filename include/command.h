/*
** EPITECH PROJECT, 2018
** vm
** File description:
** command.h
*/

#ifndef _COMMAND_H_
#define _COMMAND_H_

void live_c(process_t *, unsigned char *);
void ld_c(process_t *, unsigned char *);
void st_c(process_t *, unsigned char *);
void add_c(process_t *, unsigned char *);
void sub_c(process_t *, unsigned char *);
void and_c(process_t *, unsigned char *);
void or_c(process_t *, unsigned char *);
void xor_c(process_t *, unsigned char *);
void zjmp_c(process_t *, unsigned char *);
void ldi_c(process_t *, unsigned char *);
void sti_c(process_t *, unsigned char *);
void fork_c(process_t *, unsigned char *);
void lld_c(process_t *, unsigned char *);
void lldi_c(process_t *, unsigned char *);
void lfork_c(process_t *, unsigned char *);
void aff_c(process_t *, unsigned char *);

#endif

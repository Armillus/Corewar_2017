/*
** EPITECH PROJECT, 2018
** asm
** File description:
** analyse_syntax.h
*/

#include <stdlib.h>
#include <unistd.h>
#include "../op/op.h"
#include "lexer.h"

#ifndef ANALYSE_SYNTAX_H_
#define ANALYSE_SYNTAX_H_

int my_put_nbr_err(long long int);
void my_puterr(char *, token_t *, int);
char *my_strdup(char *);
void check_char_of_label(char, token_t *, int);
void instruction_analyse(token_t *, int);
void label_analyse(token_t *, int);
void register_analyse(token_t *, int);
void direct_analyse(token_t *, int);
void indirect_analyse(token_t *, int);
void labelparam_analyse(token_t *, int);

#endif

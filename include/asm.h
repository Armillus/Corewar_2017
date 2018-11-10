/*
** EPITECH PROJECT, 2018
** asm.h
** File description:
** list of functions prototypes
*/

#ifndef _ASM_H_
#define _ASM_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../op/op.h"
#include "lexer.h"

#define GREEN "\033[0;32m"
#define RED "\033[1;31m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;34m"
#define RESET "\033[0m"

typedef struct s_nbr {
	int com;
	int name;
} nbr_t;

typedef struct s_asm {
	char *s;
	char *buf;
	header_t *h;
	int cmd_len;
	int cmt_len;
	char *file_name;
	label_t *lab;
	int byte_counter;
	int instr_counter;
	nbr_t header_value;
} asm_t;

int my_strlen(char *str);
char *get_next_line(int fd);
void my_putstr(char *str);
int print_usage(void);
int check_my_arg(int ac, char **av);
int my_strcmp(char *str, char *str2);
char *my_str_ncut(char *str, int n);
char *my_strcat(char *, char *);
int create_my_cor_file(asm_t *a);
char *my_clean_str(char *str);
char *my_strncpy(char *str, int p);
char *my_strdup(char *src);
void *my_memset(void *s, int size, int c);
int my_asm(char *str);
asm_t *init_my_struct(char *str);
asm_t *analyze_my_line(asm_t *a);
char *cpy_informations(int size, char *dest, const char *src);
int check_instruction(token_t token);
int special_operator(token_t *t, token_t last, int i);
int find_characters(const char *str);
int write_decal(bytes_t *s, token_t *t, int i, int fd);
int my_swap(int n);
char *obtain_my_filename(char *name);
int bad_instruction(token_t l);
token_t my_last_inst(token_t *t, int i);
int write_live(token_t token, int fd);
int write_special_op(token_t *t, int i, int fd);
int write_array(char *str, int size, int fd);
int write_basic_parameter(token_t token, int fd, int count);
unsigned char my_convert_bin(char *str);
char *fill_my_byte(char *str, int k, token_t l);
char *write_and_replace(char *str, int fd);
char *init_my_byte(int n);
int write_code_byte(token_t *l, int i, int fd);
int label_bytes(token_t *l, int j, int count);
int parameter_bytes(token_t *t, int j, int count);
int count_bytes(token_t *lexer, int j, int count);
asm_t *find_my_labels(token_t *lexer, asm_t *a);
int write_instruction(char *str, int fd);
int write_parameter(token_t *t, int i, int fd, int count);
int write_label(token_t *t, int fd, int i, asm_t *a);
void write_header(header_t *h, int fd, char *path);
int write_in_file(token_t *lexer, asm_t *a);
lexer_t find_my_type(char *str);
char *my_str_char_cat(char *str, char c);
void free_asm(asm_t *a, token_t *lexer);
int is_empty(char *str);
void syntax_analysis(token_t *token);
char *my_str_cpy(char *dest, char *str);
int analyze_labels(asm_t *a);
int my_str_isnum(char *);
void my_writing_err(char *path);
asm_t *cut_comment(asm_t *a);
asm_t *find_champion_name(asm_t *a);
asm_t *find_champion_comment(asm_t *a);
int write_and_quit(char *str, int fd);
int check_length(char *str, int size, int good_len);
int my_put_nbr_err(long long int nb);
int close_and_free(int fd, asm_t *a, token_t *lexer, char *src);
int my_atoi(const char *str);
char *add_separators_chars(char *str);
char *analyze_my_token_str(char *str);
void print_my_error(char *error);
void print_my_warning(char *warning);

#endif /* !_ASM_H_ */

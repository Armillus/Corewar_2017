/*
** EPITECH PROJECT, 2018
** asm
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

int my_strlen(char *);
int my_putstr(char *);
int my_isdigit(char *, int);
int my_strcmp(char *, char *);
int my_strncmp(char *, char *, int);
int my_getnbr(char *);
int my_str_isnum(char *);
char *my_str_ncut(char *, int);
void my_put_nbr(int);
void my_putchar(int);
void *my_memset(void *, int, int);

#endif
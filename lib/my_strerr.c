/*
** EPITECH PROJECT, 2018
** my_strerr
** File description:
** Basic function to write on the error output
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/asm.h"

void my_strerr(char *str)
{
	write(2, str, my_strlen(str));
}

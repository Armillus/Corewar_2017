/*
** EPITECH PROJECT, 2018
** Virtual MAchine
** File description:
** Binary functions relative to the vm
*/

#include "../include/asm.h"

unsigned char *my_binary_strdup(unsigned char *src, unsigned int size)
{
	unsigned char *dest = NULL;

	if (!src)
		return (NULL);
	dest = malloc(sizeof(unsigned char) * size);
	if (!dest)
		return (NULL);
	for (unsigned int i = 0; i < size; i++)
		dest[i] = src[i];
	return (dest);
}

unsigned char *my_binary_strcat(unsigned char *src1,
unsigned char *src2, unsigned int src1_size, unsigned int src2_size)
{
	unsigned char *dest = NULL;
	unsigned int j = 0;

	if (!src1)
		return (my_binary_strdup(src2, src2_size));
	dest = malloc(sizeof(unsigned char) * (src1_size + src2_size));
	if (!dest)
		return (NULL);
	for (int i = 0; i < src1_size; i++, j++)
		dest[j] = src1[i];
	for (int i = 0; i < src2_size; i++, j++)
		dest[j] = src2[i];
	free(src1);
	return (dest);
}

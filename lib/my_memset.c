/*
** EPITECH PROJECT, 2018
** my_memset
** File description:
** basic function
*/

void *my_memset(void *s, int size, int c)
{
	int i = 0;

	for (i = 0; i < size; i++)
		((char*)s)[i] = c;
	return (s);
}

/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** basic function
*/

int my_str_isnum(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++) {
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
			return (1);
	}
	return (0);
}

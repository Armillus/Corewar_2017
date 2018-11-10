/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** basic function
*/

int my_atoi(const char *str)
{
	int b = 0;
	int count = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] >= '0' && str[i] <= '9')
			b = b * 10 + (str[i] - 48);
		else if (str[i] == '-')
			count++;
	}
	if (count > 0)
		b = b * (-1);
	return (b);
}

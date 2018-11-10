/*
** EPITECH PROJECT, 2017
** unit_test_corewar.c
** File description:
** unti tests for the corewar
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/vm.h"
#include "../include/my.h"
#include "../include/arena.h"

void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(corewar_tests, basics, .init = redirect_all_std)
{
	int res = my_getnbr("2");
	int res2 = my_strcmp("test1", "test2");
	int res3 = my_strcmp("match!", "match!");
	char *res4 = my_strdup("test");
	char *res5 = malloc(sizeof(char) * 3);

	res5[0] = 't';
	res5[1] = 'e';
	res5[2] = 0;
	res5 = my_strncpy(res5, 1);
	cr_assert_eq(res, 2);
	my_put_nbr(res);
	my_putchar('2');
	cr_assert_stdout_eq_str("22");
	cr_assert_neq(res2, 0);
	cr_assert_eq(res3, 0);
	cr_assert_str_eq(res4, "test");
	cr_assert_str_eq(res5, "t");
}
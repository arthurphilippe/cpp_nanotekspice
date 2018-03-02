/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** test-error
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Error.hpp"

static void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(Basic, RuntimeError, .init = redirect_all_std) {
	RuntimeError test("something, something");

	cr_assert_str_eq(test.what(), "something, something");
}

Test(Basic, FileError, .init = redirect_all_std) {
	FileError test("something, something");

	cr_assert_str_eq(test.what(), "something, something");
}

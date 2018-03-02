//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// Test-Args
//

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Parser.hpp"
#include "Error.hpp"

int parserTester(int ac, char **av);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"

static void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

/*
**	Test a configuration file without output
*/
Test(NoOuputLink, Arguments, .init = redirect_all_std)
{
	bool thrown = false;
	char *str[] = {"./nanotekspice", "tests/nts_files/nooutputlink.nts",
			"reset=1", "clock=1",
			NULL};
	try {
		parserTester(4, str);
	} catch (const FileError &error) {
		error.what();
		thrown = true;
	}
	cr_assert(thrown);
}

/*
**	Test a real configuration file with impossible value in arguments
*/
Test(RealFileWithImpossibleValue, Arguments, .init = redirect_all_std)
{
	bool thrown = false;
	char *str[] = {"./nanotekspice", "tests/counter.nts",
		       "reset=allah", "clock=poulet",
			NULL};
	try {
		parserTester(4, str);
	} catch (const FileError &error) {
		error.what();
		thrown = true;
	}
	cr_assert(thrown);
}

/*
**	Test to launch nanotekspice with a configuration file but no with
**	the intput's value
*/
Test(NoArgs, Arguments, .init = redirect_all_std)
{
	bool thrown = false;
	char *str[] = {"./nanotekspice", "tests/counter.nts",
			"",
			NULL};
	try {
		parserTester(2, str);
	} catch (const FileError &error) {
		error.what();
		thrown = true;
	}
	cr_assert(thrown);
}

/*
**	Test a false file
*/
Test(FalseNameWithValue, Arguments, .init = redirect_all_std) {
	bool thrown = false;
	char *str[] = {"./nanotekspice", "tests/counter.nts",
			"potato=0",
			NULL};
	try {
		parserTester(3, str);
	} catch (const FileError &error) {
		error.what();
		thrown = true;
	}
	cr_assert(thrown);
}

/*
**	Test to launch nanotekspice without arguments at all
*/
Test(NoArgumentAtAll, Arguments, .init = redirect_all_std)
{
	bool thrown = false;
	char *str[2] = {"./nanotekspice",
			NULL};
	try {
		parserTester(1, str);
	} catch (const FileError &error) {
		error.what();
		thrown = true;
	}
	cr_assert(thrown);
}

/*
**	Test an error in input argument value
*/
Test(RealNameWithEgal, Arguments, .init = redirect_all_std)
{
	bool thrown = false;
	char *str[] = {"./nanotekspice", "tests/counter.nts",
			"reset=",
			NULL};
	try {
		parserTester(3, str);
	} catch (const FileError &error) {
		error.what();
		thrown = true;
	}
	cr_assert(thrown);
}

/*
**	Test an no existant input in argument
*/
Test(FalseName, Arguments, .init = redirect_all_std)
{
	bool thrown = false;
	char *str[] = {"./nanotekspice", "tests/counter.nts",
			"motismadex",
			NULL};
	try {
		parserTester(3, str);
	} catch (const FileError &error) {
		error.what();
		thrown = true;
	}
	cr_assert(thrown);
}

/*
**	Functionnal Test
*/
Test(RealFile, Arguments, .init = redirect_all_std) {
	bool thrown = false;
	char *str[] = {"./nanotekspice", "tests/nts_files/counter.nts",
			"reset=1", "clock=0",
			NULL
	};
	try {
		parserTester(4, str);
	} catch (const FileError &error) {
		error.what();
		thrown = true;
	}
	cr_assert(!thrown);
}

/*
**	Test a non existant configuration file
*/
Test(FalseFile, Arguments, .init = redirect_all_std) {
	bool thrown = false;
	char *str[] = {"./nanotekspice", "u_u", "o1=1", NULL};
	try {
		parserTester(3, str);
	} catch (const FileError &error) {
		error.what();
		thrown = true;
	}
	cr_assert(thrown);
}

#pragma GCC diagnostic pop

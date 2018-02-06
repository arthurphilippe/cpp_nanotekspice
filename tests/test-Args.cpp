//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// Test-Args
//

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Readfile.hpp"
#include "Error.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"

static void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(RealFileWithImpossibleValue, Arguments, .init = redirect_all_std) {
	bool thrown = false;
	char *str[4] = {"kappa", "tests/counter.nts",
			"reset=allah",
			NULL
	};
	try
	{
		parserTester(3, str);
	}
	catch (const FileError &error)
	{
		error.what();
		thrown = true;
	}
	cr_assert(thrown);
}


Test(NoArgs, Arguments, .init = redirect_all_std) {
	bool thrown = false;
	char *str[4] = {"kappa", "tests/counter.nts",
			"",
			NULL
	};
	try
	{
		parserTester(2, str);
	}
	catch (const FileError &error)
	{
		error.what();
		thrown = true;
	}
	cr_assert(thrown);
}


Test(FalseNameWithValue, Arguments, .init = redirect_all_std) {
	bool thrown = false;
	char *str[4] = {"kappa", "tests/counter.nts",
			"prout=0",
			NULL
	};
	try
	{
		parserTester(3, str);
	}
	catch (const FileError &error)
	{
		error.what();
		thrown = true;
	}
	cr_assert(thrown);
}


Test(NoArgumentAtAll, Arguments, .init = redirect_all_std) {
	bool thrown = false;
	char *str[2] = {"kappa",
			NULL
	};
	try
	{
		parserTester(1, str);
	}
	catch (const FileError &error)
	{
		error.what();
		thrown = true;
	}
	cr_assert(thrown);
}


Test(RealNameWithEgal, Arguments, .init = redirect_all_std) {
	bool thrown = false;
	char *str[4] = {"kappa", "tests/counter.nts",
			"reset=",
			NULL
	};
	try
	{
		parserTester(3, str);
	}
	catch (const FileError &error)
	{
		error.what();
		thrown = true;
	}
	cr_assert(thrown);
}


Test(FalseName, Arguments, .init = redirect_all_std) {
	bool thrown = false;
	char *str[4] = {"kappa", "tests/counter.nts",
			"prout",
			NULL
	};
	try
	{
		parserTester(3, str);
	}
	catch (const FileError &error)
	{
		error.what();
		thrown = true;
	}
	cr_assert(thrown);
}


Test(RealFile, Arguments, .init = redirect_all_std) {
	bool thrown = false;
	char *str[4] = {"kappa", "tests/nts_files/counter.nts",
			"reset=1",
			NULL
	};
	try
	{
		parserTester(3, str);
	}
	catch (const FileError &error)
	{
		error.what();
		thrown = true;
	}
	cr_assert(!thrown);
}

Test(FalseFile, Arguments, .init = redirect_all_std) {
	bool thrown = false;
	char *str[3] = {"kappa", "u_u", "o1=1"};
	try
	{
		parserTester(3, str);
	}
	catch (const FileError &error)
	{
		error.what();
		thrown = true;
	}
	cr_assert(thrown);
}

#pragma GCC diagnostic pop


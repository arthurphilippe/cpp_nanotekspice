//
// EPITECH PROJECT, 2018
// nanotekspice test
// File description:
// Parser Tester
//

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <criterion/redirect.h>
#include "Error.hpp"
#include "Readfile.hpp"

int parserTester(int ac, char **av);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"

static void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(NoDefOfchipsets, Parser, .init = redirect_all_std) {
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/nochipsetdef.nts", "a=1", NULL};
	try {
		nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
}

Test(ChipError, Parser, .init = redirect_all_std) {
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/chiperror.nts", "a=1", NULL};
	try {
		nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
}

Test(ChipError2, Parser, .init = redirect_all_std) {
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/chipseterror2.nts", "a=1", NULL};
	try {
		nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
}


Test(NoDefOfchipsetsbutchipPresent, Parser, .init = redirect_all_std) {
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/nodefchip.nts", "a=1", NULL};
	try {
		nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
}


Test(NoLink, Parser, .init = redirect_all_std) {
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/nolink.nts", "a=1", NULL};
	try {
		nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
}

Test(ErrorLink, Parser, .init = redirect_all_std) {
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/errorlink.nts", "a=1", NULL};
	try {
		nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
}

Test(ErrorLink2, Parser, .init = redirect_all_std) {
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/errorlink2.nts", "a=1", NULL};
	try {
		nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
}

Test(EmptyFile, Parser, .init = redirect_all_std) {
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/empty.nts", "a=1", NULL};
	try {
	nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
}

Test(NoDefOflinks, Parser, .init = redirect_all_std) {
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/nolinksdef.nts", "a=1", NULL};
	try {
	nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
}



#pragma GCC diagnostic pop

//
// EPITECH PROJECT, 2018
// nanotekspice test
// File description:
// Parser Tester
//

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "Error.hpp"
#include "Readfile.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"

Test(NoDefOfchipsets, Parser) {
	std::cout << "\033[1;31m:: Testing 'No Chipset'\033[0m" << std::endl;
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/nochipsetdef.nts", "a=1", NULL};
	try {
		nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
	std::cout << "\033[1;31m--> finished test 'No Chipset'\n\033[0m" << std::endl;
}

Test(ChipError, Parser) {
	std::cout << "\033[1;31m:: Testing 'Chipset Error'\033[0m" << std::endl;
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/chiperror.nts", "a=1", NULL};
	try {
		nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
	std::cout << "\033[1;31m--> finished test 'Chipset Error'\n\033[0m" << std::endl;
}

Test(ChipError2, Parser) {
	std::cout << "\033[1;31m:: Testing 'Chipset Error 2'\033[0m" << std::endl;
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/chipseterror2.nts", "a=1", NULL};
	try {
		nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
	std::cout << "\033[1;31m--> finished test 'Chipset Error 2'\n\033[0m" << std::endl;
}


Test(NoDefOfchipsetsbutchipPresent, Parser) {
	std::cout << "\033[1;31m:: Testing 'No Definition Chipset'\033[0m" << std::endl;
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/nodefchip.nts", "a=1", NULL};
	try {
		nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
	std::cout << "\033[1;31m--> finished test 'No Definition Chipset'\n\033[0m" << std::endl;
}


Test(NoLink, Parser) {
	std::cout << "\033[1;31m:: Testing 'No Definition link'\033[0m" << std::endl;
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/nolink.nts", "a=1", NULL};
	try {
		nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
	std::cout << "\033[1;31m--> finished test 'No Definition link'\n\033[0m" << std::endl;
}

Test(ErrorLink, Parser) {
	std::cout << "\033[1;31m:: Testing 'Error Link'\033[0m" << std::endl;
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/errorlink.nts", "a=1", NULL};
	try {
		nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
	std::cout << "\033[1;31m--> finished test 'Error Link'\n\033[0m" << std::endl;
}

Test(ErrorLink2, Parser) {
	std::cout << "\033[1;31m:: Testing 'Error Link Number 2'\033[0m" << std::endl;
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/errorlink2.nts", "a=1", NULL};
	try {
		nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
	std::cout << "\033[1;31m--> finished test 'Error Link Number 2'\n\033[0m" << std::endl;
}

/*
Test(sampleTest, Parser) {
	std::cout << "\033[1;31m:: Testing 'ALLAHU'\033[0m" << std::endl;
	std::cout << "\033[1;31m--> finished test 'ALLAHU'\n\033[0m" << std::endl;
}
*/

Test(EmptyFile, Parser) {
	std::cout << "\033[1;31m:: Testing 'Empty Configuration File'\033[0m" << std::endl;
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/empty.nts", "a=1", NULL};
	try {
	nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
	std::cout << "\033[1;31m--> finished test 'Empty Configuration File'\n\033[0m" << std::endl;
}

Test(NoDefOflinks, Parser) {
	std::cout << "\033[1;31m:: Testing 'No Definition of .links'\033[0m" << std::endl;
	bool verify = false;
	char *str[4] = {"nanotekspice", "tests/nts_files/nolinksdef.nts", "a=1", NULL};
	try {
	nts::Parser(3, str);
	} catch (const FileError &error) {
		verify = true;
		error.what();
	}
	cr_assert(verify);
	std::cout << "\033[1;31m--> finished test 'No Definition of .links'\n\033[0m" << std::endl;
}



#pragma GCC diagnostic pop

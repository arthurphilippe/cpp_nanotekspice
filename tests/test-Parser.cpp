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

Test(sampleTest, Parser) {
	std::cout << "\033[1;31m:: Testing 'ALLAHU'\033[0m" << std::endl;
	std::cout << "\033[1;31m--> finished test 'ALLAHU'\n\033[0m" << std::endl;
}

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


/*
**	TO CHANGE
*/
Test(EmptyFile2, Parser) {
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


#pragma GCC diagnostic pop

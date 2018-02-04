//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// Test-Args
//

#include <criterion/criterion.h>
#include "Readfile.hpp"
#include "Error.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"
Test(RealFile, Arguments) {
	std::cout << "-------------------TEST REAL FILE" << std::endl;
	bool thrown = false;
        char *str[4] = {"kappa", "tests/counter.nts",
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
	std::cout << "-------------------END TEST REAL FILE\n" << std::endl;
}

Test(FalseFile, Arguments) {
	std::cout << "-------------------TEST FALSE FILE" << std::endl;
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
	std::cout << "-------------------END TEST FALSE FILE\n" << std::endl;
}

#pragma GCC diagnostic pop

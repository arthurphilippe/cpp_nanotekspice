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

Test(NoArgs, Arguments) {
	std::cout << "\033[1;31m:: Testing 'No Argument'\033[0m" << std::endl;
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
	std::cout << "\033[1;31m--> finished test 'No Argument'\n\033[0m" << std::endl;
}


Test(FalseNameWithValue, Arguments) {
	std::cout << "\033[1;31m:: Testing 'False Input Name with a True Value'\033[0m" << std::endl;
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
	std::cout << "\033[1;31m--> finished test 'False Input Name with a True Value'\033[0m\n" << std::endl;
}

Test(FalseName, Arguments) {
	std::cout << "\033[1;31m:: Testing 'False Input Name without Value'\033[0m" << std::endl;
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
	std::cout << "\033[1;31m--> finished test 'False Input Name without Value'\n\033[0m" << std::endl;
}



Test(RealFile, Arguments) {
	std::cout << "\033[1;31m:: Testing 'Real File with Good Argument'\033[0m" << std::endl;
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
	std::cout << "\033[1;31m--> finished test 'Real File with Good Argument'\033[0m\n" << std::endl;
}

Test(FalseFile, Arguments) {
	std::cout << "\033[1;31m:: Testing 'False Configuration File with Good Argument'\033[0m" << std::endl;
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
		std::cout << "\033[1;31m--> finished test 'False Configuration File with Good Argument'\033[0m\n" << std::endl;
}

#pragma GCC diagnostic pop

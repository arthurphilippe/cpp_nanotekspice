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
#include "Parser.hpp"
#include "Circuit.hpp"
#include "Simulation.hpp"

int parserTester(int ac, char **av)
{
	if (ac > 1)
	{
		nts::Circuit circuit(ac, av);
		nts::Simulation(circuit.getComponents());
	}
	else
		throw FileError("print_usage");
	return 0;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"

static void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(NoDefOfchipsets, Parser, .init = redirect_all_std) {
	char *str[4] = {"nanotekspice",
			"tests/nts_files/nochipsetdef.nts", "a=1", NULL};
	cr_assert_throw(nts::Circuit circuit(3, str), FileError);
}

Test(ChipError, Parser, .init = redirect_all_std) {
	char *str[4] = {"nanotekspice", "tests/nts_files/chiperror.nts", "a=1", NULL};
	cr_assert_throw(nts::Circuit circuit(3, str), FileError);
}

Test(ChipError2, Parser, .init = redirect_all_std) {
	char *str[4] = {"nanotekspice",
			"tests/nts_files/chipseterror2.nts", "a=1", NULL};
	cr_assert_throw(nts::Circuit circuit(3, str), FileError);
}

Test(NoDefOfchipsetsbutchipPresent, Parser, .init = redirect_all_std) {
	char *str[4] = {"nanotekspice",
			"tests/nts_files/nodefchip.nts", "a=1", NULL};
	cr_assert_throw(nts::Circuit circuit(3, str), FileError);
}

Test(NoLink, Parser, .init = redirect_all_std) {
	char *str[4] = {"nanotekspice",
			"tests/nts_files/nolink.nts", "a=1", NULL};
	cr_assert_throw(nts::Circuit circuit(3, str), FileError);
}

Test(ErrorLink, Parser, .init = redirect_all_std) {
	char *str[4] = {"nanotekspice",
			"tests/nts_files/errorlink.nts", "a=1", NULL};
	cr_assert_throw(nts::Circuit circuit(3, str), FileError);
}

Test(ErrorLink2, Parser, .init = redirect_all_std) {
	char *str[4] = {"nanotekspice",
			"tests/nts_files/errorlink2.nts", "a=1", NULL};
	cr_assert_throw(nts::Circuit circuit(3, str), FileError);
}

Test(EmptyFile, Parser, .init = redirect_all_std) {
	char *str[4] = {"nanotekspice",
			"tests/nts_files/empty.nts", "a=1", NULL};
	cr_assert_throw(nts::Circuit circuit(3, str), FileError);
}

Test(NoDefOflinks, Parser, .init = redirect_all_std) {
	char *str[4] = {"nanotekspice",
			"tests/nts_files/nolinksdef.nts", "a=1", NULL};
	cr_assert_throw(nts::Circuit circuit(3, str), FileError);
}

#pragma GCC diagnostic pop
